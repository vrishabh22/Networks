#include<stdio.h>
#include<unistd.h>
#include<netinet/in.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
	
#define SERV_PORT 5576
main(int argc,char **argv)
{
	int i,j;
	ssize_t n;
	FILE *fp;
	char s[80],f[80],command[50];
	//strcpy(s,"file.txt");
	
	struct sockaddr_in servaddr,cliaddr;
	
	int listenfd,connfd,clilen;
	
	listenfd=socket(AF_INET,SOCK_STREAM,0);
	
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(SERV_PORT);
	
	bind(listenfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
	listen(listenfd,1);
	clilen=sizeof(cliaddr);
	
	connfd=accept(listenfd,(struct sockaddr*)&cliaddr,&clilen);
	printf("\n clinet connected");
	int data2[100];
	read(connfd,data2,100);
	int c1=(data2[3-1])^data2[5-1]^data2[7-1]^data2[9-1]^data2[11-1]^data2[1-1];
	int c2=(data2[3-1])^data2[6-1]^data2[7-1]^data2[10-1]^data2[11-1]^data2[2-1];
	int c3=data2[5-1]^data2[6-1]^data2[7-1]^data2[12-1]^data2[4-1];
	int c4=data2[9-1]^data2[10-1]^data2[11-1]^data2[12-1]^data2[8-1];
	printf("%d %d %d %d",c1,c2,c3,c4);
	if(c1==0&&c2==0&&c3==0&&c4==0)
		printf("No error!");
	else
		printf("Error");
	close(listenfd);	
	
	}
