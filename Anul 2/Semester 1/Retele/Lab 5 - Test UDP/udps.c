#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>


#include <stdlib.h> 
#include <unistd.h> 
#include <arpa/inet.h> 


int main() {
int s;
struct sockaddr_in server, client;
int c, l;
int pozitii[100],k=0;
uint16_t  old = 0;
char str1[200],str2[200];

s = socket(AF_INET, SOCK_DGRAM, 0);
if (s < 0) {
printf("Eroare la crearea socketului server\n");
return 1;
}

memset(&server, 0, sizeof(server));
memset(&client, 0, sizeof(client));

server.sin_port = htons(1234);
server.sin_family = AF_INET;
server.sin_addr.s_addr = INADDR_ANY;

if (bind(s, (struct sockaddr *) &server, sizeof(server)) < 0) {
printf("Eroare la bind\n");
return 1;
}

l = sizeof(client);
memset(&client, 0, sizeof(client));

recvfrom(s, str1, sizeof(str1), MSG_WAITALL, (struct sockaddr *) &client, &l);

int i, j; 
int l1 = strlen(str1);
printf("\nString 1 sent by client:%s\n", str1); 


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
//printf("%d\n",k);
int len= sizeof(client);
char *hello = "Hello from server"; 

sendto(s,  hello, sizeof(str1), 0, (struct sockaddr *) &client, &len);
//k = htons(k);
//sendto(s, k, sizeof(int), 0, (struct sockaddr *) &client, sizeof(client));
//sendto(s, pozitii, sizeof(int)*k, 0, (struct sockaddr *) &client, sizeof(client));

  
close(s);
}