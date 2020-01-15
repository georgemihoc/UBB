// udp client driver program 
#include <stdio.h> 
#include <strings.h> 
#include <sys/types.h> 
#include <arpa/inet.h> 
#include <sys/socket.h> 
#include<netinet/in.h> 
#include<unistd.h> 
#include<stdlib.h> 

#define PORT 5000 
#define MAXLINE 1000 
//Raspuns: Un client trimite unui server un sir de caractere.
// Serverul returneaza caracterul care se gaseste de cele mai multe ori in 
//sir si pozitiile pe care apare. Are you satisfied with this problem?
int main() 
{ 
	char buffer[100]; 
	char message[100] ; 
	int sockfd, n,k,pozitii[100],i; 
	struct sockaddr_in servaddr; 
	printf("\nInput the string:"); 
	scanf("%s", message); 
	// clear servaddr 
	bzero(&servaddr, sizeof(servaddr)); 
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
	servaddr.sin_port = htons(PORT); 
	servaddr.sin_family = AF_INET; 
	
	// create datagram socket 
	sockfd = socket(AF_INET, SOCK_DGRAM, 0); 
	
	// connect to server 
	if(connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) 
	{ 
		printf("\n Error : Connect Failed \n"); 
		exit(0); 
	} 

	// request to send datagram 
	// no need to specify server address in sendto 
	// connect stores the peers IP and port 
	sendto(sockfd, message, MAXLINE, 0, (struct sockaddr*)NULL, sizeof(servaddr)); 
	
	// waiting for response 
	recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)NULL, NULL); 
	recvfrom(sockfd, &k, sizeof(int), 0, (struct sockaddr*)NULL, NULL);
	k = ntohs(k); 
	recvfrom(sockfd, pozitii, sizeof(int)*k, 0, (struct sockaddr*)NULL, NULL);
	//printf("%d\n",k);
	printf("caracterul:");
	printf("%c\n",buffer[0]);
	printf("pozitii:");
	for(i=0;i<k;i++)
		printf("%d ", pozitii[i]+1); 
	printf("\n");
	

	// close the descriptor 
	close(sockfd); 
} 

