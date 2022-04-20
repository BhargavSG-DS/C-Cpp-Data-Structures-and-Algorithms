#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr; 
}

void preOrder(struct node* root){
    if(root!=NULL){
        printf("%d, ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct node* root){
    if(root!=NULL){
        preOrder(root->left);
        preOrder(root->right);
        printf("%d, ",root->data);
    }
}

void inOrder(struct node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d, ",root->data);
        inOrder(root->right);
    }
}

int main(){
    struct node* root = createNode(5);
    struct node* l1 = createNode(2);
    struct node* r1 = createNode(7);
    struct node* rr1 = createNode(9);

    root->left = l1;
    root->right = r1;
    r1->right = rr1;

    preOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");
    inOrder(root);
    return 0;
}