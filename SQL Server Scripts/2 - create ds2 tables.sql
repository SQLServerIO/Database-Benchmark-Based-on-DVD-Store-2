-- Tables 
SET NOCOUNT ON
GO
USE DS2
GO
CREATE TABLE customers 
  ( 
     customerid           INT IDENTITY NOT NULL, 
     firstname            VARCHAR(50) NOT NULL, 
     lastname             VARCHAR(50) NOT NULL, 
     address1             VARCHAR(50) NOT NULL, 
     address2             VARCHAR(50), 
     city                 VARCHAR(50) NOT NULL, 
     state                VARCHAR(50), 
     zip                  INT, 
     country              VARCHAR(50) NOT NULL, 
     region               TINYINT NOT NULL, 
     email                VARCHAR(50), 
     phone                VARCHAR(50), 
     creditcardtype       TINYINT NOT NULL, 
     creditcard           VARCHAR(50) NOT NULL, 
     creditcardexpiration VARCHAR(50) NOT NULL, 
     username             VARCHAR(50) NOT NULL, 
     password             VARCHAR(50) NOT NULL, 
     age                  TINYINT, 
     income               INT, 
     gender               VARCHAR(1) 
  ) 


GO

CREATE TABLE cust_hist 
  ( 
     customerid INT NOT NULL, 
     orderid    INT NOT NULL, 
     prod_id    INT NOT NULL 
  ) 


GO

CREATE TABLE orders 
  ( 
     orderid     INT IDENTITY NOT NULL, 
     orderdate   DATETIME NOT NULL, 
     customerid  INT NOT NULL, 
     netamount   MONEY NOT NULL, 
     tax         MONEY NOT NULL, 
     totalamount MONEY NOT NULL 
  ) 


GO

CREATE TABLE orderlines 
  ( 
     orderlineid SMALLINT NOT NULL, 
     orderid     INT NOT NULL, 
     prod_id     INT NOT NULL, 
     quantity    SMALLINT NOT NULL, 
     orderdate   DATETIME NOT NULL 
  ) 


GO

CREATE TABLE products 
  ( 
     prod_id        INT IDENTITY NOT NULL, 
     category       TINYINT NOT NULL, 
     title          VARCHAR(50) NOT NULL, 
     actor          VARCHAR(50) NOT NULL, 
     price          MONEY NOT NULL, 
     special        TINYINT, 
     common_prod_id INT NOT NULL 
  ) 


GO

CREATE TABLE inventory 
  ( 
     prod_id       INT NOT NULL, 
     quan_in_stock INT NOT NULL, 
     sales         INT NOT NULL 
  ) 


GO

CREATE TABLE categories 
  ( 
     category     TINYINT IDENTITY NOT NULL, 
     categoryname VARCHAR(50) NOT NULL, 
  ) 


GO

SET IDENTITY_INSERT categories ON 

INSERT INTO categories 
            (category, 
             categoryname) 
VALUES      ( 1, 
              'Action' ) 

INSERT INTO categories 
            (category, 
             categoryname) 
VALUES      ( 2, 
              'Animation' ) 

INSERT INTO categories 
            (category, 
             categoryname) 
VALUES      ( 3, 
              'Children' ) 

INSERT INTO categories 
            (category, 
             categoryname) 
VALUES      ( 4, 
              'Classics' ) 

INSERT INTO categories 
            (category, 
             categoryname) 
VALUES      ( 5, 
              'Comedy' ) 

INSERT INTO categories 
            (category, 
             categoryname) 
VALUES      ( 6, 
              'Documentary' ) 

INSERT INTO categories 
            (category, 
             categoryname) 
VALUES      ( 7, 
              'Drama' ) 

INSERT INTO categories 
            (category, 
             categoryname) 
VALUES      ( 8, 
              'Family' ) 

INSERT INTO categories 
            (category, 
             categoryname) 
VALUES      ( 9, 
              'Foreign' ) 

INSERT INTO categories 
            (category, 
             categoryname) 
VALUES      ( 10, 
              'Games' ) 

INSERT INTO categories 
            (category, 
             categoryname) 
VALUES      ( 11, 
              'Horror' ) 

INSERT INTO categories 
            (category, 
             categoryname) 
VALUES      ( 12, 
              'Music' ) 

INSERT INTO categories 
            (category, 
             categoryname) 
VALUES      ( 13, 
              'New' ) 

INSERT INTO categories 
            (category, 
             categoryname) 
VALUES      ( 14, 
              'Sci-Fi' ) 

INSERT INTO categories 
            (category, 
             categoryname) 
VALUES      ( 15, 
              'Sports' ) 

INSERT INTO categories 
            (category, 
             categoryname) 
VALUES      ( 16, 
              'Travel' ) 

GO

CREATE TABLE reorder 
  ( 
     prod_id        INT NOT NULL, 
     date_low       DATETIME NOT NULL, 
     quan_low       INT NOT NULL, 
     date_reordered DATETIME, 
     quan_reordered INT, 
     date_expected  DATETIME 
  ) 


GO

-- This keeps the number of items with low QUAN_IN_STOCK constant so that the rollback rate is constant 
CREATE TRIGGER restock 
ON inventory 
after UPDATE 
AS 
    DECLARE @changedPROD_ID   INT, 
            @oldQUAN_IN_STOCK INT, 
            @newQUAN_IN_STOCK INT; 

    IF UPDATE(quan_in_stock) 
      BEGIN 
          SELECT @changedPROD_ID = i.prod_id, 
                 @oldQUAN_IN_STOCK = d.quan_in_stock, 
                 @newQUAN_IN_STOCK = i.quan_in_stock 
          FROM   inserted i 
                 INNER JOIN deleted d 
                         ON i.prod_id = d.prod_id 

          IF @newQUAN_IN_STOCK < 3 
            -- assumes quantity ordered is 1, 2, or 3 - change if different 
            BEGIN 
                INSERT INTO reorder 
                            (prod_id, 
                             date_low, 
                             quan_low) 
                VALUES      ( @changedPROD_ID, 
                              Getdate(), 
                              @newQUAN_IN_STOCK ) 

                UPDATE inventory 
                SET    quan_in_stock = @oldQUAN_IN_STOCK 
                WHERE  prod_id = @changedPROD_ID 
            END 
      END 

    RETURN 

GO

USE master
GO

SET NOCOUNT OFF 

GO