#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
 
int main() {
	int c,i;
	struct sockaddr_in server;
	uint16_t a, b, suma;
	char str[200],str2[200];
	printf("\nInput the string:"); 
	scanf("%s", str); 

	c = socket(AF_INET, SOCK_DGRAM, 0);
	if (c < 0) {
	printf("Eroare la crearea socketului client\n");
	return 1;
	}
	memset(&server, 0, sizeof(server));
	server.sin_port = htons(1234);
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr("127.0.0.1");

	int len = sizeof(server);


	sendto(c, str, strlen(str), 0, (struct sockaddr *) &server,len);
	int pozitii[100];
	int k; 

	recvfrom(c, str2, sizeof(str2), MSG_WAITALL, (struct sockaddr *) &server, &len);

	//recvfrom(c, &k, sizeof(k), MSG_WAITALL, (struct sockaddr *) &server, &len);
	//k=ntohs(k);
	//recvfrom(c, pozitii, sizeof(pozitii), MSG_WAITALL, (struct sockaddr *) &server, &len);
	//printf("%d\n",k);
	//for(i=0;i<k;i++)
	//	printf("%d\n", pozitii[i]+1);
	printf("Caracter: %s\n", str2); 
  
 	close(c);
}