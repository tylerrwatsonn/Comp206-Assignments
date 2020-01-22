//Tyler Watson 260867260


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct ACCOUNT {
 int accountNumber;
 float balance;
 struct ACCOUNT *next;
};


static struct ACCOUNT *head = NULL;	//global private head pointer

void findUpdate(int account, float amount) {
	if(head==NULL) {		//initialize head
		head = (struct ACCOUNT *)malloc(sizeof(struct ACCOUNT));
		head->accountNumber = account; //set account number to account number
		head->balance = amount;	//set balance to the amount desired
		head->next = NULL;	//set next to null because only one node
		//printf("New head acct: %d amnt: %f\n", head->accountNumber, head->balance);
		return;
	}
	struct ACCOUNT * temp = (struct ACCOUNT *)malloc(sizeof(struct ACCOUNT));
	temp=head;
	while(temp!=NULL) {	//iterates through linked list
		if(temp->accountNumber==account) {	//change this node
			temp->balance += amount;	//update balance
			//printf("Updated acct: %d amnt: %f\n", temp->accountNumber, temp->balance);
			return;
		}
		else if(temp->next!=NULL) {
			temp=temp->next;	//for iteration
		}
		else {
			break;
		}
	}		

	//no node matching account number so create new node
	struct ACCOUNT * new = (struct ACCOUNT *)malloc(sizeof(struct ACCOUNT));
	new->accountNumber = account;
	new->balance = amount;
	new->next = NULL;	//pointing to last node is null
	temp->next = new;	//append node to list by pointing to it using the previous last node
	//printf("New acct: %d amnt: %f\n", new->accountNumber, new->balance);
}

void prettyPrint() {
	struct ACCOUNT * temp = (struct ACCOUNT *)malloc(sizeof(struct ACCOUNT));
	temp = head;
	while(temp!=NULL) {	//iterate through list
		printf("ACCOUNT ID: %5d	 BALANCE: $ %9.2f\n", temp->accountNumber, temp->balance);
		temp=temp->next;	//iterate through list
	}
	
	
}

