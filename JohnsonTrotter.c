#include <stdio.h>
#include<time.h>

int LR = 1;
int RL = 0;

void swap(int *a, int *b)
{
    int temp = *a;
    *a=*b;
    *b=temp;
}

int fact(int n)
{
    int res = 1;
    for (int i = 1; i <= n; i++)
        res = res * i;
    return res;
}

int Permutation(int a[], int dir[], int n)
{
    int prev = 0, mobile = 0, pos;
    for (int i = 0; i < n; i++)
    {
        if (dir[a[i] - 1] == RL && i != 0) {
            if (a[i] > a[i - 1] && a[i] > prev) {
                mobile = a[i];
                prev = mobile;
            }
        }

        if (dir[a[i] - 1] == LR && i != n - 1) {
            if (a[i] > a[i + 1] && a[i] > prev) {
                mobile = a[i];
                prev = mobile;
            }
        }
    }

    {
    for (int i = 0; i < n; i++)
        if (a[i] == mobile)
            pos = i + 1;
    }

    if (dir[a[pos - 1] - 1] == RL)
        swap(&a[pos - 1], &a[pos - 2]);

    else if (dir[a[pos - 1] - 1] == LR)
        swap(&a[pos], &a[pos - 1]);

    for (int i = 0; i < n; i++) {
        if (a[i] > mobile) {
            if (dir[a[i] - 1] == LR)
                dir[a[i] - 1] = RL;
            else if (dir[a[i] - 1] == RL)
                dir[a[i] - 1] = LR;
        }
    }

    for (int i = 0; i < n; i++)
        printf("%d",a[i]);
    printf("\n");
}

int main()
{
    int n, a[10], dir[10];
    printf("Enter the number of n: ");
    scanf("%d",&n);

    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
        printf("%d",a[i]);
    }
    printf("\n");

    for (int i = 0; i < n; i++)
        dir[i] = RL;

    clock_t start, end;

    start = clock();

    for (int i = 1; i < fact(n); i++)
        Permutation(a, dir, n);

    end = clock();

    double time = (double) (end-start)/CLOCKS_PER_SEC;
    printf("\nExecution time: %f\n", time);
    return 0;

}
