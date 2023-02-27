#include<stdio.h>
void main()
{
    int n, adj[10][10],i,j,source,start;
    int stack[10],visited[10]={0},top=-1;
    printf("enter the no of vertices:");
    scanf("%d",&n);
    printf("enter the adjacent matrix:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&adj[i][j]);
        }
    }

    printf("enter the source vertex:");
    scanf("%d",&source);
    stack[++top]=source;
    visited[source]=1;
    start=source;
    while(top!=-1)
    {
        start=stack[top--];
        printf("%d\t",start);
        for(i=1;i<=n;i++)
        {
            if(adj[start][i]==1 && visited[i]==0)
            {
                stack[++top]=i;
                visited[i]=1;
            }
        }
    }
}