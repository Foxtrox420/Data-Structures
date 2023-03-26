#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    Node *right, *left;
};

Node *createNode(int value){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode -> value = value;
    newNode -> left = newNode -> right = NULL;
    return newNode;
}

Node *insert(Node *curr, int value){
    if(curr == NULL) return createNode(value);
    else{
        if(value < curr -> value){
            curr -> left = insert(curr -> left, value);
        }else if(value > curr -> value){
            curr -> right = insert(curr -> right, value);
        }
    }
    return curr;
}

Node *search(Node *curr, int value){
    if(curr == NULL){
        printf("%d is not found\n", value);
        return NULL;
    }else{
        if(value < curr -> value){
            return search(curr -> left, value);
        }else if(value > curr -> value){
            return search(curr -> right, value);
        }else if(value == curr -> value){
            printf("%d is found\n", value);
            return curr;
        }
    }
}

void preOrder(Node *curr){
    if(curr == NULL) return;
    else{
        printf("%d -> ", curr->value);
        preOrder(curr -> left);
        preOrder(curr -> right);
    }
}

void inOrder(Node *curr){
    if(curr == NULL) return;
    else{
        preOrder(curr -> left);
        printf("%d -> ", curr->value);
        preOrder(curr -> right);
    }
}

void postOrder(Node *curr){
    if(curr == NULL) return;
    else{
        postOrder(curr -> left);
        postOrder(curr -> right);
        printf("%d -> ", curr -> value);
    }
}

int main(void){

    Node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 80);
    root = insert(root, 90);
    preOrder(root);
    printf("\n");
    inOrder(root); 
    printf("\n");
    postOrder(root); 
    printf("\n"); 
    
    search(root, 70); 
    search(root, 69);

    return 0;
}
