//============================================================================
// Name        : udpServer.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : UDP ECHO Server
//============================================================================

// Server side implementation of UDP client-server model
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT	 8080
#define MAXLINE 1024


void createUdpSocket(int& sockfd  , sockaddr_in& servaddr)
{
	memset(&servaddr, 0, sizeof(servaddr));

	// Creating socket file descriptor
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}

	// Filling server information
	servaddr.sin_family = AF_INET; // IPv4
	servaddr.sin_addr.s_addr = INADDR_ANY;
	servaddr.sin_port = htons(PORT);


	// Bind the socket with the server address
	if ( bind(sockfd, (const struct sockaddr *)&servaddr,
			sizeof(servaddr)) < 0 )
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
}



// Driver code
int main() {

	//Create and bind UDP socket
	int sockfd(0);
	struct sockaddr_in servaddr;
	createUdpSocket(sockfd,servaddr);



	char buffer[MAXLINE];
	char *hello = "Hello from server @@ ";
	struct sockaddr_in cliaddr;
	memset(&cliaddr, 0, sizeof(cliaddr));



	int len, n;

	len = sizeof(cliaddr); //len is value/resuslt

	n = recvfrom(sockfd, (char *)buffer, MAXLINE,
				MSG_WAITALL, ( struct sockaddr *) &cliaddr,
				(  socklen_t *) &len);
	buffer[n] = '\0';
	printf("Client : %s\n", buffer);
	sendto(sockfd, (const char *)hello, strlen(hello),
		MSG_CONFIRM, (const struct sockaddr *) &cliaddr,
			len);
	printf("Hello message sent.\n");

	return 0;
}
