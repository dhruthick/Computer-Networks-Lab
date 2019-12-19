#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<fcntl.h>
void main()
{
	int csock;
	csock=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in saddr;
	saddr.sin_family=AF_INET;
	saddr.sin_port=htons(7891);
	saddr.sin_addr.s_addr=INADDR_ANY;
	int c=connect(csock,(struct sockaddr *) &saddr,sizeof(saddr));
	if(c==-1)
		printf("Error connecting\n");
	else
	{
		printf("Enter file name: ");
		char fname[20],buffer[100];
		gets(fname);
		send(csock,fname,20,0);
		printf("Response: ");
		recv(csock,buffer,100,0);
		puts(buffer);
	}
	close(csock);
}
