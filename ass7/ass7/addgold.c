//Tyler Watson 260867260


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char * input = getenv("QUERY_STRING");	//get query string	
	char * token = strtok(input, "=");
	char * goldpieces = strtok(NULL, "&");	//get gold value

	FILE * f = fopen("../index.html", "rt");	
	char line[1000] = "";
	printf("Content-Type:text/html\n\n");

	if (f==NULL) {
		printf("<html>");
		printf("<head><title>ERROR</title></head>");
		printf("<body><p>Unable to open file!</p></body>");
		printf("</html>");
	}
	else	//iterate through all the lines f the file and print them to the browser
	{
	while(!feof(f)) {
		fgets(line, 1000, f);
		if(!strcmp(line, "</form>\n")) {	//this is where to add the hidden tag
			//printf("<p>GOLD = %s</p>",goldpieces );
			printf("<input type=\"hidden\" name=\"gold\" value=\"%d\">", atoi(goldpieces));		
			//printf("<input name=\"gold\" style=\"width: 500px;\" placeholder=\"Please type NORTH, SOUTH, EAST, WEST, GOLD,or answer the question\">");
		}
	       	printf("%s\n", line);
		
	}
	fclose(f);
	
}
}
