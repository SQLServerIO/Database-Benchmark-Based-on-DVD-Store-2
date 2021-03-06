
-- Create DB Script: Creates database and tables and triggers
-- DVD Store Database Version 2.1 Build Script - SQL Server version -
-- Copyright (C) 2007 Dell, Inc. <dave_jaffe@dell.com> and <tmuirhead@vmware.com>
-- Last updated 07/23/2010 by GSK
-- Last updated 08/03/2012 by WDB
-- Simplified structure from previous script.
-- this script has a primary file gorup used for just sysobjects and capped at 512MB
-- there are five files in the DS2_DATA file group to spread out the IO load
-- This is sized for a 100GB load with the five data files at 25GB and the log
-- at 10% of the total size so 10GB
-- This script will also enable the full text search index
-- that is needed for this benchmark

SET NOCOUNT ON
GO
USE master
GO
Management.dbo.usp_kill_all_users 'DS2'
GO
IF EXISTS ( SELECT
                    *
                FROM
                    sysdatabases
                WHERE
                    NAME = 'DS2' ) 
    DROP DATABASE DS2
GO
CREATE DATABASE DS2 ON PRIMARY
    (
		NAME = 'primary', 
		FILENAME = 'h:\mssql\data\ds.mdf' ,
		SIZE = 512MB ,
		FILEGROWTH = 0KB
    ), 
	FILEGROUP DS2_DATA
	(
		NAME = 'ds_file1.ndf' ,
		FILENAME = 'h:\mssql\data\ds_file1.ndf' ,
		SIZE = 20480MB ,
		FILEGROWTH = 2048MB
	),   
	(
		NAME = 'ds_file2.ndf' ,
		FILENAME = 'h:\mssql\data\ds_file2.ndf' ,
		SIZE = 20480MB ,
		FILEGROWTH = 2048MB
	),
	(
		NAME = 'ds_file3.ndf' ,
		FILENAME = 'h:\mssql\data\ds_file3.ndf' ,
		SIZE = 20480MB ,
		FILEGROWTH = 2048MB
	),
	(
		NAME = 'ds_file4.ndf' ,
		FILENAME = 'h:\mssql\data\ds_file4.ndf' ,
		SIZE = 20480MB ,
		FILEGROWTH = 2048MB
	), 
	(
		NAME = 'ds_file5.ndf' ,
		FILENAME = 'h:\mssql\data\ds_file5.ndf' ,
		SIZE = 20480MB ,
		FILEGROWTH = 2048MB
	)
	LOG ON
    (
		NAME = 'ds_log' , 
		FILENAME = 'h:\mssql\data\ds_log.ldf' ,
		SIZE = 10240MB ,
		FILEGROWTH = 2048MB
    )
GO

ALTER DATABASE DS2
  MODIFY FILEGROUP DS2_DATA DEFAULT;

GO
IF ( 1 = FULLTEXTSERVICEPROPERTY('IsFullTextInstalled') ) 
    BEGIN
        EXEC [DS2].[dbo].[sp_fulltext_database] @action = 'enable'
    END
GO

USE DS2
GO

ALTER DATABASE DS2 SET RECOVERY SIMPLE;

GO