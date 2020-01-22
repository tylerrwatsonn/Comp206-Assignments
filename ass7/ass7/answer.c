#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Tyler Watson 260867260


int main(int argc, char* argv[]) {
	char * input = getenv("QUERY_STRING");	//obtatin the query string from the get request
	printf("Content-Type:text/html\n\n"); // CGI output tag
	printf("<html>");
	printf("<head><title>Next Room Link</title></head>");
	printf("<body>");
	char * token = strtok(input, "="); //get to char before command
	char * command = strtok(NULL, "&"); //get value of command
	int goldPieces = 0;	//initialize gold pieces to 0
	char * nextToken = strtok(NULL, "=");	
	char * goldValue = strtok(NULL, "");	//get value of gold
	if(goldValue == NULL) goldPieces = 10;	//if there is no value, then the gold is 10 pieces
	else { 	//if there is a value, convert it to integer and set goldPieces to goldValue
		goldPieces = atoi(goldValue);
	}
	
	//handle direction commands	
	if(!strcmp(command, "NORTH")) {
		printf("<a href=\"https://www.cs.mcgill.ca/~cbourb5/cgi-bin/addgold.cgi?gold=%d\">Press HERE to go North</a>", goldPieces);
	}
	
	else if(!strcmp(command, "SOUTH")) {
		printf("<a href=\"https://www.cs.mcgill.ca/~aporpo/cgi-bin/addgold.cgi?gold=%d\">Press HERE to go South</a>", goldPieces);
	}
	else if(!strcmp(command, "EAST")) {
		printf("<a href=\"https://www.cs.mcgill.ca/~bromer2/cgi-bin/addgold.cgi?gold=%d\">Press HERE to go East</a>", goldPieces);
	}
	else if(!strcmp(command, "WEST")) {
		printf("<a href=\"https://www.cs.mcgill.ca/~fsimar6/cgi-bin/addgold.cgi?gold=%d\">Press HERE to go West</a>", goldPieces);
	}

	else if(!strcmp(command, "GOLD")){ //if player wants to see their gold

		if(goldValue == NULL) printf("<input type=\"hidden\" name=\"gold\" value=\"10\">");
		printf("<center style=\"font-family: American Typewriter, serif; font-size: 115pt; font-style:italic, bold\">GOLD: %d</center>", goldPieces);
		printf("<a href=\"https://www.cs.mcgill.ca/~twatso5/cgi-bin/addgold.cgi?gold=%d\">Press HERE to return to current room</a>", goldPieces);
	}


	else {	//check for correct answer
		if(!strcmp(command, "pre-processed")) {	//correct answer
			goldPieces = goldPieces + 10;
			printf("<b>CORRECT! </b>");
		}
		else {	//wrong answer
			goldPieces = goldPieces - 5;
			printf("<b>INCORRECT! </b>");
		}
		//check loss/win conditions
		if(goldPieces <= 0) printf("<b>YOU LOSE!</b>");				//game lost
		else if(goldPieces >= 100) printf("<b>YOU WIN!!!!</b>");		//game won
		//if game continues, redirect back to my page to choose direction
		else printf("<a href=\"https://www.cs.mcgill.ca/~twatso5/cgi-bin/addgold.cgi?gold=%d\">Press HERE to go back and pick a direction</a>", goldPieces);
	}
	printf("<body>");
	printf("</html>");

	
}

