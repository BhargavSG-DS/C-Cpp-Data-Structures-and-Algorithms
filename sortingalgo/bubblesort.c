#include<stdio.h>
#include<stdlib.h>

void print(int *a, int n)
{
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

void bubblesort(int *a,int n){
    int temp,sort=0;
    for(int i=0;i<n;i++){
        sort = 1;
        printf("pass %d\n",i);
        for(int j=0;j<n-1;j++){
            if(a[j]>a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                sort = 0; 
            }
            if(sort){
                return;
            }
        }
    }
}

int main()
{
    int ptr[] = {15,9,101,54,58};
    int length = sizeof(ptr)/sizeof(int);
    print(ptr,length);
    bubblesort(ptr,length);
    print(ptr,length);
    return 0;
}