//Tyler Watson 260867260

#include <stdio.h>

int reverse(char* a,char* b) {
	int sizeA; //size of a
	int sizeB; //size of b
	for (sizeA=0;a[sizeA]!='\0'; ++sizeA); //compute size of a
	for (sizeB=0;b[sizeB]!='\0'; ++sizeB); //compute size of b
	if (sizeA != sizeB) return -1;	       //if sizes are not equal return -1 to signify not the reverse
	for(int i=0; i<sizeA; i++) {	       //go through all letters of a
		if (a[i]!=b[sizeB-1-i]) return -1; //compare letter with its mirror location in b and if they are not equal then return -1 to signify not the reverse
	}
	return 0; //if function has not returned yet it means that b is the reverse of a

}

int main(int argc, char* argv[]) { 
	if (argc!=3) { //check number of arguments
		printf("Wrong number of arguments. Please input: ./reverse WORD1 WORD2.\n");
		return 1;
	}
	int result = reverse(argv[1], argv[2]); //call function
	if(result==0) printf("WORD1=%s WORD2=%s - REVERSE\n",argv[1], argv[2]); //if they are the reverse function will return 0
	if(result==-1) printf("WORD1=%s WORD2=%s - NOT REVERSE\n", argv[1], argv[2]); //if they are not the reverse the function will return -1
	return 0; //end program
}

