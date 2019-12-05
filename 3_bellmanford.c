#include<stdio.h>

int distance[100],next[100],cost[100][100],src,flag,n,i,j,k;
void printpath(int v)
{
    if(next[v]==-1)
        printf("%d",v);
    else
    {
        printpath(next[v]);
        printf("-->%d",v);
    }
}

void main(){
    printf("Enter the no.of nodes: ");
    scanf("%d",&n);
    printf("Enter the cost matrix:\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&cost[i][j]);
    //for(src=1;src<=n;src++){
        for(i=1;i<=n;i++){
            distance[i]=999;
            next[i]=-1;
        }
        printf("Enter the source node: ");
        scanf("%d",&src);
        distance[src]=0;
        for(k=1;k<n;k++){
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++){
                    if(cost[i][j]!=999 && cost[i][j]!=0 && distance[j]>distance[i]+cost[i][j]){
                        distance[j]=distance[i]+cost[i][j];
                        next[j]=i;
                    }
                }
        }
        for(i=1;i<=n;i++)
                for(j=1;j<=n;j++){
                    if(cost[i][j]!=999 && distance[j]>distance[i]+cost[i][j]){
                        printf("Negative cycle exists\n");
                        return;
                    }
                }
        printf("Shortest path from %d is given below\n",src);
        for(i=1;i<=n;i++)
            if(i!=src)
            {
                printf("For vertex %d: ",i);
                if(distance[i]==999)
                    printf("No path\n");
                else
                {
                    printpath(i);
                    printf(" Distance=%d\n",distance[i]);
                }
            }
        printf("\n\n");
    //}
}
