#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Customer{
	int number;
	char name[50];
	Customer* left;
	Customer* right;
};

void enter(){
	printf("press ENTER to continue..."); getchar();
}

Customer* createNewCustomer(int number, char name[50]){
	Customer* newCustomer = (Customer*)malloc(sizeof(Customer));
	newCustomer->number = number;
	strcpy(newCustomer->name, name);
	newCustomer->left = NULL;
	newCustomer->right = NULL;
	return newCustomer;
}

void printMenu(){
	puts("Customer Data");
	puts("=============");
	puts("1. View All Cruise Ticket: ");
	puts("2. Buy Cruise Ticket: ");
	puts("5. Exit");
	printf("Choose: ");
}

Customer* insert(Customer* root, int number, char name[50]){
	if(root == NULL){
		root = createNewCustomer(number, name);
		return root;
	} else if(number < root->number){
		root->left = insert(root->left, number, name);
	} else if(number > root->number){
		root->right = insert(root->right, number, name);
	} else if(number == root->number){
		printf("the data has already exist!!\n");
		enter();
	}
	return root;
}

Customer* insertMenu(Customer* root){
	char name[50];
	int custNumber;
	
	printf("input your name: ");
	scanf("%s", name); getchar();
	printf("input your number: ");
	scanf("%d", &custNumber); getchar();
	
	return insert(root, custNumber, name);
}

Customer* search(Customer* root, int number){
	if(root == NULL){
		return NULL;
	} else if(number == root->number){
		return root;
	} else if(number < root->number){
		root = search(root->left, number);
	} else if(number > root->number){
		root = search(root->right, number);
	}
	return root;
}

void searchMenu(Customer* root){
	int numberSearch = 0;
	scanf("%d", &numberSearch); getchar();
	Customer* searchData = search(root, numberSearch);
	if(searchData == NULL){
		printf("Data not found!");
		enter();
	} else{
		printf("number\t: %d\n", searchData->number);
		printf("name\t: %s\n", searchData->name);
	}
}

void preOrder(Customer* root){
	if(root != NULL){
		printf("%d, %s\n", root->number, root->name);
		preOrder(root->left);
		preOrder(root->right);
	}
}

void inOrder(Customer* root){
	if(root != NULL){
		inOrder(root->left);
		printf("%d, %s\n", root->number, root->name);
		inOrder(root->right);
	}
}

void postOrder(Customer* root){
	if(root != NULL){
		postOrder(root->left);
		postOrder(root->right);
		printf("%d, %s\n", root->number, root->name);
	}
}

void viewMenu(Customer *root){
	int inputChoice = 0;
	if(root == NULL){
		puts("there is no data!!");
		enter();
	}
	do{
		puts("What view do you want? ");
		puts("1. Preorder");
		puts("2. Inorder");
		puts("3. PostOrder");
		puts("4. <<Back");
		puts("choose: ");
		scanf("%d", &inputChoice); getchar();
	} while(inputChoice < 1 || inputChoice > 4);
		switch(inputChoice){
			case 1:
				preOrder(root);
				break;
				
			case 2:
				inOrder(root);
				break;
				
			case 3:
				postOrder(root);
				break;
		}
}



int main(){
	
	
	int inputNumber = 0;
	Customer* root = NULL;
	do{
		do{
			system("cls");
			printMenu();
			scanf("%d", &inputNumber);getchar();
		}while(inputNumber < 1 || inputNumber > 5);
		switch (inputNumber){
			case 1:
				viewMenu(root);
				break;
				
			case 2:
				root = insertMenu(root);
				break;
				
			case 3:
				searchMenu(root);
				break;
				
			case 4:
				break;
				
			case 5:
				break;
				
		}
	}while(inputNumber != 5);
	
	
	
	
	
	return 0;
}
