#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
    int value; 
    Node *right, *left; 
}; 

Node *createNode(int value){
    Node *newNode = (Node*)malloc(sizeof(Node)); 
    newNode->value = value; 
    newNode->left = newNode->right = NULL; 
}

Node *insert(Node *curr, int value){
    if(curr == NULL){
        return createNode(value); 
    }
    else{
        if(value < curr->value){
            curr->left = insert(curr->left, value); 
        }
        else if(value > curr->value ){
            curr->right = insert(curr->right, value); 
        }
    }
    return curr; 
}

Node *search(Node *curr, int value){
    if(curr == NULL){
        printf("There is no value that you have inputed [%d]\n", value); 
    }
    else{
        if(value < curr->value){
            return search(curr->left, value); 
        }
        else if(value > curr->value){
            return search(curr->right, value);
        }
        else{
            printf("The value is found [%d]\n", value);
            return curr; 
        }
    }
}

void preOrder(Node* curr){
    if(curr == NULL){
        return; 
    }
    else{
        printf("%d -> ", curr->value); 
        preOrder(curr->left);
        preOrder(curr->right); 
    }
}

void postOrder(Node* curr){
    if(curr == NULL){
        return; 
    }
    else{
        postOrder(curr->left);
        postOrder(curr->right); 
        printf("%d -> ", curr->value); 
    }
}

void inOrder(Node* curr){
    if(curr == NULL){
        return; 
    }
    else{
        preOrder(curr->left);
        printf("%d -> ", curr->value); 
        preOrder(curr->right); 
    }
}

int main(){

    Node *root = NULL; // make sure this initialized first,this will be important for the insert process. 
    //root = insert(root, 50);  //format to insert
    
    // use the functions here
    root = insert(root, 50);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 80);
    root = insert(root, 90);
    
    printf("Roots in order : "); inOrder(root); printf("\n");
    printf("Roots in preorder : "); preOrder(root); printf("\n");
	printf("Roots in postorder : "); postOrder(root); printf("\n");
    return 0; 
}
