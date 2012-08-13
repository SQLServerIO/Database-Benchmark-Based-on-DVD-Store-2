# DVD Store Benchmark

This is a fork of the DVD Store Database Benchmark V2.1 created by Dell and VMWare.  
This version is SQL Server specific and simplified for ease of use.  

Folder Structure:  
PowerShell Scripts  
This folder contains three scripts.  
generate ds2 bulk load files.ps1:  
This script will walk you through a series of questions to generate the bulk load files.  
Please enter database size (integer expected) :  
Any size from 1 MB to hundreds of terabytes can be generated.  
It takes about 13 minutes on an Intel Q6600 to generate a 10GB data set.  
Please enter whether above database size is in (MB / GB) :  
Specifiy the unit of measure megabytes or gigabytes  
Please enter path of executables :  
This is where you unpacked the executables to  
Please enter path to store the output :  
This where you want the CSV files to go. I recommend a seprate drive with plenty of free space.  

generate ds2 sql scripts.ps1 INCOMPLETE  
This script will walk you through a series of questions to generate the database and schema creation scripts.  

generate ds2 config file.ps1 INCOMPLETE  
This script will walk you through a series of questions to generate the configuration file for the load tests.  

SQL Server Scripts  
This folder contains pre-generated SQL Server database and schema creation scripts. Modify to suit your needs.  

source  
The C source code for the four programs that generate the bulk load data.  
using MinGW to compile them on Windows c:\MinGW\bin\gcc -MD -Os -s -o "output exec" "source file"  
Sample batch file Build Windows Executables.bat for you to modify or use to do the build if you so desire.  

Load Generator  
The source code and executible to generate the workloads you can use a middle aspx tier stored in the web directory.  
You can also generate load using the ds2sqlserverdriver.exe and the config generated earlier.  
