#include <stdio.h>
#include<time.h>
#define INF 99

void floyd(int A[][10], int n)
{
    int i,j,k;
        for(k = 0; k < n; k++) {
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                if(A[i][k] + A[k][j] < A[i][j]) {
                    A[i][j] = A[i][k] + A[k][j];
                }
            }
        }
    }
    printf("\nShortest Distance Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(A[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int n, i, j, k;
    int cost[10][10], A[10][10];
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the cost matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            A[i][j] = cost[i][j];
        }
    }
     clock_t start, end;

    start=clock();
    floyd(A, n);
    end=clock();

    double time=(double)(end-start)/CLOCKS_PER_SEC;
    printf("Execution time: %f", time);
    return 0;
}
