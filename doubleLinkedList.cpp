#include <stdio.h>
#include <stdlib.h>

struct tnode{
	int data;
	struct tnode *next;
	struct tnode *prev;
};

struct tnode *head = NULL;

void pushBelakang(int data){
	struct tnode *newnode = (struct tnode*)malloc(sizeof(struct tnode));
	newnode->data = data;
	newnode->next = NULL;
	newnode->prev = NULL;
	
	if(head == NULL){
		head = newnode;
	} else{
		struct tnode *curr = head;
		
		while(curr->next != NULL){
			curr = curr->next;
		}
		curr->next = newnode;
		newnode->prev = curr;
	}
}

void pushDepan(int data){
	struct tnode *newnode = (struct tnode*)malloc(sizeof(struct tnode));
	newnode->data = data;
	newnode->next = NULL;
	newnode->prev = NULL;
	
	if(head == NULL){
		head = newnode;
	} else{
		newnode->next = head;
		head->prev = newnode;
		head = newnode;
	}
}

int main(){
	
	push(7);	
	push(17);	
	push(27);	
	
	return 0;
}
