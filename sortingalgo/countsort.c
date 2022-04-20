#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void print(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int maximum(int A[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < A[i])
        {
            max = A[i];
        }
    }
    return max;
}

void countsort(int *a, int l)
{
    int i, j;

    int max = maximum(a, l);

    int *count = (int *)malloc((max + 1) * sizeof(int));

    for (int i = 0; i <= max; i++)
    {
        count[i] = 0;
    }

    for (i = 0; i < l; i++)
    {
        count[a[i]] = count[a[i]] + 1;
    }
    i = 0;
    j = 0;

    while (i <= max)
    {
        if (count[i] > 0)
        {
            a[j] = i;
            count[i] = count[i] - 1;
            j++;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int ptr[] = {15,9,101,54,58};
    // int ptr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int l = sizeof(ptr) / sizeof(int);
    print(ptr, l);
    countsort(ptr, l);
    print(ptr, l);
    return 0;
}