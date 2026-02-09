#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int adjacent[MAX][MAX];
int visited[MAX];
int n;
void bfs(int x)
{
    int queue[MAX];
    int f=0;
    int r=0;
    int i;
    for(i=0; i<n;i++)
    {
        visited[i]=0; 
    }
    queue[r++]=x;
    visited[x]=1;
    printf("BFS traversal : ");
    while(f<r)
    {
        int v= queue[f++];
        printf("%d", v);
        for(i=0;i<n;i++)
        {
            if(adjacent[v][i]==1 && !visited[i])
            {
                queue[r++]=i;
                visited[i]=1;
            }
        }
    }
    printf("\n");
}
void dfs(int v)
{
    int i;
    printf("%d", v);
    visited[v]=1;
    for(i=0;i<n;i++)
    {
        if(adjacent[v][i]==1 && !visited[i])
        {
            dfs(i);
        }
    }
}
int main()
{
    int i;
    int j;
    int x;
    printf("Enter number of vertices : ");
    scanf("%d", &n);
    printf("Enter adjacency matrix: \n");
    for(i=0;i<n;i++)
    {
         for(j=0;j<n;j++)
    {
        scanf("%d", & adjacent[i][j]);
        
    }
    }
    printf("Enter starting vertex: \n");
    scanf("%d", &x);
    bfs(x);
    for(i=0;i<n;i++)
    {
    visited[i]=0;
    }
     printf("DFS traversal :");
dfs(x);
return 0;
}