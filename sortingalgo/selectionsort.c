#include<stdio.h>
#include<stdlib.h>

void print(int *a, int n)
{
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

void selectionsort(int *a,int n){
    int index;
    for(int i=0;i<n-1;i++){
        printf("pass %d\n",i);
        index = i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[index])
            {
                index = j;
            }
            int temp = a[i];
            a[i] = a[index];
            a[index] = temp;
        }
    }
}

int main()
{
    int ptr[] = {10,2,3,55,6,85,45,5};
    int length = sizeof(ptr)/sizeof(int);
    print(ptr,length);
    selectionsort(ptr,length);
    print(ptr,length);
    return 0;
}