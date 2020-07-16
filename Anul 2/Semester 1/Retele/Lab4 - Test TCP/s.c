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
void * socketThread(void *arg)
{
    printf("Deservice client...\n");
    char str1[100],str2[100]; 
    int server_fd, valread; 
    char caracter;
    int pozitii[100],k=0;
    int new_socket = *((int *)arg);
  	valread = read(new_socket, str1, sizeof(str1));
		int i, j; 
		int l1 = strlen(str1);
		printf("\nString 1 sent by client:%s\n", str1); 
		//printf("\nCharacter sent by client:%c\n", caracter);
		
		int poz = 0;
		int minim = 999;
		for(i = 0;i<strlen(str1);i++){
			int nr = 0;
			for(j=0;j<strlen(str1);j++){
				if(str1[i]==str1[j])
					nr++;
			}
			if(nr<minim)
			{
				minim= nr;
				str2[0]= str1[i];
			}
		}
		for(i = 0;i<strlen(str1);i++){
			if(str1[i]== str2[0])
				pozitii[k++]=i;
		}

		printf("%c\n",str2[0]);
		send(new_socket, str2, sizeof(str2), 0); 
		k = htons(k);
		send(new_socket,&k,sizeof(int),0);
		send(new_socket,pozitii,sizeof(int)*k,0);
		
		close(new_socket);
    	pthread_exit(NULL);
}
int main() 
{ 
	signal(SIGINT,selfDestroy);
	int server_fd, new_socket, valread; 
	struct sockaddr_in address; 
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
	
	 pthread_t tid[40];
    	int i = 0;

    	while (1) {
        	if ((new_socket = accept(server_fd, (struct sockaddr*)&address,(socklen_t*)&addrlen))< 0) { 
		perror("accept"); 
		exit(EXIT_FAILURE); 
	} 

        	printf("S-a conectat un client.\n");

        	if( pthread_create(&tid[i++], NULL, socketThread, &new_socket) != 0 ) {
            		printf("Failed to create thread\n");
        	}
        
        	if( i >= 30) {
           		i = 0;
            		while(i < 30) {
                		pthread_join(tid[i++],NULL);
            		}
            		i = 0;
        	}

    	}

	return 0; 
} 

