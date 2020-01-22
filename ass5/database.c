//Tyler Watson 260867260 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


// char* splitString( char* string) {
//     char* result[];
//     int i=0;
//     for(int j; j<4; j++){
//         char* element = "";
//             while(string[i] != ',') {
//                 if(isalnum(string[i])) strcat(element, string[i]);
//             }
//         result[j] = element;
//     }
// }

struct ENTRY {
    int ID;
    char name[20];
    int age;
    float GPA;
} entries[1000];

int entLength =0;

void buildStructures(FILE *file) {
    int i;
    char ch; //search file char by char
    int count=0;
    while(!feof(file)) { //while  not end of file
      char line[50] = ""; //string for each line of the csv file
      fgets(line, 50, file); // read one string into line
        struct ENTRY e;
	char temp1[20]="";	//string for ID
        for(i=0; i<strlen(line); i++) {	//for loop for ID
            ch = line[i]; //obtain char of line
            if(ch == ',') break; //stop the for loop once we reach a comma
            else if(ch == ' ') continue; //simply skip over the spaces
            else if(isdigit(ch)) strncat(temp1, &ch, 1);
        }
	e.ID=atoi(temp1);	//chang ID to int and set the ID of the entry
	i+=1;	//go to index just past ','
        char temp2[20]="";	//string for name
	for(i=i; i<strlen(line); i++) { //for loop for name
	    ch = line[i];
            if(ch == ',') break;
	    else if(ch == ' ') continue;
            else if(isalpha(ch)) {	//heck if the char is a letter
		    strncat(temp2, &ch, 1);
	    }
	    }
	strcpy(e.name, temp2);
	i+=1;
        char temp3[20]="";	//sting for age
        for(i; i<strlen(line); i++) { //for loop for age
            ch = line[i];
            if(ch == ',') break;
            else if(ch == ' ') continue;
            else if(isdigit(ch)) strncat(temp3, &ch, 1);
        }
        e.age=atoi(temp3);
	i+=1;
        char temp4[20]="";
        for(i; i<strlen(line); i++) { //for loop for GPA
            ch = line[i];
            if(ch == ',') break;
            else if(ch == ' ') continue;
            else if(isdigit(ch) || ch=='.') strncat(temp4, &ch, 1);	//include '.'
        }
        e.GPA=atof(temp4);
	entries[count]=e;	//add struct entry to entries array
        count+=1;	//increase index of entries
 	entLength = count;
    }
    
}

void show (FILE *file) {
    buildStructures(file);	//build entry structures
    for(int i=0; i<entLength; i++) {
        struct ENTRY e = entries[i];
        printf("Record %2d: ID=%-5d NAME=%-7s AGE=%-2d GPA=%1.1f\n",i, e.ID, e.name, e.age, e.GPA);
    }
}

void addEntry(FILE *file, int ID, char* name, int age, float GPA) {
	entLength += 1;
	fprintf(file, "%d,%s,%d,%1.1f\n", ID, name, age, GPA);
}

void deleteEntry(FILE *file, int ID) {
    FILE *tmp;
    tmp=fopen("database.tmp", "w");
    int exists=0;
    while(!feof(file)) {  //while  not end of file
	    char line[50] = "";
      fgets(line, 50, file); // read one string into line
      char id[20]="";
      char ch;
      for(int i=0; i<strlen(line); i++) {            
        ch = line[i];
        if(ch == ',') break;
        else if(ch == ' ') continue;
        else if(isdigit(ch)) strncat(id, &ch, 1);
      }
      if(atoi(id) == ID) {
	      exists=1;
      }
      else {
          fputs(line,tmp);
      }
    }
    remove("database.csv");
    rename("database.tmp", "database.csv");
    if(!exists) printf("Sorry, that user was not found. Nothing was deleted.");
    else entLength -= 1;
}


void uppercase(char s[]) {
	for(int i=0; s[i]!='\0'; i++){ 
		s[i]=toupper(s[i]);
	}
}

int main(int argc, char* argv[]) {
    FILE *fp;
    fp=fopen("database.csv", "r+");
    if(argc == 1) {
	    printf("You did not provide any arguments. Please enter: ./database CMD OPT1 OPT2 OPT3 OPT4\n");
	    return 1;
    }
    char CMD[10];
    int ID = -1;
    char name[15];
    int age = -1;
    float GPA=0.0;
    sscanf(argv[1], "%s", CMD);
    uppercase(CMD);
    if(strcmp(CMD, "SHOW") == 0) {
    	fp=fopen("database.csv", "r");
	show(fp);
	fclose(fp);
    }
    else if(strcmp(CMD, "DELETE") == 0) {    
    	fp=fopen("database.csv", "r+");
	if(argc > 2) sscanf(argv[2], "%d", &ID);
	if(ID == -1) {
		printf("Name of record to delete is missing.\n");
		return 1;
	}
	deleteEntry(fp, ID);
	fclose(fp);
    }
    else if(strcmp(CMD, "ADD") == 0) {
    	fp=fopen("database.csv", "a");
	if (argc < 6) {
		printf("Missing ID, Name, AGE, and GPA arguments.\n");
		return 1;
	}
	sscanf(argv[2], "%d", &ID);
	sscanf(argv[3], "%s", name);
	sscanf(argv[4], "%d", &age);
	sscanf(argv[5], "%f", &GPA);
	addEntry(fp, ID, name, age, GPA);
        fclose(fp);
    }
    else printf("The command you requested in invalid. Please select from one of these: SHOW, DELETE, ADD\n");
    return 0;
}
