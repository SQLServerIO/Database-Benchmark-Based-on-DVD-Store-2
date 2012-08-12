<#
.SYNOPSIS
   <A brief description of the script>
.DESCRIPTION
   <A detailed description of the script>
.PARAMETER <paramName>
   <Description of script parameter>
.EXAMPLE
   <An example of using the script>
#>
$database_size 		= 10					#Database Size
$database_size_str 	= "mb"   		#String to indicate size: MB / GB or mb / gb
$database_type 		= "mssql"    		#Type = mssql / sql / pgsql / oracle / MSSQL / SQL / ORACLE /PGSQL
$db_sys_type 		= "win"   				#System : win / linux / WIN / LINUX
$db_file_path 		= "c:\"				#User can give any path to store DBFiles
$csv_file_path 		= ""#get-location

$arr_db_file_paths  = @("","","","","","","","","","")
$arr1_db_file_paths = @("","","","","","","","","","")

$is_GB_Size_S 		= "gb"
$is_MB_Size_S 		= "mb"
$is_Sys_Win_S 		= "win"
$is_Sys_Linux_S 	= "linux"
$is_DB_SQLServer_S 	= "mssql"
$is_DB_SQL_S 		= "sql"
$is_DB_PGSQL_S 		= "pgsql"
$is_DB_Oracle_S 	= "oracle"

$bln_is_Large_DB 	= 0
$bln_is_Small_DB 	= 0
$bln_is_Medium_DB 	= 0
$bln_is_Sys_Win 	= 0
$bln_is_Sys_Linux 	= 0
$bln_is_DB_MSSQL 	= 0
$bln_is_DB_SQL 		= 0
$bln_is_DB_PGSQL 	= 0
$bln_is_DB_ORACLE 	= 0
$str_is_Small_DB 	= ""
$str_is_Medium_DB 	= ""
$str_is_Large_DB 	= ""
$str_file_name 		= ""				#Store name of file to be created from template 


Write-Host  "Please enter following parameters: "
Write-Host   "***********************************"
$database_size 		= Read-Host "Please enter database size (integer expected) :"
$database_size 		= $database_size.Trim()
$database_size_str 	= Read-Host "Please enter whether above database size is in (MB / GB) : "
$database_type 		= Read-Host "Please enter database type (MSSQL / SQL / PGSQL / ORACLE) : "
if ($database_type -eq "MSSQL")
{
    $db_sys_type = "WIN"
}
else
{
    $db_sys_type = Read-Host "Please enter system type on which DB Server is installed (WIN / LINUX) : "
}
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

#Set the flags according to parameters passed. These flags will be used further
if($db_sys_type.ToLower() -match $is_Sys_Win_S.ToLower())
{	
	$bln_is_Sys_Win = 1
}
elseif($db_sys_type.ToLower() -match $is_Sys_Linux_S.ToLower())
{
	$bln_is_Sys_Linux = 1
}

#Set the flags according to parameters passed. These flags will be used further
if($database_type.ToLower() -match $is_DB_SQLServer_S.ToLower())
{
	$bln_is_DB_MSSQL	= 1
}
elseif($database_type.ToLower() -match $is_DB_SQL_S.ToLower())
{
	$bln_is_DB_SQL 		= 1	
}
elseif($database_type.ToLower() -match $is_DB_PGSQL_S.ToLower())
{
	$bln_is_DB_PGSQL 	= 1	
}
elseif($database_type.ToLower() -match $is_DB_Oracle_S.ToLower())
{	
	$bln_is_DB_ORACLE 	= 1
}

#***************************************************************************************

if($bln_is_DB_ORACLE -eq 1 -or $bln_is_DB_MSSQL -eq 1)
{		
	if($bln_is_DB_ORACLE -eq 1)
	{
		#Only four paths needed - Cust table dbfile, Index dbfile, DS_MISC dbfile, Order table dbfile respectively
		#Just paths where datafiles will be stored are needed
		#Paths for oracle on windows should be like this : c:\oracledbfiles\
		#Paths for oracle on linux should be like this : /oracledbfiles/
		
		Write-Host   "For Oracle database scripts, total 4 paths needed to specify where cust, index, ds_misc and order dbfiles are stored. "
		Write-Host   "If only one path is specified, it will be assumed same for all dbfiles. "
		Write-Host   "For specifying multiple paths use  character as seperator to specify multiple paths "
		
		Read-Host 	$db_file_path = "Please enter path(s) (;  seperated if more than one path) where Database Files will be stored (ensure that path exists) : "
		$arr1_db_file_paths = $db_file_path.Split(";")

		#If number of paths specified are between 2 and 4 or greater than 4 , its an error						 
		if($arr1_db_file_paths.Length -ne 1 -and $arr1_db_file_paths.Length -lt 4 -or ($arr1_db_file_paths.Length) -gt 4)
		{
			Write-Host   "Wrong number of paths entered"
			Write-Host   "Four paths for following are needed:  Cust table dbfile, Index dbfile, DS_MISC dbfile, Order table dbfile respectively "
			exit(0)
		}
		#If single path is specified by user then paths for all dbfiles are assumed same
		if($arr1_db_file_paths.Length -eq 1)
		{
			$arr_db_file_paths[0] =	$arr_db_file_paths[1] = $arr_db_file_paths[2] = $arr_db_file_paths[3] = $arr1_db_file_paths[0]	
		}
		else #If 4 paths spacified then 
		{
			$arr_db_file_paths[0] = $arr1_db_file_paths[0]
			$arr_db_file_paths[1] = $arr1_db_file_paths[1]
			$arr_db_file_paths[2] = $arr1_db_file_paths[2]
			$arr_db_file_paths[3] = $arr1_db_file_paths[3]
		}
		
	}
	elseif($bln_is_DB_MSSQL -eq 1)
	{
		#Seven paths for storing following files are needed: ds.mdf, ds_misc.ndf, cust1.ndf, cust2.ndf, orders1.ndf, orders2.ndf, ind1.ndf, ind2.ndf, ds_log.ldf, FULLTEXTCAT_DSPROD(catalog file for full text search)  respectively
		#Two dbfiles per table are assumed and path for second dbfile of same table is assumed same as that of first dbfile 
		#Just paths where datafiles will be stored are needed
		#Paths for SQL Server on windows should be like this : c:\oracledbfiles\
 
		
		Write-Host   "For SQL Server database scripts, total 7 paths needed to specify where ds.mdf,ds_misc,cust,order,index,log and full text catalog dbfiles are stored. "
		Write-Host   "If only one path is specified, it will be assumed same for all dbfiles. "
		Write-Host   "For specifying multiple paths use  character as seperator to specify multiple paths "
				
		$db_file_path 		= Read-Host "Please enter path(s) (;  seperated if more than one path) where Database Files will be stored (ensure that path exists) : "
		$arr1_db_file_paths = $db_file_path.Split(";")   #Split tokenized string and store paths in array
		
		#If number of paths specified are between 2 and 7 or greater than 7 , its an error
        Write-Host $arr1_db_file_paths.Length
		if(($arr1_db_file_paths.Length -ne 1 -and $arr1_db_file_paths.Length -lt 7) -or $arr1_db_file_paths.Length -gt 7)
		{
			Write-Host   "Wrong number of paths entered"
			Write-Host   "Seven paths for storing following files are needed: ds.mdf, ds_misc.ndf, cust1.ndf, orders1.ndf, ind1.ndf, ds_log.ldf, FULLTEXTCAT_DSPROD(catalog file for full text search)  respectively "
			exit(0)
		}
		#If single path is specified by user then paths for all dbfiles are assumed same
		if($arr1_db_file_paths.Length -eq 1)
		{
			$arr_db_file_paths[0] =	$arr_db_file_paths[1] = $arr_db_file_paths[2] = $arr_db_file_paths[3] = $arr1_db_file_paths[0]
			$arr_db_file_paths[4] =	$arr_db_file_paths[5] = $arr_db_file_paths[6] = $arr_db_file_paths[7] = $arr1_db_file_paths[0]		
			$arr_db_file_paths[8] =	$arr_db_file_paths[9] = $arr1_db_file_paths[0]
		}
		else #If 7 paths spacified then 
		{
			$arr_db_file_paths[0] = $arr1_db_file_paths[0]   							#path for ds.mdf
			$arr_db_file_paths[1] = $arr1_db_file_paths[1]   							#path for ds_misc.ndf
			$arr_db_file_paths[2] = $arr_db_file_paths[3] = $arr1_db_file_paths[2]		#path for cust1.ndf and cust2.ndf
			$arr_db_file_paths[4] = $arr_db_file_paths[5] = $arr1_db_file_paths[3]		#path for orders1.ndf and orders2.ndf
			$arr_db_file_paths[6] = $arr_db_file_paths[7] = $arr1_db_file_paths[4]		#path for ind1.ndf and ind2.ndf
			$arr_db_file_paths[8] = $arr1_db_file_paths[5]								#path for ds_log.ldf
			$arr_db_file_paths[9] = $arr1_db_file_paths[6]								#path for full text catalog file
		}				
	}	
}

Write-Host   "***********************************"
#***************************************************************************************

Write-Host   "Initializing parameters..."
Write-Host   "***********************************"
Write-Host   "Database Size: $database_size "
Write-Host   "Database size is in $database_size_str "
Write-Host   "Database Type is $database_type "
Write-Host   "System Type for DB Server is $db_sys_type "
if($bln_is_DB_ORACLE -eq 1 -or $bln_is_DB_MSSQL -eq 1)
{
	Write-Host   "File Paths : $db_file_path "		
}
Write-Host   "***********************************"


if($bln_is_DB_SQL -eq 1)			#For SQL
{
	#Open a template file and replace placeholders in it and write new file

	Write-Host   "Creating build script for SQL from templates... "
	Write-Host   "Template files are stored in respective build folders and the output files are also stored in same folder "
	Write-Host   "Template files are named with generic_template at end of their filename and the output files without _template at end "
	
	$lines 			= ""
	$line 			= ""
	$str_file_name 	= ""
	open (FILE, "sqlds2_cleanup_generic_template.sql") -or die "Can not Open file : $!"	
	$lines 			=  <FILE>
	close (FILE)
	foreach( $line in $lines)
	{
		$line =~ s/{CUST_ROW}/$i_Cust_Rows/g
		$line =~ s/{ORD_ROW}/$ord_row/g
	}	
	$str_file_name = "sqlds2_cleanup_".$database_size.$database_size_str.".sql"
	open (NEWFILE, ">" , $str_file_name) -or die "Creating new file to write failed : $!"
	print NEWFILE $lines
	close (NEWFILE)
	
	Write-Host   "Completed creating and writing build scripts for SQL database... "
	
}
elseif($bln_is_DB_PGSQL -eq 1)			#For PGSQL
{
	#Open a template file and replace placeholders in it and write new file

	Write-Host   "Creating build script for PostgreSQL from templates... "
	Write-Host   "Template files are stored in respective build folders and the output files are also stored in same folder "
	Write-Host   "Template files are named with generic_template at end of their filename and the output files without _template at end "
	
	$lines = ""
	$line = ""
	$str_file_name = ""
	open (FILE, "pgsqlds2_cleanup_generic_template.sql") -or die "Can not Open file : $!"	
	$lines =  <FILE>
	close (FILE)
	foreach ($line in $lines)
	{
		$line =~ s/{CUST_ROW}/$i_Cust_Rows/g
		$line =~ s/{ORD_ROW}/$ord_row/g
	}	
	$str_file_name = "pgsqlds2_cleanup_".$database_size.$database_size_str.".sql"
	open (NEWFILE, ">" , $str_file_name) -or die "Creating new file to write failed : $!"
	print NEWFILE $lines
	close (NEWFILE)
	
	Write-Host   "Completed creating and writing build scripts for PostgreSQL database... "
	
}
elseif($bln_is_DB_ORACLE -eq 1) 		#For Oracle
{
	Write-Host   "Started creating and writing build scripts for Oracle database... "
	
	#Create cleanup sql script (with foreign key disabled) from template
	$lines = ""
	$line = ""
	$str_file_name = ""
	open (FILE, "oracleds2_cleanup_generic_fk_disabled_template.sql") -or die "Can not Open file : $!"	
	$lines =  <FILE>
	close (FILE)
	foreach ($line in $lines)
	{
		$line =~ s/{CUST_ROW}/$i_Cust_Rows/g         
		$line =~ s/{CUST_ROW_PLUS_ONE}/$cust_row_plus_one/g	
	}	
	$str_file_name = "oracleds2_cleanup_".$database_size.$database_size_str."_fk_disabled.sql"
	open (NEWFILE, ">", $str_file_name) -or die "Creating new file to write failed : $!"
	print NEWFILE $lines
	close (NEWFILE)
	
	#Create cleanup sql script (without foreign key disabled) from template
	$lines = ""
	$line = ""
	$str_file_name = ""
	open (FILE, "oracleds2_cleanup_generic_template.sql") -or die "Can not Open file : $!"	
	$lines =  <FILE>
	close (FILE)
	foreach ($line in $lines)
	{
		$line =~ s/{CUST_ROW}/$i_Cust_Rows/g         
		$line =~ s/{CUST_ROW_PLUS_ONE}/$cust_row_plus_one/g	
	}	
	$str_file_name = "oracleds2_cleanup_".$database_size.$database_size_str.".sql"
	open (NEWFILE, ">", $str_file_name) -or die "Creating new file to write failed : $!"
	print NEWFILE $lines
	close (NEWFILE)
	
	#Create cleanup shell script (without foreign key disabled) from template
	$lines = ""
	$line = ""
	$str_file_name = ""
	open (FILE, "oracleds2_cleanup_generic_template.sh") -or die "Can not Open file : $!"	
	$lines =  <FILE>
	close (FILE)
	$str_file_name = "oracleds2_cleanup_".$database_size.$database_size_str.".sql"
	foreach ($line in $lines)
	{
		$line =~ s/{SQL_FNAME}/$str_file_name/g	
	}		
	$str_file_name = ""
	$str_file_name = "oracleds2_cleanup_".$database_size.$database_size_str.".sh"
	open (NEWFILE, ">", $str_file_name) -or die "Creating new file to write failed : $!"
	print NEWFILE $lines
	close (NEWFILE)
	
	#Create cleanup sql script (with foreign key disabled) from template
	$lines = ""
	$line = ""
	$str_file_name = ""
	open (FILE, "oracleds2_cleanup_generic_fk_disabled_template.sql") -or die "Can not Open file : $!"	
	$lines =  <FILE>
	close (FILE)
	foreach ($line in $lines)
	{
		$line =~ s/{CUST_ROW}/$i_Cust_Rows/g         
		$line =~ s/{CUST_ROW_PLUS_ONE}/$cust_row_plus_one/g	
	}	
	$str_file_name = "oracleds2_cleanup_".$database_size.$database_size_str."_fk_disabled.sql"
	open (NEWFILE, ">", $str_file_name) -or die "Creating new file to write failed : $!"
	print NEWFILE $lines
	close (NEWFILE)
	
	#Create cleanup shell script (with foreign key disabled) from template
	$lines = ""
	$line = ""
	$str_file_name = ""
	open (FILE, "oracleds2_cleanup_generic_fk_disabled_template.sh") -or die "Can not Open file : $!"	
	$lines =  <FILE>
	close (FILE)
	$str_file_name = "oracleds2_cleanup_".$database_size.$database_size_str."_fk_disabled.sql"
	foreach ($line in $lines)
	{
		$line =~ s/{SQL_FNAME}/$str_file_name/g         			
	}	
	$str_file_name = ""
	$str_file_name = "oracleds2_cleanup_".$database_size.$database_size_str."_fk_disabled.sh"
	open (NEWFILE, ">", $str_file_name) -or die "Creating new file to write failed : $!"
	print NEWFILE $lines
	close (NEWFILE)
	
	
	#Create create db sql script from template
	$lines = ""
	$line = ""
	$str_file_name = ""
	open (FILE, "oracleds2_create_db_generic_template.sql") -or die "Can not Open file : $!"	
	$lines =  <FILE>
	close (FILE)
	foreach ($line in $lines)
	{
		$line =~ s/{CUST_ROW_PLUS_ONE}/$cust_row_plus_one/g         			
	}	
	$str_file_name = "oracleds2_create_db_".$database_size.$database_size_str.".sql"
	open (NEWFILE, ">", $str_file_name) -or die "Creating new file to write failed : $!"
	print NEWFILE $lines
	close (NEWFILE)
	
	#TODO : Need to create table space script which will depend on database size since number of database files will vary as DBsize varies
	#Create create tablespace sql script from template
	$lines = ""
	$line = ""
	$str_file_name = ""
	open (FILE, "oracleds2_create_tablespaces_generic_template.sql") -or die "Can not Open file : $!"	
	$lines =  <FILE>
	close (FILE)	
	 $i_Cnt = 0
	foreach ($line in $lines)
	{
		if($line =~ m/{CUST1DATAFILE_PATH}/)
		{
			$line =~ s/{CUST1DATAFILE_PATH}/$arr_db_file_paths[0]/g						
		}			         			
		if($line =~ m/{CUST2DATAFILE_PATH}/)
		{
			$line =~ s/{CUST2DATAFILE_PATH}/$arr_db_file_paths[0]/g						
		}	
		if($line =~ m/{IND1DATAFILE_PATH}/)
		{
			$line =~ s/{IND1DATAFILE_PATH}/$arr_db_file_paths[1]/g						
		}	
		if($line =~ m/{IND2DATAFILE_PATH}/)
		{
			$line =~ s/{IND2DATAFILE_PATH}/$arr_db_file_paths[1]/g						
		}	
		if($line =~ m/{DS_MISCDATAFILE_PATH}/)
		{
			$line =~ s/{DS_MISCDATAFILE_PATH}/$arr_db_file_paths[2]/g						
		}	
		if($line =~ m/{ORDER1DATAFILE_PATH}/)
		{
			$line =~ s/{ORDER1DATAFILE_PATH}/$arr_db_file_paths[3]/g						
		}	
		if($line =~ m/{ORDER2DATAFILE_PATH}/)
		{
			$line =~ s/{ORDER2DATAFILE_PATH}/$arr_db_file_paths[3]/g						
		}	
	}	
	$str_file_name = "oracleds2_create_tablespaces_".$database_size.$database_size_str.".sql"
	open (NEWFILE, ">", $str_file_name) -or die "Creating new file to write failed : $!"
	print NEWFILE $lines
	close (NEWFILE)
		
	#Create new create_all shell script file from template
	$lines = ""
	$line = ""	
	$str_file_name = ""
	open (FILE, "oracleds2_create_all_generic_template.sh") -or die "Can not Open file : $!"	
	$lines =  <FILE>
	close (FILE)
	foreach ($line in $lines)
	{
		$str_file_name = "oracleds2_create_tablespaces_".$database_size.$database_size_str.".sql"
		$line =~ s/{TBLSPACE_SQLFNAME}/$str_file_name/g  
		$str_file_name = "oracleds2_create_db_".$database_size.$database_size_str.".sql"     
		$line =~ s/{CREATEDB_SQLFNAME}/$str_file_name/g		   		   	
	}	
	$str_file_name = ""
	$str_file_name = "oracleds2_create_all_".$database_size.$database_size_str.".sh"
	open (NEWFILE, ">", $str_file_name) -or die "Creating new file to write failed : $!"
	print NEWFILE $lines
	close (NEWFILE)
	
	Write-Host   "Completed creating and writing build scripts for Oracle database!!"
}
elseif($bln_is_DB_MSSQL -eq 1) 		#For SQL Server
{
	Write-Host   "Started creating and writing build scripts for SQL Server database..."

	#Create new create_all sql script file from template
	$lines = ""
	$line = ""	
	$str_file_name = ""
	open (FILE, "sqlserverds2_create_all_generic_template.sql") -or die "Can not Open file : $!"	
	$lines =  <FILE>
	close (FILE)
	 $i_Cnt = 0
	 $i_arrCnt = $arr_db_file_paths.Length
	 $i_LastIndex = ($i_arrCnt - 1)
	foreach ($line in $lines)
	{
		if($line =~ m/{DATAFILE_PATH}/)
		{
			#$arr_db_file_paths[$i_Cnt] =~ s/\\//g    #Replace all backslashes if exists
			$line =~ s/{DATAFILE_PATH}/$arr_db_file_paths[$i_Cnt]/g			
			$i_Cnt = ($i_Cnt + 1)				
		}			   
		if($line =~ m/{FULLTEXTCAT_PATH}/)
		{
			$line =~ s/{FULLTEXTCAT_PATH}/$arr_db_file_paths[$i_LastIndex]/g
		}
		if($line =~ m/{DRIVELETTER}/)
		{
			$line =~ s/{DRIVELETTER}/$str_driveletter/g
		}            			
	}	
	$str_file_name = "sqlserverds2_create_all_".$database_size.$database_size_str.".sql"
	open (NEWFILE, ">", $str_file_name) -or die "Creating new file to write failed : $!"
	print NEWFILE $lines
	close (NEWFILE)
	
	#Create new cleanup sql script file from template
	$lines = ""
	$line = ""	
	$str_file_name = ""
	open (FILE, "sqlserverds2_cleanup_generic_template.sql") -or die "Can not Open file : $!"	
	$lines =  <FILE>
	close (FILE)
	foreach ($line in $lines)
	{
		$line =~ s/{CUST_ROW}/$i_Cust_Rows/g
		$line =~ s/{ORD_ROW}/$ord_row/g
		$line =~ s/{DRIVELETTER}/$str_driveletter/g					   		   	
	}	
	$str_file_name = "sqlserverds2_cleanup_".$database_size.$database_size_str.".sql"
	open (NEWFILE, ">", $str_file_name) -or die "Creating new file to write failed : $!"
	print NEWFILE $lines
	close (NEWFILE)
	
	#Create new create_ind sql script from template
	$lines = ""
	$line = ""	
	$str_file_name = ""
	open (FILE, "sqlserverds2_create_ind_generic_template.sql") -or die "Can not Open file : $!"	
	$lines =  <FILE>
	close (FILE)
	 $i_Cnt = 0
	 $i_arrCnt = $arr_db_file_paths.Length
	 $i_LastIndex = ($i_arrCnt - 1)
	foreach ($line in $lines)
	{				   
		if($line =~ m/{FULLTEXTCAT_PATH}/)
		{
			#$arr_db_file_paths[$i_Cnt] =~ s/\\//g    #Replace all backslashes if exists
			$line =~ s/{FULLTEXTCAT_PATH}/$arr_db_file_paths[$i_LastIndex]/g
		}      			
	}	
	$str_file_name = "sqlserverds2_create_ind_".$database_size.$database_size_str.".sql"
	open (NEWFILE, ">", $str_file_name) -or die "Creating new file to write failed : $!"
	print NEWFILE $lines
	close (NEWFILE)
	
	#Create new create_db sql script file from template
	$lines = ""
	$line = ""	
	$str_file_name = ""
	open (FILE, "sqlserverds2_create_db_generic_template.sql") -or die "Can not Open file : $!"	
	$lines =  <FILE>
	close (FILE)
	 $i_Cnt = 0
	 $i_arrCnt = $arr_db_file_paths.Length
	 $i_LastIndex = ($i_arrCnt - 1)
	foreach ($line in $lines)
	{
		if($line =~ m/{DATAFILE_PATH}/)
		{
			#$arr_db_file_paths[$i_Cnt] =~ s/\\//g    #Replace all backslashes if exists
			$line =~ s/{DATAFILE_PATH}/$arr_db_file_paths[$i_Cnt]/g			
			$i_Cnt = ($i_Cnt + 1)				
		}			   		    			
	}	
	$str_file_name = "sqlserverds2_create_db_".$database_size.$database_size_str.".sql"
	open (NEWFILE, ">", $str_file_name) -or die "Creating new file to write failed : $!"
	print NEWFILE $lines
	close (NEWFILE)
	
	Write-Host   "Completed creating and writing build scripts for SQL Server database!!"
}

Write-Host   "All database build scripts(shell and sql) are dumped into their respective folders. "
Write-Host   "These scripts are created from template files in same folders with '_generic_template' in their name. "
Write-Host   "Scripts that are created from template files have '_' $database_size $database_size_str in their name. "
Write-Host   "User can edit the sql script generated for customizing sql script for more DBFiles per table and change the paths of DBFiles."
Write-Host   "Now Run CreateConfigFile.pl  script in ds2 folder which will generate configuration file used as input to the driver program."

#***************************************************************************************

#Now move to required folders according to Database Type
$ord_row 			= ($i_Ord_Rows * 12)
$cust_row_plus_one 	= ($i_Cust_Rows + 1)

#$SchemaOutputFile  		= Read-Host "Please enter path to store the create database script: "
#$SchemaFile = New-Object System.IO.StreamWriter $SchemaOutputFile;
#$SchemaFile.Writeline("testing")
#$SchemaFile.close()

#***************************************************************************************

