 /************************************************
  *  Mastermind:   PO2 Dugas-Davis, Maxime	 *
  *  Created:      02JAN2017			 *
  *  Last Edited:  14FEB2017 07:11:22		 *
  *  Purpose:      Take in user input and modify *
  *  it to create a username (SECRET AGENT NAME!)* 
  *  will save results to a file. Peace!	 *
  ************************************************/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "UserMenu.h"

void UserMenu();

int main (int argc, char *argv[])
{
	FILE *fp;	

	char *carr1 = argv[1];
	char *carr2 = argv[2];
	char stringy[] = "WHAT?!";
	char bad_chars[] = "!@%^*~|";
	int checker = 0;	

	printf ( "\n***Brk Pt. #1***\n" );

	if ( argc == 3 ) 
	{
		printf ( "Arguments supplied are as follows: filename '%s' and option '%s'. \n", carr1, carr2 );
		printf ( "Good Job! You have a basic reading comprehension. **Clap** **Clap** **Clap**\n" );
		system("clear");
		printf ( "\n***Brk Pt. #2***\n" );				
		
		for ( int i = 0; i < strlen ( carr1 ) && checker != 1; ++i ) 
		{
			for( int j = 0; j < strlen( bad_chars ); ++j)
			{
				if ( bad_chars[i] == carr1[j] ) 
				{
					printf( "\nWRONG! You may not enter the following characters for your file name:\n" );
					printf( "\nPew* Pew* Pew*! ---> " );							
					printf( "\t%s", bad_chars );			
					checker = 1;
					UserMenu();
					break;
				}	
			}
		}
		
		
		if ( *carr2 != 's' && *carr2 != 'n' )
		{
			printf ( "Your input is invalid, just like your life!\n" );
			printf ( "\n***Brk Pt. #9***\n" );
			UserMenu();
			exit(3);
		}
		if ( *carr2 == 's' )
		{
			printf( "\nYour results will be saved for future viewing. Contratulations, you're a hoarder.\n" );
			
	
			//Call function for phishing
			//Save username into a variable
				//Within username call consonant and vowel check functions and randum number generator
			//Call cool calculator
			//Save Cool Points into a variable
			//Save both Username and Cool Points into File yo.
	
			fp = fopen ( carr1, "a" );
			fputs ( stringy, fp );
			printf ( "\n***Brk Pt. #9***\n" );
			if ( fp )
			{
				fclose(fp);
			}
			else
			{
				printf("\nArr, there be nothing to close.\n");
			}
		
		}
		else if ( *carr2 == 'n' )
		{
			printf("\nYou have chosen to do nothing, just like you do in life. Nothing will be saved.\n");
			//UserMenu();
		}
	
	}
	if ( argc < 3 ) 
	{
		printf ( "Too few arguments supplied. Learn how to count. Anti-Nerd.\n" );
		UserMenu();
		printf ( "\n***Brk Pt. #3***\n" );	
	}
	if ( argc > 3 )
	{
		printf ( "Too many arguments supplied. Less is more.\n" );
		UserMenu();	
		printf ( "\n***Brk Pt. #4***\n" );	
	}

	

	printf ( "\n" );
	printf ( "\n***Brk Pt. #11***\n" );
	return ( 0 );

}

void UserMenu()
{
	system("clear");

	printf("\n\n");	

	printf("------------------------------------------------------------------------------------------\n");
	sleep(2);	
	printf("|\t\t\t\t\t\t\t\t\t\t\t |\n");	
	sleep(2);
	printf("|\t***End goal, find your super-duper SECRET agent (user) name.***\t\t\t |");
	printf("\n");
	sleep(2);
	printf("|\t\t\t\t\t\t\t\t\t\t\t |\n");
	sleep(2);
	printf("| -Enter a VALID file name in which you would like to save your results.\t\t |\n");
	sleep(2);
	printf("| -Please only enter: 's' to save results' or 'n' to do nothing.'\t\t\t |\n");
	sleep(2);
	printf("| -No special characters (!@#$%, etc.) will be accepted. They will be shot on sight.\t | \n");
	sleep(2);
	printf("|\t\t\t\t\t\t\t\t\t\t\t |\n");
	sleep(2);
	printf("|\t\tFormat of input: 'OMGmyfilenamegoesherr.txt, s'\t\t\t\t |\n");
	sleep(2);
	printf("|\t\t\t\t\t\t\t\t\t\t\t |\n");
	sleep(2);
	printf("------------------------------------------------------------------------------------------\n");

	printf("\n");

	sleep(10);
	system("clear");
	
	exit(0);
}

//gcc -o um UserMenu_Ver0.c phishy phishy_Ver0.c uio userinoutput_Ver0.c
