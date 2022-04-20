#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

int max(int data1, int data2){
    if(data1>data2)
        return data1;
    return data2;
    }

int getHeight(struct Node *ptr)
{
    if(ptr==NULL)
        return 0;
    return ptr->height;
}

struct Node *createNode(int key)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left= NULL;
    node->right=NULL;
    node->height = 1;
    return node;
}

int getBalanceFactor(struct Node* ptr)
{
    if(ptr==NULL)
        return 0;
    return getHeight(ptr->left) - getHeight(ptr->right);
}

struct Node * RightRotate(struct Node* ptr)
{
    struct Node* l = ptr->left;
    struct Node* r = ptr->right;

    ptr->right = ptr;
    ptr->left = r;

    ptr->height = max(getHeight(ptr->right),getHeight(ptr->left)) + 1;
    l->height = max(getHeight(l->right),getHeight(l->left)) + 1;

    return l;
}

struct Node * LeftRotate(struct Node* ptr)
{
    struct Node* r = ptr->right;
    struct Node* l = ptr->left;

    r->left = ptr;
    ptr->right = l;

    ptr->height = max(getHeight(ptr->right),getHeight(ptr->left)) + 1;
    r->height = max(getHeight(r->right),getHeight(r->left)) + 1;

    return r;
}

void inOrder(struct Node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d(%d) ",root->key,root->height);
        inOrder(root->right);
    }
}

struct Node* insertbst(struct Node* root,int key)
{
    if(root == NULL)
        return(createNode(key));
    
    if(key < root->key)
        root->left = insertbst(root->left,key);
    else if (key > root->key)
        root->right = insertbst(root->right,key);
    
    root->height = 1 + max(getHeight(root->left),getHeight(root->right));
    int bf = getBalanceFactor(root);

    //left-left case
    if(bf>1 && key < root->left->key){ return RightRotate(root);}
    //right-right case
    if(bf<-1 && key > root->right->key){ return LeftRotate(root);}
    //left-right case
    if(bf>1 && key > root->right->key){root->left = LeftRotate(root->right); return RightRotate(root);}
    //right-left case
    if(bf<-1 && key < root->left->key){root->right = RightRotate(root->right); return LeftRotate(root);}
}

int main(){
    struct Node * root = createNode(5);
    insertbst(root,8);
    insertbst(root,3);
    // insertbst(root,56);
    insertbst(root,2);
    inOrder(root);
    return 0;
}