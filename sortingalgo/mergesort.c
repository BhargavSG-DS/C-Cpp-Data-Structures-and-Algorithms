#include <stdio.h>
#include <stdlib.h>

int count;

void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void mergesort(int *a, int *b, int *c, int m, int n)
{
    int i, j, k;
    i = j = k = 0;
    while (i < m && j < n)
    {
        if (a[i] < b[j])
        {
            c[k] = a[i];
            i++, k++;
        }
        else
        {
            c[k] = b[j];
            j++, k++;
        }
    }
    while (i < m)
    {
        c[k] = a[i];
        k++, i++;
    }
    while (j < n)
    {
        c[k] = b[j];
        k++, j++;
    }
}

int main()
{
    int ptr1[] = {10, 11, 22, 55, 67, 75};
    int ptr2[] = {1, 2, 3, 4, 5, 6, 7};
    int l1 = sizeof(ptr1) / sizeof(int);
    int l2 = sizeof(ptr2) / sizeof(int);
    int l3 = l1 + l2;
    int ptr[l3];
    print(ptr1, l1);
    print(ptr2, l2);
    mergesort(ptr1, ptr2, ptr, l1, l2);
    print(ptr, l3);
  return 0;
}