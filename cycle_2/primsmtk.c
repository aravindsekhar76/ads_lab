#include <stdio.h>

#define V 5

int G[V][V] = {
    {0,1,0,3,4},
    {1,0,7,5,0},
    {0,7,0,2,0},
    {3,5,2,0,9},
    {4,0,0,9,0}};


int main()
{
    int selected[V]={0},i,j,x,y,sum;
    int edge_count=0,min;

    selected[0]=1;
    while(edge_count < V-1)
    {
        x = 0, y=0, min=999;
        for(i=0;i<V;i++)
        {
            if (selected[i]==1)
            {
                for(j=0;j<V;j++)
                {
                    if (!selected[j] && G[i][j] !=0)
                    {
                        if (min > G[i][j] ) {
                            min=G[i][j];
                            x=i;
                            y=j;
                        }
                    }
                }
            }
        }
    printf("edge : weight  = ");
    sum = sum + G[x][y];
    printf("%d - %d : %d\n",x,y,G[x][y]);
    selected[y]=1;
    edge_count ++;
    
    }
    printf("minimum cost = %d",sum);
return 0;
}