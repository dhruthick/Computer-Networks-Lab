#include<stdio.h>
#define min(x,y) (x>y)?y:x
void main()
{
    int capacity,output,count=0,data[100]={0},i=0,x,drop;
    printf("Enter the capacity of the bucket: ");
    scanf("%d",&capacity);
    printf("Enter the output rate: ");
    scanf("%d",&output);
    printf("Enter the size of data arriving at (Enter -1 to stop)\n");
    int c=0;
    while(i!=-1){
        printf("time= %d :",c+1);
        scanf("%d",&i);
        if(i>0)
            data[c++]=i;
    }
    for(i=0;i<c||count;i++){
        printf("time: %d\treceived: %d",i+1,data[i]);
        printf("\tsent: %d",min(data[i]+count,output));
        if((x=data[i]+count-output)>0){
            if(x>capacity){
                count=capacity;
                drop=x-capacity;
            }
            else{
                drop=0;
                count=x;
            }
        }
        else{
            count=0;
            drop=0;
        }
        printf("\tdropped: %d\tremaining: %d\n",drop,count);
    }
}
