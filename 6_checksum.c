#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int checksum(int ch){
    char data[100];
    int sum=0,n,i;
    printf("Enter data: ");
    fflush(stdin);
    gets(data);
    //scanf("%s",data);
    if(strlen(data)%2==0)
        n=strlen(data)/2;
    else
        n=(strlen(data)+1)/2;
    for(i=0;i<n;i++)
        sum+=(data[i*2]*256)+data[(i*2)+1];
    if(ch==1){
        printf("Enter the value of checksum received: ");
        scanf("%d",&n);
        sum+=n;
    }
    if(sum>=65536)
        sum=(sum/65536)+(sum%65536);
    sum=65535-sum;
    return sum;
}
void main()
{
    printf("Checksum\n");
    while(1){
        printf("1.Encode\t2.Decode\t3.Exit\nEnter choice: ");
        int ch,cs;
        scanf("%d",&ch);
        switch(ch){
        case 1:cs=checksum(0);
        printf("Checksum to be sent is: %d\n",cs);
        break;
        case 2:cs=checksum(1);
        if(cs!=0)
            printf("Checksum= %d Data has been tampered with\n",cs);
        else
            printf("Checksum= %d No errors in data received\n",cs);
        break;
        case 3:exit(0);
        break;
        default:printf("Invalid choice!\n");
        }
    }
}
