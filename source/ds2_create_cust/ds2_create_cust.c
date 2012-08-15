/*
* DVD Store 2 Create Customer data - ds2_create_cust.c
*
* Copyright (C) 2005 Dell, Inc. <dave_jaffe@dell.com> and <tmuirhead@vmware.com>
*
* Creates customer data files for DVD Store Database V.2
* Syntax: ds2_create_cust n_first n_last region_str S|M|L n_Sys_Type > output_file
*         (see details below)
* Run on Linux to use large RAND_MAX (2e31-1)
* To compile: gcc -o ds2_create_cust ds2_create_cust.c -lm
* Last Updated 5/12/05
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
#include <time.h>

#include "ds2_data.h"

#define MAX_PROD_ID_SMALL 10000
#define MAX_PROD_ID_MED   100000
#define MAX_PROD_ID_LARGE 1000000

// Functions
int random2(int i, int j);
double random2d(double i, double j);

main(int argc, char* argv[])
{
	int n_first, n_last, adder=0, max_prod_id;
	char* ind;
	char n_first_str[20], n_last_str[20], region_str[3], size;
	int i, j, m, k, i_user, n_prev_orders;
	int customerid, street_index, firstname_index, lastname_index, city_index, domain_index, state_index, country_index
	, zip, region, creditcard_type, i_month, i_year, age, income;
	double phone, creditcard;
	char	firstname[50], lastname[50], city[50], state[50], country[50], creditcard_exp[25], domain_name[50] ,
	username[100], password[25], address[150], gender[5], street_name[50], email[150], output_file[250];

	int i_Sys_Type = 0;	//0 for Linux, 1 for Windows        //Added by GSK
	char str_Sys_Type[20]; //Added by GSK

	// Check syntax
	//if (argc < 5)
	//if (argc < 6)     //Changed By GSK
	if (argc < 7)     //Changed By WDB added output_file_name command line arg if empty goes to console
	{
		fprintf(stderr, "Syntax: ds2_create_cust n_first n_last region_str S|M|L n_Sys_Type output_file\n");  //Changed Syntax by GSK
		fprintf(stderr, "        where n_first, n_last can contain M or m for millions\n");
		fprintf(stderr, "        the M or m can be followed by a +n\n");
		fprintf(stderr, "Creates customer data files for DS2 database\n");
		fprintf(stderr, "Region_str can be US or ROW\n");
		fprintf(stderr, "S,M,L uses product ids up to %d, %d, and %d, respectively\n", 
		MAX_PROD_ID_SMALL, MAX_PROD_ID_MED, MAX_PROD_ID_LARGE);
		fprintf(stderr, "n_Sys_Type can be 0 (Linux) or 1 (Windows)\n");		//Changed Syntax by GSK    
		fprintf(stderr, "Examples: ds2_create_cust  1 1000  US  S 0  =>  US custs        1 -> 1000\n");
		fprintf(stderr, "          ds2_create_cust    1 1M  US  L 0  =>  US custs        1 -> 1000000\n");
		fprintf(stderr, "          ds2_create_cust 1M+1 2M  ROW L 0  =>  ROW custs 1000001 -> 2000000\n");
		exit(-1);
	}

	strcpy(n_first_str,  argv[1]);
	if (!(ind = strpbrk(n_first_str, "Mm")))
	{ 
		n_first = atoi(n_first_str);
	}
	else
	{
		if (*(ind+1) == '+') adder = atoi(ind+2);
		*ind = '\0';
		n_first = 1000000 * atoi(n_first_str) + adder;
	}

	strcpy(n_last_str,  argv[2]);
	adder = 0;
	if (!(ind = strpbrk(n_last_str, "Mm")))
	{ 
		n_last = atoi(n_last_str);
	}
	else
	{
		if (*(ind+1) == '+') adder = atoi(ind+2);
		*ind = '\0';
		n_last = 1000000 * atoi(n_last_str) + adder;
	}
	strcpy(region_str, argv[3]); 
	size = toupper(argv[4][0]);

	strcpy(str_Sys_Type,argv[5]);                //Added by GSK
	i_Sys_Type = atoi(str_Sys_Type);             //Added by GSK
	strcpy(output_file,argv[6]);				 //Added by WDB

	char* pch;
	pch = strstr(output_file,".csv");
	
	if(pch == NULL)//if the string doesn't end in .csv
	{
		if(( '/' != output_file[ strlen(output_file) - 1 ] ) && ( '\\' != output_file[ strlen(output_file) - 1 ] ))//if the string doesn't end in a backslash
		{
			strcat(output_file,"/cust.csv");
		}
		else
		{
			strcat(output_file,"cust.csv");
		}
	}

	switch (size)
	{
	case 'S':
		max_prod_id = MAX_PROD_ID_SMALL;
		break;
	case 'M':
		max_prod_id = MAX_PROD_ID_MED;
		break;
	case 'L':
		max_prod_id = MAX_PROD_ID_LARGE;
		break;
	}

	srand(n_first); // Seed rand() with n_first
	{
		FILE *fp;  
		fp=fopen(output_file, "w+");

		for (i=n_first; i<=n_last; i++) 
		{
			//added by WDB
			//generates a first name from the actors name list to generate a more realiztic name
			firstname_index    = random2(0, 199);
			strcpy(firstname,actor_firstnames[firstname_index]);

			//added by WDB
			//generates a last name from the actors name list to generate a more realiztic name
			lastname_index    = random2(0, 199);
			strcpy(lastname,actor_lastnames[lastname_index]);

			//added by WDB
			//pulls from the new city corpus to generate a more realiztic city state combination
			city_index    = random2(0, 99);
			strcpy(city,customer_city_names[city_index]);
			
			if (strncmp(region_str,"US", 2) == 0)
			{
				region = 1;
				state_index    = random2(0, 50);
				strcpy(state,states[state_index]);
				strcpy(country,"US");
				zip = random2(10000, 99999); 
			}
			else 
			{
				region = 2;
				country_index  = random2(0,9);
				strcpy(country,countries[country_index]);
				strcpy(state,"");
				zip = 0;
			} //End Else
			
			customerid     =  i;
			
			//TODO: add a valid phone number generator
			phone          =  random2d(1000000000, 9999999999);

			//TODO: add valid credit card number generator
			creditcard_type =  random2(1,5);
			creditcard      =  random2d(1000000000000000, 9999999999999999);
			
			//TODO:increase range or make a commad line parameter for the start and range
			i_year  = 2007 + random2(1, 5);
			i_month = random2(1, 12);
			sprintf(creditcard_exp,"%4d/%02d", i_year, i_month);
			
			//added by WDB
			//this pulls from the new street name corpus and genrates a more realistic street address
			street_index    = random2(0, 321);
			sprintf(street_name,"%d",random2(128,99999));
			strcat(street_name," "); 
			strcat(street_name,	street_names[street_index]);
			sprintf(address,street_name, phone);      

			//added by WDB
			//this pulls from the new domain name corpus and genrates a more realistic email address
			strcpy(domain_name,firstname);
			strcat(domain_name,lastname);
			domain_index = random2(1,9999);
			sprintf(email,"%s%d",domain_name,domain_index);
			strcat(email,"@");
			domain_index    = random2(0, 199);
			strcat(email,customer_domain_names[domain_index]);

			//TODO: come up with a better algorithmic method for generating user id's 
			sprintf(username, "user%d", i);

			//TODO: come up with a better password scheme that is usable by the
			//load generator. A simple algorithim probably
			strcpy(password, "password");  
			
			//TODO: make a command line parameter for age range and base
			age  = random2(18, 90); // 18 - 90 yrs of age
			
			income  = 20000*random2(1, 5); // >$20,000, >$40,000, >$60,000, >$80,000, >$100,000

			if (random2(0,1)) strcpy(gender, "M");
			else strcpy(gender, "F");
		
			fprintf(fp, "%d,%s,%s,%s,,%s,%s,%05d,%s,%1d,%s,%10.0f,%1d,%16.0f,%s,%s,%s,%d,%d,%s\n",
			customerid, firstname, lastname, address, city, state, zip, country, region, email, phone, creditcard_type, 
			creditcard, creditcard_exp, username, password, age, income, gender);

			//commented out for now since it follows the same code path for both linux and windows
			//this is only valid if you are compiling this on windows with GCC
			//I will make a valid change for both windows and linux if you want to compile this on linux.
			// if(i_Sys_Type == 0)   //If System is Linux, Append LF only    //Added by GSK
			// {	
				// fprintf(fp, "%d,%s,%s,%s,,%s,%s,%05d,%s,%1d,%s,%10.0f,%1d,%16.0f,%s,%s,%s,%d,%d,%s\n",
				// customerid, firstname, lastname, address, city, state, zip, country, region, email, phone, creditcard_type, 
				// creditcard, creditcard_exp, username, password, age, income, gender);
			// }	
			// else if(i_Sys_Type == 1) //If System is Windows, Append CR+LF   //Added by GSK
			// {
				// fprintf(fp, "%d,%s,%s,%s,,%s,%s,%05d,%s,%1d,%s,%10.0f,%1d,%16.0f,%s,%s,%s,%d,%d,%s\r\n",
				// customerid, firstname, lastname, address, city, state, zip, country, region, email, phone, creditcard_type, 
				// creditcard, creditcard_exp, username, password, age, income, gender);	
			// }

		} //End of For
		fclose(fp);
	}
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
//---------------------------------------random2d---------------------------------------
//
// random2d(i,j) - returns a random double uniformly distributed between i and j,
//  inclusively  (assumes j >= i)                        
//
double random2d(double i, double j)
{
	return i + floor((1+j-i) * (double) rand()/(((double) RAND_MAX) + 1));
} //random2
//

