#include <stdio.h>
#define INF 9999
#define MAX 10
int mindistance(int dist[], int visited[], int n)
{
    int min=INF,index= -1;
    for(int i=0; i<n;i++)
    {
        if(!visited[i] && dist[i]<min )
        {
            min = dist[i];
            index = i;
        }
    }
    return index;
}
void dijkstra(int graph[MAX][MAX],int n, int src)
{
    int dist[MAX],visited[MAX];
    for(int i=0;i<n;i++)
    {
        dist[i]=INF;
        visited[i]=0;
    }
    dist[src]=0;
    for(int count=0;count<n-1;count++)
    {
        int u = mindistance(dist,visited,n);
        visited[u]=1;
    for(int v = 0; v < n; v++){
        if(!visited[v] && graph[u][v]&& dist[u]!=INF && dist[u]+graph[u][v]<dist[v])
            {
    dist[v]=dist[u]+graph[u][v];
            }
    }
}

printf("Vertex\tdistance from source\n");
for(int i=0;i<n;i++)
{
    printf("%d\t%d\n",i,dist[i]);
}

}

int main()
{
    int graph[MAX][MAX]={
        {0, 4, 0, 0, 0},
        {4, 0, 8, 0, 0},
        {0, 8, 0, 7, 2},
        {0, 0, 7, 0, 6},
        {0, 0, 2, 6, 0}
    };
    int n=5;
    int source=0;
    dijkstra(graph,n,source);
    return 0;
}