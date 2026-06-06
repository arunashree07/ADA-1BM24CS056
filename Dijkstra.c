#include <stdio.h>
#include<time.h>

int minDist(int dist[], int vis[], int n) {
    int min = 10000, min_idx;

    for (int i = 0; i < n; i++) {
        if (vis[i] == 0 && dist[i] <= min) {
            min = dist[i];
            min_idx = i;
        }
    }
    return min_idx;
}

void dijkstra(int graph[][100], int src, int n) {
    int dist[100];
    int vis[100];

    for (int i = 0; i < n; i++) {
        dist[i] = 10000;
        vis[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDist(dist, vis,n);
        vis[u] = 1;

        for (int v = 0; v < n; v++)
        {
            if (!vis[v] && graph[u][v] && dist[u] != 10000 && dist[u] + graph[u][v] < dist[v])
                {
                    dist[v] = dist[u] + graph[u][v];
                }
        }
    }

    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < n; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

int main() {
    int graph[100][100],n;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d",&n);
    printf("Enter weight matrix: \n");
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
            scanf("%d", &graph[i][j]);
      }
    }

    int source = 0;
    clock_t start, end;
    start=clock();
    dijkstra(graph, source, n);
    end=clock();

    double time=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\nExecution time: %f\n", time);

    return 0;
}
