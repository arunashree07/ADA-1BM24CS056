#include<time.h>
#include<stdio.h>

int max(int a, int b)
{
    if (a>b)
        return a;
    else
        return b;
}
int main()
{
    int P[100], W[100], M, n, Table[100][100];
    printf("Enter the number of of components: ");
    scanf("%d", &n);
    printf("Enter the maximum capacity of the knapsack: ");
    scanf("%d", &M);

    for(int i=1;i<=n;i++)
    {
        printf("Enter the weight and profit: ");
        scanf("%d%d", &W[i], &P[i]);
    }      
    
    clock_t start, end;
    start = clock();
    for(int i=0;i<=n;i++)
    {
         for(int j=0;j<=M;j++)
         {
             if(i==0 || j==0)
             {
                 Table[i][j]=0;
             }
             else if (j<W[i])
             {
                 Table[i][j]=Table[i-1][j];
             }
             else
             {
                 Table[i][j]=max(Table[i-1][j], P[i]+Table[i-1][j-W[i]]);
             }
         }
    }

    end = clock();
    printf("Maximum knap is %d", Table[n][M]);
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nExecution time: %f seconds\n", time_taken);
