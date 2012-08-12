/*
* DVD Store 2 Create Inventory data - ds2_create_inv.c
*
* Copyright (C) 2005 Dell, Inc. <dave_jaffe@dell.com> and <tmuirhead@vmware.com>
*
* Creates inventory data files for DVD Store Database V.2
* Syntax: ds2_create_inv n_prods n_Sys_Type > inv.csv  
* Builds inventory csv file from orderlines files for use in INVENTORY table load
* Each line of output file: productid, quan_in_stock, quan_sold
* Run on Linux to use large RAND_MAX (2e31-1)
* To compile: gcc -o ds2_create_inv ds2_create_inv.c -lm
* To compile on Windows: gcc -MD -Os -s -o ds2_create_inv.exe ds2_create_inv.c
* Last Updated 5/13/05
* Last Updated 6/11/2010 by GSK
* Last Updated 8/6/2012 by WDB
*
*  This program is free software; you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation; either version 2 of the License, or
*  (at your option) any later version.
*
*  This program is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with this program; if not, write to the Free Software
*  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA  */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define ERR_OPEN_1 11 
#define ERR_OPEN_2 12 
#define ERR_READ 13 
#define ERR_WRITE 14 
   
int f_err_report(int mode) { 
	if(mode==ERR_OPEN_1) printf("error opening file1n"); 
	if(mode==ERR_OPEN_2) printf("error opening file2n"); 
	else if(mode==ERR_READ) printf("error reading from file"); 
	else if(mode==ERR_WRITE) printf("error writing to file"); 
	exit(-1); 
} 



void perror(const char *s);

int main(int argc, char* argv[])
{
	char* months[] = {"jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"};
	int n_prods, i_month, orderline_id, order_id, prod_id, sales, quan_in_stock;
	char fname[50], line[110];
	char filepath[30];
	char toinputfile[50];
	char output_file[150];
	FILE *FP_orderlines;
	int* pTot_sales;
	int i_Sys_Type = 0;	 //0 for Linux, 1 for Windows        //Added by GSK  

	//if (argc < 2)
	//if (argc < 3)    //Changed by GSK
	if (argc < 5)    //Changed by WDB adding n_path n_output_file
	{
		printf("syntax:   ds2_create_inv n_path n_prods n_Sys_Type n_output_file\n");  //Changed by GSK //Changed by WDB
		printf("n_Sys_Type can be 0 (Linux) or 1 (Windows) \n");            //Added by GSK  
		exit(-1);
	}
	strcpy(filepath,argv[1]); //added by WDB
	n_prods = atoi(argv[2]);
	i_Sys_Type = atoi(argv[3]);	//Added by GSK
	strcpy(output_file,argv[4]); //Added by WDB

	char* pch;
	pch = strstr(output_file,".csv");

	if(pch == NULL)//if the string doesn't end in .csv
	{
		if(( '/' != output_file[ strlen(output_file) - 1 ] ) && ( '\\' != output_file[ strlen(output_file) - 1 ] ))//if the string doesn't end in a backslash
		{
			strcat(output_file,"/inv.csv");
		}
		else
		{
			strcat(output_file,"inv.csv");
		}
	}
	 if(( '/' != filepath[ strlen(filepath) - 1 ] ) && ( '\\' != filepath[ strlen(filepath) - 1 ] ))//if the string doesn't end in a backslash
	 {
		 strcat(filepath,"\\");
	 }
	
	pTot_sales = (int *) calloc(n_prods, sizeof(int));
	if (pTot_sales == NULL)
	{
		printf("Not enough memory\n");
		exit(-1);
	}

	for (prod_id=0; prod_id<n_prods; prod_id++) pTot_sales[prod_id] = 0;  

	for (i_month=0; i_month<12; i_month++)
	{
		strcpy(toinputfile,filepath);
		strcat(toinputfile,months[i_month]);
		sprintf(fname, "%s_orderlines.csv", toinputfile);
		if((FP_orderlines = fopen(fname, "r"))==NULL)
		{
			printf("file open error");
			break;
		}

		while(fgets(line, 100, FP_orderlines))
		{
			sscanf(line, "%d,%d,%d,%d", &orderline_id, &order_id, &prod_id, &sales);
			pTot_sales[prod_id-1] += sales;
		}
		fclose(FP_orderlines);
	}
	srand(n_prods); //Seed rand() with n_prods

	{
		FILE *fp;  
		fp=fopen(output_file, "w+");
				
		for (prod_id=0; prod_id<n_prods; prod_id++)
		{
			quan_in_stock = random2(0,500);
			if ((prod_id+1) % 10000 == 0) quan_in_stock *= 10; // boost inventory for hot sellers
			
			//Changed by GSK
			//Changed by WDB
			//commented out for now since it follows the same code path for both linux and windows
			//this is only valid if you are compiling this on windows with GCC
			//I will make a valid change for both windows and linux if you want to compile this on linux.
			fprintf(fp,"%d,%d,%d\n", prod_id+1, quan_in_stock, pTot_sales[prod_id]);  
			// if(i_Sys_Type == 0) //If System type is Linux, Append LF only   //Added by GSK
			// {
				// fprintf(fp,"%d,%d,%d\n", prod_id+1, quan_in_stock, pTot_sales[prod_id]);  
			// }
			// else if(i_Sys_Type == 1) //If System type is Windows, Append CR + LF both   //Added by GSK
			// {
				// fprintf(fp,"%d,%d,%d\r\n", prod_id+1, quan_in_stock, pTot_sales[prod_id]);  
			// }
		}// end for
		fclose(fp);
	}// end write file
}

//---------------------------------------random2---------------------------------------
//
// random2(i,j) - returns a random integer uniformly distributed between i and j,
//  inclusively  (assumes j >= i)                        
//
int random2(int i, int j)
{
	return i + floor((1+j-i) * (double) rand()/(((double) RAND_MAX) + 1));
} //random2
//
//
