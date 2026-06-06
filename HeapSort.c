#include <stdio.h>
#include <time.h>

void heapify(int a[], int n, int p)
{
    int c, item;
    item = a[p];
    c = 2 * p + 1;

    while (c < n)
    {
        if (c + 1 < n)
        {
            if (a[c] < a[c + 1])
            {
                c++;
            }
        }

        if (item < a[c])
        {
            a[p] = a[c];
            p = c;
            c = 2 * p + 1;
        }
        else
        {
            break;
        }
    }
    a[p] = item;
}

void build_heap(int a[], int n)
{
    int i;

    for (i = (n - 1) / 2; i >= 0; i--)
    {
        heapify(a, n, i);
    }
}

void heapsort(int a[], int n)
{
    int i, temp;

    build_heap(a, n);

    for (i = n - 1; i > 0; i--)
    {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        heapify(a, i, 0);
    }
    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}

int main()
{
    clock_t start, end;
    int a[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    start = clock();
    heapsort(a, n);
    end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nExecution time: %f seconds\n", time_taken);

    return 0;
}
