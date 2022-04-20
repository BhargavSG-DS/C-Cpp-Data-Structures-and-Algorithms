#include <stdio.h>
#include <stdlib.h>

void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void mergesort(int a[], int low, int mid, int high)
{
    int i, j, k;
    int b[100];
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }
        else
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        b[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        b[k] = a[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        a[i] = b[i];
    }
}

void merge(int a[], int l, int h)
{
    int mid;
    if (l < h)
    {
        mid = (l + h) / 2;
        merge(a, l, mid);
        merge(a, mid + 1, h);
        mergesort(a, l, mid, h);
    }
}

int main()
{
    int ptr[] = {876, 6868, 8610, 597, 687, 7864};
    int l = sizeof(ptr) / sizeof(int);
    print(ptr, l);
    merge(ptr, 0, l-1);
    print(ptr, l);
    return 0;
}