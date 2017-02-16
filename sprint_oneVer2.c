 /************************************************
  *  Mastermind:   PO2 Dugas-Davis, Maxime	 *
  *  Created:      02JAN2017			 *
  *  Last Edited:  1FEB2017 11:48:22		 *
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


//FUNCTIONS TO BE USED ;P
void UserMenu();
char phishy(char username, int score);
char consonantfunky(char *consonantsearch);
char vowelfunky(char *vowelsearch);
int randnumfunky(int usernum);
int codenamescorer(char *cusername);

int main (int argc, char *argv[])
{
	FILE *fp;	

	char *carr1 = argv[1];
	char *carr2 = argv[2];
	char cnewline[] = "\n";
	char ctab[] = "\t";
	char cunderline[] = "_";
	char ciscoreis[] = "Your score is: ";	
	//char buf[50];
	char cvalidnumfavnum[] = "0123456789";
	//char stringy[] = "WHAT?!";
	char cbad_chars[] = "!@%^*~|";
	//char buffer[100];
	char cfirstname[100]; 	//= "Maxime";//"Dalton";//"Charlie";
	char clastname[100];	//= "Dugas-Davis";//"Shaadt";
	char cfavcolor[100];	//= "Green";//"Purple";
	char cfirstcar[100]; 	//= "Chevy";//"Toyota";
	char cfavnum[20];	//= "9";	
	char cusername[20];	
	char ctoalphaifinalnum[20];
	char ctoalphaiscore[20];

	int icounter 		= 0; //counter, set to 0.
	int iNameGood 		= 0;
	int ifinalnum		= 0;
	int iscore		= 0;
	int ichecker = 0;	
	//int numbytes;

	//Break Points are for error checking
	//printf ( "\n***Break Point #1***\n" );

	//Checks to see if correct number of arguments are inputted.
	if ( argc == 3 ) 
	{
		printf ( "Arguments supplied are as follows: filename '%s' and option '%s'. \n", carr1, carr2 );
		printf ( "Good Job! You have a basic reading comprehension. **Clap** **Clap** **Clap**\n" );
		system("clear");
		//printf ( "\n***Break Point #2***\n" );				
		
		//Checks to see if user inputs "bad characters in .txt name".
		for ( int i = 0; i < strlen ( carr1 ) && ichecker != 1; ++i ) 
		{
			for( int j = 0; j < strlen( cbad_chars ); ++j)
			{
				if ( cbad_chars[i] == carr1[j] ) 
				{
					printf( "\nWRONG! You may not enter the following characters for your file name:\n" );
					printf( "\nPew* Pew* Pew*! ---> " );							
					printf( "\t%s", cbad_chars );			
					ichecker = 1;
					UserMenu();
					break;
				}	
			}
		}
		
		//checks for s or n entered in argv[2], if neither are found it goes to the user menu
		if ( *carr2 != 's' && *carr2 != 'n' )
		{
			printf ( "Your input is invalid, just like your life!\n" );
			//printf ( "\n***Break Point #***\n" );
			UserMenu ( );
			exit ( 3 );
		}
		if ( *carr2 == 's' )
		{
			printf ( "\nYour results will be saved for posterity. Contratulations, you're a hoarder.\n" );
			printf ( "\n" );
			
			//*********************************************Check Point***************************************************
			//Takes in 5 things from user: fn, ln, fc, first car make, and favorite number.			
			//Take in a First Name
			printf ( "Enter your first name: \n" );
			fgets ( cfirstname, 100, stdin );
			//buffer[strcspn(buffer, "\n")] = 0;
			printf ( "\n" );

			//Take in a Last Name
			printf("Enter your last name: \n");
			fgets(clastname, 100, stdin);
			printf ( "\n" );

			//Take in a favcolor
			printf("Enter your favorite color: \n");
			fgets(cfavcolor, 100, stdin);
			printf ( "\n" );

			//Take in a first car
			printf("Enter your first car make: \n");
			fgets(cfirstcar, 100, stdin);
			printf ( "\n" );

			//Convaluted way of making sure user inputs numbers 0-9
			do{
			printf("Enter your favorite number: \n");
			fgets(cfavnum, 20, stdin);
			printf ( "\n" );

			if(*cfavnum != cvalidnumfavnum[0] && *cfavnum != cvalidnumfavnum[1] && *cfavnum != cvalidnumfavnum[2] && *cfavnum != cvalidnumfavnum[3] && *cfavnum != cvalidnumfavnum[4] && *cfavnum != cvalidnumfavnum[5] && *cfavnum != cvalidnumfavnum[6] && *cfavnum != cvalidnumfavnum[7] && *cfavnum != cvalidnumfavnum[8] && *cfavnum != cvalidnumfavnum[9])
				{
					printf("Your favorite number is invalid, like your life.\n\n");
				}
			}while(*cfavnum != cvalidnumfavnum[0] && *cfavnum != cvalidnumfavnum[1] && *cfavnum != cvalidnumfavnum[2] && *cfavnum != cvalidnumfavnum[3] && *cfavnum != cvalidnumfavnum[4] && *cfavnum != cvalidnumfavnum[5] && *cfavnum != cvalidnumfavnum[6] && *cfavnum != cvalidnumfavnum[7] && *cfavnum != cvalidnumfavnum[8] && *cfavnum != cvalidnumfavnum[9]);

			//Calls consonant/vowel functions to find first consonant/vowel in fn, ln, fc, and first make. To make username.
			//printf("\n***Break Point 2. Before calculations and printf statements.***\n");
			cusername[0] = consonantfunky(cfirstname);
			cusername[1] = vowelfunky(clastname);
			cusername[2] = consonantfunky(cfavcolor);
			cusername[3] = vowelfunky(cfirstcar);

			//Strip newline from fgets and username array to prevent strange characters "?"
			cusername[5] = sizeof(cusername - 1);

			//Adds random number to users favorite number to make username
			ifinalnum = randnumfunky(cfavnum[0]);
	
			//printf("\n%d\n", ifinalnum);

			printf("\n\nYour fancy username is: %s_%d\n", cusername, ifinalnum);

			//calls scorer to grade username based on ascii value
			iscore = codenamescorer(cusername);

			//printf("Break Point 3. Before file io.\n");
	
			printf ( "\n***Your cool points, for having such an amazing username are: %d   ***\n\n", iscore );

			//printf("\n***Break Point 6. RIGHT BEFORE RETURN (0); OOOH WEEE!***\n");

			printf ( "\n" );
			//********************************************Check Point****************************************************

			//Save Cool Points into a variable
			//Save both Username and Cool Points into File yo.
	
			fp = fopen ( carr1, "a" );
			//fputs ( cusername, fp );
			//ssize_t pwrite( fp, cusername, strlen(cusername) );
			//ssize_t pwrite( fp, "\n", strlen(cusername) );
			//fputs ( "_", fp );
			//fputs ( "\n ", fp);
			ctoalphaifinalnum[0] = ifinalnum;
			ctoalphaiscore[0] = iscore;
			//fputs ( ctoalphaifinalnum, fp );
			//fputs ( ctoalphaiscore, fp );			

			fwrite ( cusername, sizeof (char), 3, fp );
			fputs ( cunderline, fp );
			//fwrite ( ifinalnum, sizeof (int), 3, fp );
			fputs ( ctab, fp ); 
			//fwrite ( iscore, sizeof (int), 3, fp );
			fputs ( cnewline, fp );

			//printf( "\n>>> %i ... %i <<<", ifinalnum, iscore );

			//printf ( "\n***Break Point #***\n" );
			//if file is open close it.
			if ( fp )
			{
				fclose ( fp );
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
	else if ( argc < 3 ) 
	{
		printf ( "Too few arguments supplied. Learn how to count. Anti-Nerd.\n" );
		UserMenu();
		//printf ( "\n***Break Point ***\n" );	
	}
	else if ( argc > 3 )
	{
		printf ( "Too many arguments supplied. Less is more.\n" );
		UserMenu();	
		//printf ( "\n***Break Point 4***\n" );	
	}

	printf ( "\n" );
	//printf ( "\n***Break Point #***\n" );
	return ( 0 );

}
//If user doesn't get it by sheer intuition alone, print this "helpful" menu
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

	//Sleep and clear added for fancy effects
	sleep(10);
	system("clear");
	
	exit(0);
}
//		****************************************Check Point******************************************************
	

//Searches FN and FC for first consonant found. Took me an embarrasing amount of time to figure this out.
char consonantfunky(char *consonantsearch)
{
	char cconsonantcheck[]  = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
	char cusername[50];
	int  icheck 	        = 0;


	for(int i = 0; i < (strlen(consonantsearch)-1) && icheck != 1; i++)
	{
		for(int j = 0; j < strlen(cconsonantcheck); j++)
		{
			if(consonantsearch[i] == cconsonantcheck[j])
			{
				cusername[0] = consonantsearch[i];
				icheck = 1;
				break;
			}
		}
	}
	
	return(cusername[0]);
}

//Same thing as consonant funtion, only for vowels in LN and Make
char vowelfunky(char *vowelsearch)
{

	char cvowelcheck[]  = "aeiouAEIOU";
	char cusername[50];
	int  icheck 	    = 0;


	memset(cusername, 0, sizeof(cusername));

	for(int i = 0; i < (strlen(vowelsearch)-1) && icheck != 1; i++)
	{
		for(int j = 0; j < strlen(cvowelcheck); j++)
		{
			if(vowelsearch[i] == cvowelcheck[j])
			{
				cusername[0] = vowelsearch[i];
				icheck = 1;
				break;
			}
		}
	}
	

	return(cusername[0]);
}

//random number generator to add to user petty and lame favorite number. My fav number is clearly superior, as I am a hipster and don't have one...
int randnumfunky(int usernum)
{

	int irandnum = 0;

	srand(time(NULL));			//Seed srand with time so that I can add random num to luckynum.
        
	irandnum = rand() % 50;	

	usernum = usernum + irandnum;
	
	return usernum;
	
}

//scores 4 letter user/secret agent name thingy by adding ascii values together.
int codenamescorer(char *cusername)
{

	//char stringy[] = cusername;
	//printf("%s", cusername);
	int ordinalval = 0;
	int score = 0;

	//Assign ordinal value to an int
	//For loop, to loop through string for strlen (length of string)
	//Add each letter's ordinal value to an int
	for(int i = 0; i < strlen(cusername); i++)
	{
		ordinalval = cusername[i];
		score += ordinalval;
		//printf(" %c", ordinalval);
	}

	//return ascii values of each character, all added together.
	return score;

}
//gcc -o um UserMenu_Ver0.c phishy phishy_Ver0.c uio userinoutput_Ver0.c
