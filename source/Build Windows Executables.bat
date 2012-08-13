c:\MinGW\bin\gcc -MD -Os -s -o "..\bin\ds2_create_cust.exe" .\ds2_create_cust\ds2_create_cust.c
c:\MinGW\bin\gcc -MD -Os -s -o "..\bin\ds2_create_inv.exe" .\ds2_create_inv\ds2_create_inv.c
c:\MinGW\bin\gcc -MD -Os -s -o "..\bin\ds2_create_orders.exe" .\ds2_create_orders\ds2_create_orders.c
c:\MinGW\bin\gcc -MD -Os -s -o "..\bin\ds2_create_prod.exe" .\ds2_create_prod\ds2_create_prod.c
del "..\bin\ds2_create_cust.d"
del "..\bin\ds2_create_inv.d"
del "..\bin\ds2_create_orders.d"
del "..\bin\ds2_create_prod.d"
del ..\release.zip
7z a -r -tzip "..\release.zip" ..\bin\
7z a -r -tzip "..\release.zip" "..\PowerShell Scripts\"
7z a -r -tzip "..\release.zip" "..\SQL Server Scripts\"
7z a -tzip "..\release.zip" "..\Load Generator\"
7z a -tzip "..\release.zip" "..\gpl.txt"
7z d -r -tzip "..\release.zip" "..\Load Generator\ds2sqlserverfns.cs" "..\Load Generator\ds2webfns.cs" "..\Load Generator\ds2xdriver.cs"
