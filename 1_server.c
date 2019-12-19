#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<fcntl.h>

void main()
{
	int ssock,f,n;
	ssock=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in saddr;
	saddr.sin_family=AF_INET;
	saddr.sin_port=htons(7891);
	saddr.sin_addr.s_addr=INADDR_ANY;
	bind(ssock,(struct sockaddr*) &saddr, sizeof(saddr));
	if(listen(ssock,5)==0)
		printf("Listening\n");
	else
		printf("Error\n");
	int csock=accept(ssock,NULL,NULL);
	char fname[20],buffer[100];
	recv(csock,fname,20,0);
	f=open(fname,O_RDONLY);
	if(f==-1){
		strcpy(buffer,"File not found");
		n=strlen(buffer);
	}
	else
		n=read(f,buffer,100);
	send(csock,buffer,100,0);
	close(csock);
	close(ssock);
}
