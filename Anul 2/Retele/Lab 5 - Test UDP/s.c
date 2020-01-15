// server program for udp connection 
#include <stdio.h> 
#include <strings.h> 
#include <sys/types.h> 
#include <arpa/inet.h> 
#include <sys/socket.h> 
#include<netinet/in.h> 
#define PORT 5000 
#define MAXLINE 1000 

// Driver code 
int main() 
{ 
	char *message = "Hello Client";   
	int listenfd, len; 
	struct sockaddr_in servaddr, cliaddr; 
	bzero(&servaddr, sizeof(servaddr)); 
	// Create a UDP Socket 
	listenfd = socket(AF_INET, SOCK_DGRAM, 0);		 
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
	servaddr.sin_port = htons(PORT); 
	servaddr.sin_family = AF_INET; 

	// bind server address to socket descriptor 
	bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)); 
	
		//receive the datagram 
	len = sizeof(cliaddr); 
	while(1){
		int pozitii[100],k=0,i,j;
		char buffer[100],str2[200]; 

		int n = recvfrom(listenfd, buffer, sizeof(buffer), 
				0, (struct sockaddr*)&cliaddr,&len); //receive message from server 
		buffer[n] = '\0'; 
		int poz = 0;
		int maxim = 0;
		for(i = 0;i<strlen(buffer);i++){
	        int nr = 0;
	        for(j=0;j<strlen(buffer);j++){
	                if(buffer[i]==buffer[j])
	                        nr++;
	        }
	        if(nr>maxim)
	        {
	                maxim = nr;
	                str2[0]= buffer[i];
	        }
		}
		for(i = 0;i<strlen(buffer);i++){
	        if(buffer[i]== str2[0])
	                pozitii[k++]=i;
		} 
		printf("%d",k);
		// send the response 
		sendto(listenfd, str2, MAXLINE, 0, 
			(struct sockaddr*)&cliaddr, sizeof(cliaddr)); 
		k = htons(k);
		sendto(listenfd, &k, MAXLINE, 0, 
			(struct sockaddr*)&cliaddr, sizeof(cliaddr)); 
		sendto(listenfd, pozitii, MAXLINE, 0, 
			(struct sockaddr*)&cliaddr, sizeof(cliaddr)); 
	}
	close(listenfd);

} 

