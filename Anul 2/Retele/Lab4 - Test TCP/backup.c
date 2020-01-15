#include <arpa/inet.h> 
#include <netinet/in.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <unistd.h> 

#define PORT 7856


int main() 
{ 
	struct sockaddr_in address; 
	int sock = 0, valread,maxim; 
	struct sockaddr_in serv_addr; 
	char str1[100],str2[100],str[200]; 

	//printf("\nInput the string 1:"); 
	//scanf("%s", str1); 
	
	//printf("\nInput the string 2:"); 
	//scanf("%s", str2);

 
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

	if (inet_pton(AF_INET, "172.30.3.1", &serv_addr.sin_addr) <= 0) { 
		printf("\nAddress not supported \n"); 
		return -1; 
	} 

	if (connect(sock, (struct sockaddr*)&serv_addr, 
				sizeof(serv_addr)) 
		< 0) { 
		printf("\nConnection Failed \n"); 
		return -1; 
	} 

	//int l2 = strlen(str1); 
	
	//int l1 = strlen(str2);


	//send(sock, str1, sizeof(str1), 0); 
	//send(sock, str2, sizeof(str2), 0); 


	recv(sock, str, sizeof(str), 0);
	//recv(sock, &maxim, sizeof(maxim),0);
	//maxim = ntohs(maxim);

	printf("Mesaj de la server: %s\n", str); 
	//printf("Apartii: %d\n", maxim);
	close(sock);

	return 0; 
} 


