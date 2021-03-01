// Client side implementation of UDP client-server model
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <time.h>

#define PORT	 8080
#define MAXLINE 1024

// Driver code
int main() {
     time_t now,t1,t2;
   time(&now);
   char *str=ctime(&now);
	int sockfd;
	char buffer[MAXLINE];
	struct sockaddr_in	 servaddr;

	// Creating socket file descriptor
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}

	memset(&servaddr, 0, sizeof(servaddr));

	// Filling server information
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORT);
	servaddr.sin_addr.s_addr = INADDR_ANY;

	int n, len;

	sendto(sockfd, (char *)str, strlen(str),
		MSG_CONFIRM, (const struct sockaddr *) &servaddr,
			sizeof(servaddr));
   time(&t1);
	printf("message sent to server.\n");

	n = recvfrom(sockfd, (char *)buffer, MAXLINE,
				MSG_WAITALL, (struct sockaddr *) &servaddr,
				&len);
	buffer[n] = '\0';
	printf("Server : %s\n", buffer);
 time(&t2);
/*printf("Time differenc is:%ld seconds\n",t2-t1);*/

	close(sockfd);
	return 0;
}
