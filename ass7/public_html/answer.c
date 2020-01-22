#include <stdlib.h>
#include <stdio.h>
#include <string.h>




int main(int argc, char* argv[]) {
	char * input = getenv("inputText");

	FILE * fp = fopen("index.html", "a");
	fprintf(fp, "<a href=\"http:www.google.com\">Press HERE to go North</a>");

	if(!strcmp(input, "NORTH")) {

		fprintf(fp, "<a href=\"http:www.google.com\">Press HERE to go North</a>");
	}
	
	else if(!strcmp(input, "SOUTH")) {
		printf("<a href=\"http:www.google.com\">Press HERE to go South</a>");
	}
	else if(!strcmp(input, "EAST")) {
		printf("<a href=\"http:www.google.com\">Press HERE to go East</a>");
	}
	
	else if(!strcmp(input, "WEST")) {
		printf("<a href=\"http:www.google.com\">Press HERE to go West</a>");
	}

	else if(!strcmp(input, "GOLD")){
		printf("<a href=\"http:www.google.com\">Press HERE to see your gold</a>");
	}

	else {
	}

	
}
