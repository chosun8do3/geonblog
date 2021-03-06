#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<sys/socket.h>

void error_handling( char *message )	{
	fputs( message, stderr );
	fputc( '\n', stderr );
	exit(1);
}

int main(int argc, int **argv)	{
	int sock;
	struct sockaddr_in serv_addr;
	//char message[30];
	int str_len;
	char ID[12];
	char name[25];
	char message[100];
	char result[20];

	printf("ID : ");
	scanf("%s", &ID);
	printf("name : ");
	scanf("%s", &name);
	printf("message : ");
	scanf("%s", &message);

	printf("ID : %s, name : %s, message : %s", ID, name, message);

	if(argc != 3)	{
		printf("Usage : $s <IP> <port> \n", argv[0]);
		exit(1);
	}

	sock = socket( PF_INET, SOCK_STREAM, 0 );
	if(sock == -1)
		error_handling( "socket() error" );

	memset( &serv_addr, 0, sizeof(serv_addr) );
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_addr.sin_port = htons( atoi( argv[2]));

	if( connect( sock, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) == -1 )
		error_handling( "connect() error!" );

	write( sock, &ID, sizeof(ID) );
	write( sock, &name, sizeof(name) );
	write( sock, &message, sizeof(message) );

	str_len = read( sock, result, sizeof(result) - 1 );
	if(str_len == -1)
		error_handling( "read() error!" );

	printf("%s\n\n", result);

	close( sock );

	return 0;

}


