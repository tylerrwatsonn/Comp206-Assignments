//Tyler Watson 260867260

#include <stdlib.h>
#include <stdio.h>

#include "ssv.h"
#include "linked.h"


int main() {
	FILE *fp;
	fp = fopen("bank.ssv", "r");
	char line[20]="";

	while(fgets(line, 19, fp)) {	//line by line
		if('\n' == line[0]) break;
		int acct;
		float amnt;
		parse(line, &acct, &amnt);	//function in ssv.c
		findUpdate(acct, amnt);		//function in linked.c
	} 
	prettyPrint();
	return 0;

}

