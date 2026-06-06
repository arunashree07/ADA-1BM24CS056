#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#define MAX 30

typedef struct {
    int u, v, w;
} Edge;

Edge edges[MAX], result[MAX];
int parent[MAX];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void setUnion(int i, int j) {
    parent[i] = j;
}

void sortEdges(int e) {
    int i, j;
    Edge temp;
    for (i = 0; i < e - 1; i++) {
        for (j = 0; j < e - i - 1; j++) {
            if (edges[j].w > edges[j + 1].w) {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

void kruskal(Edge edges[], int n, int m)
{
    int i,u,v, count=0, cost=0;
    for (i = 0; i < n; i++)
        parent[i] = i;

    sortEdges(m);

    for (i = 0; i < m && count < n - 1; i++) {
        u = find(edges[i].u);
        v = find(edges[i].v);

        if (u != v) {
            result[count++] = edges[i];
            cost += edges[i].w;
            setUnion(u, v);
        }
    }

    printf("\nMinimum Spanning Tree:\n");
    for (i = 0; i < count; i++) {
        printf("%d-%d\t%d\n", result[i].u, result[i].v, result[i].w);
    }

    printf("Total cost = %d\n", cost);

}
int main() {
    int n, m, i, j, u, v;
    int count = 0, cost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter edges (u v weight):\n");
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    clock_t start, end;
    start=clock();
    kruskal(edges, n,m);
    end=clock();
    double time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("\nExecution time: %f\n", time);
    return 0;
}
