/*
* DVD Store 2 Create Product data - ds2_create_prod.c
*
* Copyright (C) 2005 Dell, Inc. <dave_jaffe@dell.com> and <tmuirhead@vmware.com>
*
* Creates product data files for DVD Store Database V.2
* Syntax: ds2_create_prod n_prods n_Sys_Type > prod.csv
* Builds DS database products load file
* Run on Linux to use large RAND_MAX (2e31-1)
* To compile: gcc -o ds2_create_prod ds2_create_prod.c -lm
* Last Updated 5/13/05
* Last Updated 6/11/2010 by GSK
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
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "ds2_data.h"

#define MAX_CATEGORY 16

float  price;
int    prod_id, category, quan_in_stock, special, sales_prod_id, sales, common_prod_id;
char   title[50], actor[50], sales_csv_fn[50];
char output_file[150];
FILE*  fp;

//TODO: possibly make other options like price, special and customer also bought items dynamic		
int main(int argc, char* argv[])
{
	int n_prods, i;
	int i_Sys_Type = 0;	 //0 for Linux, 1 for Windows        //Added by GSK  

	// Check syntax
	//if (argc < 2)
	//if (argc < 3)    //Changed by GSK
	if (argc < 4)    //Changed by WDB	
	{
		//fprintf(stderr, "Syntax: ds2_create_prod n_prods\n");
		fprintf(stderr, "Syntax: ds2_create_prod n_prods n_Sys_Type n_output_file\n");  //Changed by GSK
		fprintf(stderr, "n_prods number of products to generate\n"); //Added by WDB		
		fprintf(stderr, "n_Sys_Type can be 0 (Linux) or 1 (Windows)\n"); //Added by GSK  		
		fprintf(stderr, "n_output_file the file name or just a file path you wish to output prod.csv to\n");
		exit(-1);
	}

	n_prods = atoi(argv[1]);
	i_Sys_Type = atoi(argv[2]);    //Added by GSK
	strcpy(output_file,argv[3]); //Added by WDB

	char* pch;
	pch = strstr(output_file,".csv");

	if(pch == NULL)//if the string doesn't end in .csv
	{
		if(( '/' != output_file[ strlen(output_file) - 1 ] ) && ( '\\' != output_file[ strlen(output_file) - 1 ] ))//if the string doesn't end in a backslash
		{
			strcat(output_file,"/prod.csv");
		}
		else
		{
			strcat(output_file,"prod.csv");
		}
	}
	{
		FILE *fp;  
		fp=fopen(output_file, "w+");

		for (i = 0; i < n_prods; i++)
		{
			prod_id = i+1;

			// Generate a category up to the maximum
			category = random2(1, MAX_CATEGORY);
			// Generate 1M unique titles from 1000 title words selected 2 at a time
			sprintf(title, "%s %s", movie_titles[random2(1, 999)], movie_titles[random2(1, 999)]);

			// Generate 40,000 actor names from randomly selecting from 200 first names x 200 last names
			sprintf(actor, "%s %s", actor_firstnames[random2(0, 199)], actor_lastnames[random2(0, 199)]);
			
			// Generate a price between $9.99 and $29.99 ($9.99, $10.99, etc.)
			price = 0.99 + random2(9, 29);

			// For catalogs of less than 100,000 items select 1 item in 100 as Specials
			// For catalogs of 100,000 items or more select 1 item in 10,000 as Specials
			if (n_prods>100000) special = (10000 == random2(1, 10000));
			else  special = (100 == random2(1, 100));

			// Select another prod_id that customers bought who bought this one
			common_prod_id = random2(1, n_prods);
			fprintf(fp,"%d,%d,%s,%s,%5.2f,%d,%d\n", prod_id, category, title, actor, price, special, common_prod_id);
			//commented out for now since it follows the same code path for both linux and windows
			//this is only valid if you are compiling this on windows with GCC
			//I will make a valid change for both windows and linux if you want to compile this on linux.
			// if(i_Sys_Type == 0)   //If System is Linux, Append LF only    //Added by GSK
			// {	
				// fprintf(fp,"%d,%d,%s,%s,%5.2f,%d,%d\n", prod_id, category, title, actor, price, special, common_prod_id);
			// }	
			// else if(i_Sys_Type == 1) //If System is Windows, Append CR+LF   //Added by GSK   //Don't need the \r\n just \n on windows
			// {
				// fprintf(fp,"%d,%d,%s,%s,%5.2f,%d,%d\r\n", prod_id, category, title, actor, price, special, common_prod_id);
			// }
		} //end for
		fclose(fp);
	}// end file
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
