#include <arpa/inet.h> 
#include <netinet/in.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <unistd.h> 

#define PORT 1234 


int main() 
{ 
	struct sockaddr_in address; 
	int sock = 0, valread,maxim; 
	struct sockaddr_in serv_addr; 
	char str1[100],str2[100],str[200]; 
	char caracter[100];

	printf("\nInput the string:"); 
	scanf("%s", str1); 
	
	printf("\nInput the character:"); 
	scanf("%s", caracter);

 
	char buffer[1024] = { 0 }; 

	if ((sock = socket(AF_INET, 
					SOCK_STREAM, 0)) 
		< 0) { 
		printf("\n Socket creation error \n"); 
		return -1; 
	} 

	memset(&serv_addr, '0', sizeof(serv_addr)); 
	serv_addr.sin_family = AF_INET; 
	serv_addr.sin_port = htons(PORT); 

	if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) { 
		printf("\nAddress not supported \n"); 
		return -1; 
	} 

	if (connect(sock, (struct sockaddr*)&serv_addr, 
				sizeof(serv_addr)) 
		< 0) { 
		printf("\nConnection Failed \n"); 
		return -1; 
	} 

	int l2 = strlen(str1); 


	send(sock, str1, sizeof(str1), 0); 
	send(sock, caracter, sizeof(caracter), 0); 


	recv(sock, str, sizeof(str), 0);
	
	printf("Caracter: %s\n", str); 
	close(sock);

	return 0; 
} 

