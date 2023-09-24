#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Customer{
	char id[10];
	char name[50];
	int age;
	Customer* left;
	Customer* right;
};

Customer* createNewCustomer(char id[], char name[], int age){

	Customer* newCustomer = (Customer*)malloc(sizeof(Customer));
	strcpy(newCustomer->id, id);
	strcpy(newCustomer->name, name);
	newCustomer->age = age;
	newCustomer->left = newCustomer->right = NULL;
	return newCustomer;
	
}

Customer* insert(Customer* root, char id[], char name[], int age){
	if(root == NULL){
		root = createNewCustomer(id, name, age);
	}else if(strcmp(id, root->id) < 0){
		root->left = insert(root->left, id, name, age);
	}else if(strcmp(id, root->id) > 0){
		root->right = insert(root->right, id, name, age);
	}else{
		printf("data already exist!!\n");
	}
	
	return root;
}

void preOrder(Customer* root){
	if(root != NULL){
		printf("%s, %s, %d\n", root->id, root->name, root->age);
		preOrder(root->left);
		preOrder(root->right);
	}
}

Customer* predesessor(Customer* root){
	Customer* curr = root->left;
	while(curr->right != NULL){
		curr = curr->right;
	}
	return curr;
}

Customer* successor(Customer* root){
	Customer* curr = root->left;
	while(curr->left != NULL){
		curr = curr->left;
	}
	return curr;
}

void postOrder(Customer* root){
	if(root != NULL){
		preOrder(root->left);
		preOrder(root->right);
		printf("%s, %s, %d\n", root->id, root->name, root->age);
	}
}

void inOrder(Customer* root){
	if(root != NULL){
		preOrder(root->left);
		printf("%s, %s, %d\n", root->id, root->name, root->age);
		preOrder(root->right);
	}
}

Customer* deleteAvl(Customer* root){
	if(root == NULL){
		printf("the data is not exist!");
		return NULL;
	}else if(strcmp(id, root->id) < 0){
		root->left = deleteAvl(root->left, id);
	}else if(strcmp(id, root->id) > 0){
		root->right = deleteAvl(root->right, id);
	}else{
		if(root->left == NULL && root->right == NULL){
			free(root);
			root = NULL;
		}else if(root->left == NULL || root->right == NULL){
			Customer* temp;
			if(root->left != NULL){
				temp = root->left;
			}else{
				temp = root->right;
			}
		}else{
			// ----- Menggunakan predesessor-----------
			Customer* pre = predesessor(root);
			strcpy(root->id, pre->id);
			strcpy(root->name, pre->name);
			root->age = pre->age;
			
			root->left - deleteAvl(root->left, pre->id);
			// ------Menggunakan successor--------------
//			Customer* pre = successor(root);
//			strcpy(root->id, pre->id);
//			strcpy(root->name, pre->name);
//			root->age = pre->age;
//			
//			root->right - deleteAvl(root->left, pre->id);
		}
	}
	return root;
}

Customer* deleteMenu(Customer* root){
	char id[255];
	do{
		printf("Input Id you want to delete[5-10]: ");
		scanf("%[^\n]", id);
	}while(strlen(id) <  2 || strlen(id) > 10)
	
	return deleteAvl(root, id);
}


int main(){
	
	Customer* root = NULL;
	root = insert(root, "SUI1", "Asep", 10);
	root = insert(root, "SAI2", "Budi", 15);
	root = insert(root, "SIU3", "Cico", 20);
	root = insert(root, "SIU4", "Dodi", 25);
	root = insert(root, "SIU5", "Egys", 30);
	root = insert(root, "SIU6", "Fadi", 35);
	inOrder(root);
	puts("");
	
	root = deleteMenu(root);
	preOrder(root);
	puts("");
	
	return 0;
}
