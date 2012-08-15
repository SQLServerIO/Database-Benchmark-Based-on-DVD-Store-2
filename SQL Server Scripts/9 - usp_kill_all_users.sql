--usp_kill_all_users
-- little script I use to kill all users out of a database before
-- restores or other activities

--USE [Management]
GO


SET ANSI_NULLS ON
GO

SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE [dbo].[usp_kill_all_users] (@target_database varchar(255))
as

set nocount on

declare 
	@cmd varchar(1000)
	,@RC int
	,@retry int
	,@spid varchar(10)
	,@source_database_name varchar(255)

--table holds users to be killed
CREATE TABLE #tmpUsers
    (
		 spid INT
		, eid INT
		, status VARCHAR(30)
		, loginname VARCHAR(50)
		, hostname VARCHAR(50)
		, blk INT
		, dbname VARCHAR(50)
		, cmd VARCHAR(30)
    )

    IF (
        SELECT
            LEFT(CAST(SERVERPROPERTY('productversion') AS VARCHAR) ,
                 1)
       ) = '9' 
        BEGIN
            ALTER TABLE #tmpUsers
            ADD request_id INT
        END

    IF (
        SELECT
            LEFT(CAST(SERVERPROPERTY('productversion') AS VARCHAR) ,
                 2)
       ) = '10' 
        BEGIN
            ALTER TABLE #tmpUsers
            ADD request_id INT
        END

    IF (
        SELECT
            LEFT(CAST(SERVERPROPERTY('productversion') AS VARCHAR) ,
                 2)
       ) = '11' 
        BEGIN
            ALTER TABLE #tmpUsers
            ADD request_id INT
        END

set @retry = 1

Start:
truncate table #tmpUsers

INSERT INTO
    #tmpUsers
    EXEC sp_who

DECLARE LoginCursor CURSOR FAST_FORWARD
    FOR SELECT
            spid
          , dbname
        FROM
            #tmpUsers
        WHERE
            dbname = @target_database

OPEN LoginCursor

FETCH NEXT FROM LoginCursor INTO @spid ,@source_database_name
WHILE (@@fetch_status <> -1)
    BEGIN
        IF (@@fetch_status <> -2) 
            BEGIN
                SET @cmd = 'KILL ' + @spid
				PRINT @cmd
                EXEC (
                      @cmd
                    )
            END
        FETCH NEXT FROM LoginCursor INTO @spid ,@source_database_name
    END

CLOSE LoginCursor
DEALLOCATE LoginCursor

truncate table #tmpUsers
INSERT INTO
    #tmpUsers
    EXEC sp_who

if (SELECT count(spid) FROM #tmpUsers WHERE dbname = @target_database) = 0
begin
	set @RC = 0
end
else if @retry < 10
begin
	set @retry = @retry + 1
	WAITFOR DELAY '000:00:06'
	GOTO start
end
else
	set @RC = 1

return @RC


GO

