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

	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) { 
		perror("socket failed"); 
		exit(EXIT_FAILURE); 
	} 

	address.sin_family = AF_INET; 
	address.sin_addr.s_addr = INADDR_ANY; 
	address.sin_port = htons(PORT); 

	if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) { 
		perror("bind failed"); 
		exit(EXIT_FAILURE); 
	} 
	while(1){
		if (listen(server_fd, 3) < 0) { 
			perror("listen"); 
			exit(EXIT_FAILURE); 
		} 
		if ((new_socket = accept(server_fd, 
						(struct sockaddr*)&address, 
						(socklen_t*)&addrlen)) < 0) { 
			perror("accept"); 
			exit(EXIT_FAILURE); 
		} 
		if(fork()==0){


			valread = read(new_socket, str1, 
					sizeof(str1));
			valread = read(new_socket, str2, 
					sizeof(str2));
			int l1 = strlen(str1), l2= strlen(str2);


			printf("\nString 1 sent by client:%s\n", str1); 
			printf("\nString 2 sent by client:%s\n", str2);

			int n = strlen(str1);
			int m = strlen(str2);
			int i = 0, j = 0,k=0;


			while (i < n && j < m)
				if (str1[i] < str2[j])
					str[k++] = str1[i++];
				else
					str[k++] = str2[j++];

			while (i < n)
				str[k++] = str1[i++];
			while (j < m)
				str[k++] = str2[j++];

			send(new_socket, str, sizeof(str), 0); 
			printf("\nModified string sent to client\n"); 
			close(new_socket);
			exit(0);
		}
	}
	return 0; 

} 

