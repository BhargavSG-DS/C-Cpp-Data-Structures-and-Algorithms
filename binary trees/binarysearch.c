#include<stdio.h>

int binarySearch(int arr[], int size, int element)
{
int low = 0, mid, high = size - 1,i=0;

    while(low<=high)
    {
            printf("pass %d\n",i);
            mid = (high + low)/2;
            if(arr[mid]==element)
            {
                return mid;
            }
            else if(arr[mid] < element)
            {
                low = mid+1;
            }
            else if(arr[mid] > element)
            {
                high = mid-1;
            }
            i++;
    }
    return -1;
}

void main()
{
    int Myarr[] = {12,34,56,71,89,97,101};
    int index;
    int num;
    printf("enter the number to be searched:");
    scanf("%d",&num);
    index = binarySearch(Myarr,7,num);
    printf("the position of %d in the array is at index %d",num,index);
}