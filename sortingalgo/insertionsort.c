#include<stdio.h>
#include<stdlib.h>

void print(int *a, int n)
{
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

void insertionsort(int *a,int n){
    int key,j;
    for(int i=0;i<n;i++){
        printf("pass %d\n",i);
        key = a[i];
        j=i-1;
        while(j>=0 && a[j] > key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1]=key;
    }
}

int main()
{
    int ptr[] = {10,9,8,7,65,4,3,3,2,10};
    int length = sizeof(ptr)/sizeof(int);
    print(ptr,length);
    insertionsort(ptr,length);
    print(ptr,length);
    return 0;
}