#include<stdio.h>
void main()
{
    int n,adj[10][10], visited[10]={0},ne=1,i,j,min,mincost=0,u,v;
    printf("enter the number of vertices:");
    scanf("%d",&n);
    printf("enter the adjacency matrix:");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&adj[i][j]);
            if (adj[i][j]==0)
            adj[i][j]=9999;
        }
    }
    visited[1]=1;
    while(ne < n)
    {
        for(i=1,min=999;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if (visited[i]!=0 && adj[i][j]<min)
                {
                    min=adj[i][j];
                    u=i;
                    v=j;
                }
            }
        }
        if(visited[u]==0||visited[v]==0)
        {
            printf("\n Edge %d (%d,%d):%d",ne++,u,v,min);
            mincost+=min;
            visited[v]=1;
        }
        adj[u][v]=adj[v][u]=9999;
    }
    printf("\nthe minimum cost :%d",mincost);

}