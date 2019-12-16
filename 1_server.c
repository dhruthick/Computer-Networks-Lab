#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<string.h>

void main(){
    int ssock,csock;
    char buffer[500];
    char fn[20];
    int f,n;

    ssock=socket(AF_INET,SOCK_STREAM,0);

    struct sockaddr_in saddr;
    saddr.sin_family=AF_INET;
    saddr.sin_port=htons(911);
    saddr.sin_addr.s_addr=INADDR_ANY;

    bind(ssock,(struct sockaddr *) &saddr,sizeof(saddr));

    if(listen(ssock,5)==0)
        printf("Listening\n");
    else
        printf("Error\n");

    csock=accept(ssock,NULL,NULL);

    recv(csock,fn,20,0);

    f=open(fn,O_RDONLY);
    if(f==-1)
    {
        strcpy(buffer,"File not found");
        n=strlen(buffer);
    }
    else
        n=read(f,buffer,500);

    send(csock,buffer,n,0);

    close(csock);
    close(ssock);
}
