# script created by GSK 
#Last updated: 11/1/2011
#PowerShell conversion script created by Wes Brown 
#Last updated: 08/02/2012

#Purpose of script: 
#			This script will achieve following things: 
#			1)  Calculate number of rows for each of customers, orders and products table according to database size.
#			2)  Call data generation C programs to create CSV files for each table in their respective folders.
#			3)  Create database build and cleanup *.sql scripts for the specified database size.
#Prerequisites for script:
#			Powershell V2
#			To understand how to use this  script and what parameter values should be given to this  script,
#			please go through section 6 of documentation ds2.1_Documentation.txt in /ds2 folder

#Here We are assuming default values for 10mb small SQL Server Database instance on Windows
#Though user can specify any valid value
$database_size 		= 10					#Database Size
$database_size_str 	= "mb"   		#String to indicate size: MB / GB or mb / gb
$csv_file_path 		= ""#get-location
										
$is_GB_Size_S 		= "gb"
$is_MB_Size_S 		= "mb"

$bln_is_Large_DB 	= 0
$bln_is_Small_DB 	= 0
$bln_is_Medium_DB 	= 0
$bln_is_Sys_Win 	= 0
$str_is_Small_DB 	= ""
$str_is_Medium_DB 	= ""
$str_is_Large_DB 	= ""


Write-Host  "Please enter following parameters: "
Write-Host   "***********************************"
$database_size 		= Read-Host "Please enter database size (integer expected) :"
$database_size 		= $database_size.Trim()
$database_size_str 	= Read-Host "Please enter whether above database size is in (MB / GB) : "
$execute_path 		= Read-Host "Please enter path of executables: "
$output_path  		= Read-Host "Please enter path to store the output: "

Write-Host  "***********************************"

#Set the flags according to parameters passed. These flags will be used further
if($database_size_str.ToLower() -match $is_GB_Size_S.ToLower())
{
	if($database_size -eq 1)
	{
		$bln_is_Medium_DB = 1	
		$str_is_Medium_DB = "M"
	}
	elseif($database_size -gt 1 -match $database_size -lt 1024)
	{
		$bln_is_Large_DB = 1
		$str_is_Large_DB = "L"
	}
}
elseif($database_size_str.ToLower() -match $is_MB_Size_S.ToLower())
{
	if($database_size -ge 1 -and $database_size -lt 1024)
	{
		$bln_is_Small_DB = 1
		$str_is_Small_DB = "S"
	}	
}

#***************************************************************************************

Write-Host   "Initializing parameters..."
Write-Host   "***********************************"
Write-Host   "Database Size: $database_size "
Write-Host   "Database size is in $database_size_str "
Write-Host   "Executables located at $execute_path "
Write-Host   "CSV output path $output_path" 
Write-Host   "***********************************"

#***************************************************************************************

#Code to extract driveletter on which  script is executing
#This driveletter will be used in SQL Server 2008 template scripts to replace driveletter in CSV datafile path
$str_driveletter 	= ""
$bln_IsCygwin 		= 0
#Extract first letter which is driveletter from executepath	
$str_driveletter 	= $execute_path.ToString().Substring(0,1)

#***************************************************************************************

Write-Host   "Calculating Rows in tables "

#First we need to calculate ratio which will determine number of rows in Major tables
# Customer, Orders and Products

$i_Cust_Rows    = 0
$i_Ord_Rows     = 0
$i_Prod_Rows    = 0
$mult_Cust_Rows = 0
$mult_Ord_Rows  = 0
$mult_Prod_Rows = 0
$ratio_Mult     = 0
$ratio_Cust     = 0
$ratio_Ord      = 0
$ratio_Prod     = 0


#For small database (Database size greater than 10MB till 1GB/ 1000 MB)
if($bln_is_Small_DB -eq 1)
{
	#Now base DB will be 10MB database and ratio calculated wrt to that
	Write-Host   "Small size database (less than 1 GB) "
	$mult_Cust_Rows = 20000				# 2 x 10^4
	$mult_Ord_Rows  = 1000				# 1 x 10^3
	$mult_Prod_Rows = 10000				# 1 x 10^4
	$ratio_Mult 	= ($database_size / 10)	# 10MB database is base
}

#For medium database with size exactly 1GB
if($bln_is_Medium_DB -eq 1)
{
	Write-Host   "Medium size database ( equal to 1 GB) "
	$mult_Cust_Rows = 2000000				# 2 x 10^6
	$mult_Ord_Rows  = 100000				# 1 x 10^5
	$mult_Prod_Rows = 100000				# 1 x 10^5
	$ratio_Mult 	= ($database_size / 1)	 	# 1GB database is base
}

#For large database with size > 1GB
if($bln_is_Large_DB -eq 1)
{
	Write-Host   "Large size database ( greater than 1 GB) "
	$mult_Cust_Rows = 200000000 			# 2 x 10^8
	$mult_Ord_Rows  = 10000000				# 1 x 10^7
	$mult_Prod_Rows = 1000000				# 1 x 10^6
	$ratio_Mult 	= ($database_size / 100)	# 100GB database is base
}

Write-Host   "Ratio calculated : $ratio_Mult "

#Calculate number of rows in table according to ratio
$i_Cust_Rows = ($mult_Cust_Rows * $ratio_Mult)
$i_Ord_Rows  = ($mult_Ord_Rows * $ratio_Mult)
$i_Prod_Rows = ($mult_Prod_Rows * $ratio_Mult)

#print   number of rows for a check
Write-Host   "Customer Rows: $i_Cust_Rows "
Write-Host   "Order Rows / month: $i_Ord_Rows "
Write-Host   "Product Rows: $i_Prod_Rows "

#***************************************************************************************
#Start data generation and dump data into CSV files
# CSV files will be converted into their windows or linux equivalent according to System type

Write-Host   "Creating CSV files...."

#These are parameters to C Program
# Declaration and Initialization is done here for $par4 and $par_Sys_Type 

$par1_Start    		= 0        #start
$par2_End      		= 0        #end
$par3_Fname    		= ""       #Name 
#Month Name used for Order table data generation
$par3_ArrMonth      = @("jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec")  
$par4_DB_Size       = ""    #S|M|L 
$par5_Month_Number  = 0     #parameter used for determining month for Order table data generation(1 to 12)
$par_Sys_Type       = 0     #0 (Linux) / 1 (Windows)
$par_n_Prod         = 0     # Number of Product table rows parameter for Product and Inv data generation
$par_Max_Prod_Id    = 0	    # Max Product Id = number of Product table rows  used in Order table data generation
$par_Max_Cust_Id    = 0	    # Max Customer Id = number of Customer table rows used in Order table data generation

if($bln_is_Small_DB -eq 1)
{
	 $par4_DB_Size = $str_is_Small_DB
}
elseif($bln_is_Medium_DB -eq 1) 
{
	$par4_DB_Size = $str_is_Medium_DB	
}
elseif($bln_is_Large_DB -eq 1)
{
	 $par4_DB_Size = $str_is_Large_DB
}

$par_Sys_Type = 1

#***************************************************************************************

Write-Host   "Starting to create CSV data files.... "
Write-Host   "For larger database sizes, it will take time."
Write-Host   "Do not kill the script till execution is complete. "

#Create CSV files for Customer table
#Call already compiled C program in respective folders to generate CSV Files

#Initialize parameters for Customer C Program
$par1_Start = 1
$par2_End   = ($i_Cust_Rows / 2)
$par3_Fname = "US" 

Write-Host   "Creating Customer CSV files "
Write-Host   "$par1_Start $par2_End $par3_Fname $par4_DB_Size $par_Sys_Type " 

$par1_Start = (($i_Cust_Rows / 2) + 1)
$par2_End 	= $i_Cust_Rows
$par3_Fname = "US"

Write-Host   "$par1_Start $par2_End $par3_Fname $par4_DB_Size $par_Sys_Type "
invoke-expression "$execute_path\ds2_create_cust.exe $par1_Start $par2_End $par3_Fname $par4_DB_Size $par_Sys_Type $output_path\row_cust.csv"
Write-Host   "Customer CSV Files created "

#***************************************************************************************
#Create CSV files for Orders, Orderlines and Cust_Hist table
#Call already compiled C program in respective folders to generate CSV Files

Write-Host   "Creating Orders, Orderlines and Cust_Hist csv files "

$par1_Start 		= 0 
$par2_End 			= 0   
$par3_Fname 		= ""
$par5_Month_Number 	= 0
$par_Max_Prod_Id 	= $i_Prod_Rows
$par_Max_Cust_Id 	= $i_Cust_Rows
$i_LoopCount 		= 0
foreach ($month in $par3_ArrMonth)
{
	$i_LoopCount++
	$par5_Month_Number 	= $i_LoopCount
	$par1_Start 		= ($par2_End + 1)
	$par2_End 			= ($i_Ord_Rows * $par5_Month_Number)

	Write-Host   "Creating Order CSV file for Month $month"	
	Write-Host   "$par1_Start $par2_End $month $par4_DB_Size $par5_Month_Number $par_Sys_Type $par_Max_Prod_Id $par_Max_Cust_Id "
    invoke-expression "$execute_path\ds2_create_orders.exe $par1_Start $par2_End $output_path\$month $par4_DB_Size $par5_Month_Number $par_Sys_Type $par_Max_Prod_Id $par_Max_Cust_Id"
    Write-Host "$execute_path\ds2_create_orders.exe $par1_Start $par2_End $output_path\$month $par4_DB_Size $par5_Month_Number $par_Sys_Type $par_Max_Prod_Id $par_Max_Cust_Id"
}
Write-Host   "All Order, Orderlines, Cust_Hist CSV files created"

#***************************************************************************************

#Create CSV files for Products,Inv table
#Call already compiled C program in respective folders to generate CSV Files

$par_n_Prod = $i_Prod_Rows   #Initialize to number of rows for Product table


#Create Inventory CSV file first since we are in orders folder now
Write-Host   "Creating Inventory CSV file"
invoke-expression "$execute_path\ds2_create_inv.exe $output_path\ $par_n_Prod $par_Sys_Type $output_path\inv.csv"
Write-Host   "Inventory CSV file created"

#Create Product CSV file first since we are in prod folder now
Write-Host   "Creating product CSV file"
invoke-expression "$execute_path\ds2_create_prod.exe $par_n_Prod $par_Sys_Type $output_path\prod.csv"
Write-Host   "Product CSV file created"

#***************************************************************************************

#Now move to required folders according to Database Type
$ord_row 			= ($i_Ord_Rows * 12)
$cust_row_plus_one 	= ($i_Cust_Rows + 1)

#$SchemaOutputFile  		= Read-Host "Please enter path to store the create database script: "
#$SchemaFile = New-Object System.IO.StreamWriter $SchemaOutputFile;
#$SchemaFile.Writeline("testing")
#$SchemaFile.close()


#***************************************************************************************

