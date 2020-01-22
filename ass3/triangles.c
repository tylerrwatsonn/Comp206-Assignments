//Tyler Watson 260867260

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char **argv)
{
   int size; 			//initialize size variable
   if (argc > 1) {		//true if there are arguments with the script command
   if (atoi(argv[1]) <= 0) {	//check if arg is greater than 0
	   printf("%s", "An incorrect triangle size was inputted. The size must be greater than 0 and an integer number. Syntax: ./triangles SIZE\n");
	return 1;		
   }
   
   if (atoi(argv[1]) > 0) {	//if arg is greater than 0 then change size to the arg
	size = atoi(argv[1]);

   }
   }
   else {			//if no arguments
	puts("Please input a number greater than 0.");
	scanf("%d", &size);	//wait for input
	if(size<=0) {		//if input is less than 0 throw error
           printf("%s", "An incorrect triangle size was inputted. The size must be greater than 0 and an integer number. Syntax: ./triangles SIZE\n");
        return 1;
	}
   } 
   int i;			
   for(i=0; i<=size; i++) {	//for loop to display triangle
	int j;
	for(j=0; j<size-i; j++) printf(" ");	//for loop to display first spaces
	for(j=0; j<i; j++) printf("*");		//for loop to display *
	puts("\n");				//new line
   }
   return 0;
}
