#include<stdio.h>
int distance[100],previous[100];
void printpath(int v)
{
    if(previous[v]==-1)
        printf("%d",v);
    else
    {
        printpath(previous[v]);
        printf("-->%d",v);
    }
}
void main()
{
    int i,k,n,source,weight[100][100],j,mark[100],min,u;
    printf("Enter the no. of vertices: ");
    scanf("%d",&n);
    printf("Enter the weight matrix:\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&weight[i][j]);
    printf("Enter the source vertex: ");
    scanf("%d",&source);
    for(i=1;i<=n;i++)
    {
        mark[i]=0;
        distance[i]=999;
        previous[i]=-1;
    }
    mark[source]=1;
    distance[source]=0;
    k=1;
    u=source;
    while(k<n)
    {
        for(i=1;i<=n;i++)
            if(mark[i]==0 && distance[i]>weight[u][i]+distance[u])
            {
                distance[i]=weight[u][i]+distance[u];
                previous[i]=u;
            }
        min=999;
        for(i=1;i<=n;i++)
            if(distance[i]<min && mark[i]==0)
            {
                min=distance[i];
                u=i;
            }
        mark[u]=1;
        k++;
    }
    printf("The shortest paths from source vertex %d are...\n",source);
    for(i=1;i<=n;i++)
        if(i!=source)
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
}
