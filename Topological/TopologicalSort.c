#include<stdio.h>
#include<time.h>

void topologicalSort(int v,int adj[v][v]){
    int indegree[v], queue[v];
    int front=0,rear=-1;
    for(int i=0;i<v;i++){
        indegree[i]=0;
    }
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(adj[i][j]==1){
                indegree[j]++;
            }
        }
    }
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            queue[++rear]=i;
        }
    }
    printf("\nTopological order:\t");
    while(front<=rear){
        int node=queue[front++];
        printf("%d ",node+1);
        for(int i=0;i<v;i++){
            if(adj[node][i]==1){
                indegree[i]--;
                if(indegree[i]==0){
                    queue[++rear]=i;
                }
            }
        }
    }
}
int main(){
    int v;
    printf("\nEnter the number of vertices: ");
    scanf("%d",&v);
    int adj[v][v];
    printf("\nEnter the adjacency matrix:\n");
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            scanf("%d",&adj[i][j]);
        }
    }
    clock_t start, end;

    start = clock();
    topologicalSort(v,adj);
    end = clock();
    double time = (double)(end-start)/CLOCKS_PER_SEC;

    printf("\nExecution time: %f\n",time);
    return 0;
}
