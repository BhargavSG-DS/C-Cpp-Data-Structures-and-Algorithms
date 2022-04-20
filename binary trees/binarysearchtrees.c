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

int isBST(struct node* root){
    static struct node *prev = NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev != NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return (isBST(root->right));
    }
    else{
        return 1;
    }
}

void inOrder(struct node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d, ",root->data);
        inOrder(root->right);
    }
}

struct node* binarySearch(struct node* root,int key){
    if(root!=NULL){
        if(root->data == key){
            return root;
        }
        else if(root->data > key){
            return(binarySearch(root->left,key));
        }
        else{
            return(binarySearch(root->right,key));
        }
    }
    else{
        return NULL;
    }
}

void insertbst(struct node *root,int key){
    struct node* prev = NULL;
    while(root!=NULL){
        prev = root;
        if(key == root->data){
            printf("Cannot insert duplicates\n");
            break;
        }
        else if(key <root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    struct node* new = createNode(key);
    if(key>prev->data){
        prev->right = new;
    }
    else{
        prev->left = new;
    }
}

struct node * inOrderPre(struct node* root){
    root = root->left;
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}

struct node* deleteNode(struct node* root,int value){
    struct node* ipre;
    if(root==NULL){
        return NULL;
    }

    if(root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }

    if(value<root->data){
        root->left = deleteNode(root->left,value);
    }
    else if(value>root->data){
        root->right = deleteNode(root->right,value);
    }
    else{
        ipre = inOrderPre(root);
        root->data = ipre->data;
        root->left = deleteNode(root->left,ipre->data);
    }
    return root;
}

int main(){
    int n;
    struct node* root = createNode(5);
    struct node* l1 = createNode(2);
    struct node* r1 = createNode(7);
    struct node* rr1 = createNode(9);
    struct node* lr1 = createNode(3);
    struct node* rl1 = createNode(6);
    root->left = l1;
    root->right = r1;
    r1->right = rr1;
    r1->left = rl1;
    l1->right = lr1;

    if(isBST(root)){
        printf("Yes\n");
    }

    else{
        printf("no, not a binary search tree!");
    }

    printf("insert:\t");
    scanf("%d",&n);
    insertbst(root,n);
    inOrder(root);
    printf("\n");
    deleteNode(root,n);
    inOrder(root);
    printf("\n");
    deleteNode(root,5);
    inOrder(root);
    printf("\n");
    insertbst(root,5);
    inOrder(root);
    return 0;
}