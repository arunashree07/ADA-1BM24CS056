
#include<stdio.h>
#include<time.h>

int minKey(int key[], int set[], int n)
{
    int min=9999, min_idx;
    for(int i=0;i<n;i++)
    {
        if(set[i]==0 && key[i]<min)
        {    min=key[i];
            min_idx=i;}
    }
    return min_idx;
}
int prim(int graph[][100], int n)
{
    int key[100], set[100], parent[100] ;

    for(int i=0;i<n;i++)
    {
        key[i]=999;
        set[i]=0;
    }

    key[0]=0;
    parent[0]=-1;

    for(int k=0;k<n-1;k++)
    {
        int u = minKey(key,set,n);
        set[u]=1;

        for(int i=0;i<n;i++)
        {
            if((graph[u][i])&&set[i]==0 && graph[u][i]<key[i])
            {
                parent[i]=u;
                key[i]=graph[u][i];
            }
        }
    }
    int mincost=0;
    printf("EDGE\tWEIGHT\n");

    for(int i=1;i<n;i++)
    {
        printf("%d-%d\t%d\n", parent[i],i,graph[parent[i]][i]);
        mincost+=graph[parent[i]][i];
    }
    printf("The minimum cost is %d", mincost);
    return 0;
}
int main()
{
    int graph[100][100],n;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix:\n");

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    clock_t start, end;

    start=clock();
    prim(graph, n);
    end=clock();

    double time=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\nExecution time: %f\n", time);
}
