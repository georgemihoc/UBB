#include <netinet/in.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <unistd.h> 
#include <signal.h>

#define PORT 1234 
int s;
void selfDestroy(int sig){
	close(s);
	exit(0);
}

int main() 
{ 
	signal(SIGINT,selfDestroy);
	int server_fd, new_socket, valread; 
	struct sockaddr_in address; 
	char str1[100],str2[100],str[200]; 
	int addrlen = sizeof(address); 
	char buffer[1024] = { 0 }; 
	char* hello = "Hello from server"; 

	if ((server_fd = socket(AF_INET, 
					SOCK_STREAM, 0)) == 0) { 
		perror("socket failed"); 
		exit(EXIT_FAILURE); 
	} 

	address.sin_family = AF_INET; 
	address.sin_addr.s_addr = INADDR_ANY; 
	address.sin_port = htons(PORT); 

	if (bind(server_fd, (struct sockaddr*)&address, 
				sizeof(address)) < 0) { 
		perror("bind failed"); 
		exit(EXIT_FAILURE); 
	} 

	if (listen(server_fd, 3) < 0) { 
		perror("listen"); 
		exit(EXIT_FAILURE); 
	} 
	if ((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) { 
		perror("accept"); 
		exit(EXIT_FAILURE); 
	} 

		valread = read(new_socket, str1, 
				sizeof(str1));
		valread = read(new_socket, str2, 
				sizeof(str2));
		int i, j; 
		int l1 = strlen(str1), l2= strlen(str2);


		printf("\nString 1 sent by client:%s\n", str1); 
		printf("\nString 2 sent by client:%s\n", str2);

		char caracter[100]="abc";
		int maxim=0, nr = 0;
		for(i = 0;i<strlen(str1);i++){
			if(str1[i]==str2[i]){
				nr=0;
				for(j = 0;j<strlen(str1);j++)
					if(str1[j]==str1[i])
						nr++;
				for(j = 0;j<strlen(str2);j++)
					if(str2[j]==str1[i])
						nr++;
				if(nr>maxim){
					maxim = nr;
					strcpy(caracter,str1+i);
				}
			}
		}

		send(new_socket, caracter, sizeof(caracter), 0); 
		maxim = htons(maxim);
		send(new_socket, &maxim, sizeof(maxim), 0);
		printf("\nModified string sent to client\n %s",caracter); 
		close(new_socket);

	return 0; 
} 

