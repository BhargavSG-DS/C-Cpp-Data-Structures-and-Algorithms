#include <stdio.h>
#include <stdlib.h>

int count;

void print(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int partition(int *a, int low, int high)
{
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    do
    {
        while (a[i] <= pivot)
        {
            i++;
        }
        while (a[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);
    int temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j;
}

void quicksort(int *a, int low, int high)
{
    int index;
    if (low < high)
    {
        printf("call %d\n", count);
        count++;
        index = partition(a, low, high);
        quicksort(a, low, index - 1);
        quicksort(a, index + 1, high);
    }
}

int main()
{
    int ptr[] = {10, 2, 3, 55, 6, 85, 10, 5, 6, 7, 5};
    // int ptr[] = {1,2,3,4,5,6,7};
    int length = sizeof(ptr) / sizeof(int);
    print(ptr, length);
    quicksort(ptr, 0, length - 1);
    print(ptr, length);
    return 0;
}