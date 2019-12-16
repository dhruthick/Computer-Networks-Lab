#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<string.h>

void main()
{
    int csock;
    char buffer[500],fn[20];

    csock=socket(AF_INET,SOCK_STREAM,0);

    struct sockaddr_in saddr;
    saddr.sin_family=AF_INET;
    saddr.sin_port=htons(911);
    saddr.sin_addr.s_addr=INADDR_ANY;

    int c=connect(csock, (struct sockaddr*) saddr, sizeof(saddr));
    if(c==-1)
        printf("Error connecting\n");

    printf("Enter filename: ");
    gets(fn);
    send(csock,fname,20,0);

    printf("Response: ");
    while(recv(csock,buffer,500,0)>0)
        puts(buffer);
    printf("\n");

    close(csock);
}
