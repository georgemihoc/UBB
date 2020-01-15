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
	//char str[200]; 

 
	char buffer[1024] = { 0 }; 

	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) { 
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
	

	if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) { 
		printf("\nConnection Failed \n"); 
		return -1; 
	} 

	// while(1){
	// 	recv(sock, str, sizeof(str), 0);
	// 	printf("Mesaj de la server: %s\n", str);
	// 	printf("\nInput the message:");
	// 	char str1[200];
 //        scanf("%s", str1);
 //        char *newstr = malloc(strlen(str1) + 2);
	// 	strcpy(newstr, str1);
	// 	strcat(newstr, "\n");
	// 	//strcat(str1,"\n");
	// 	send(sock, newstr, sizeof(newstr), 0);
	// }
	char str[100]= "George Mihoc\n",str2[100]="4\n",str3[100], mesaj[100],mesaj2[100],mesaj3[100];
	recv(sock, mesaj,sizeof(mesaj),0);
	printf("%s", mesaj);

	//scanf("%s %s", str,str2,str3);
	//uint16_t l= strlen(str)+1;
	//str[l-1]='\n';

	send(sock, str,sizeof(char)*14,0);

	recv(sock,mesaj2,sizeof(mesaj2),0);

	uint16_t l2= strlen(str2)+1;

	//str2[l-1] = '\n';

	//str2[0] = "4";
	//str2[1] = '\n';
	send(sock,str2,sizeof(char)*3,0);

	recv(sock,mesaj3,sizeof(mesaj3),0);

	printf("%s\n",mesaj3 );

	//printf("Mesaj de la server: %s\n", str); 
	close(sock);

	return 0; 
} 


