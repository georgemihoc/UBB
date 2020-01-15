#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>

int main() {
        int c;
        struct sockaddr_in server;

        c = socket(AF_INET, SOCK_STREAM, 0);
        if (c < 0) {
                printf("Eroare la crearea socketului client\n");
                return 1;
        }

        memset(&server, 0, sizeof(server));
        server.sin_port = htons(7856);
        server.sin_family = AF_INET;
        server.sin_addr.s_addr = inet_addr("172.30.3.1");

        if (connect(c, (struct sockaddr *) &server, sizeof(server)) < 0) {
                printf("Eroare la conectarea la server\n");
                return 1;
        }

        printf("Dati mesaj1 si mesaj2:\n");
        char str[100],str2[100],str3[100],mesaj1[200],mesaj2[200],mesaj3[200];
        //printf("%d\n",l);
        recv(c,mesaj1,sizeof(mesaj1),0);
        printf("%s\n",mesaj1);

        scanf("%s %s", str,str2,str3);
        //printf("%s\n",str);
        uint16_t l = strlen(str)+1;
        str[l-1]='\n';
        //uint16_t l1 = htons(l);
        //send(c, &l1, sizeof(l), 0);
        send(c, str, sizeof(char)*l, 0);

        recv(c,mesaj2,sizeof(mesaj2),0);

        uint16_t l2=strlen(str2)+1;

        str2[l-1]='\n';
        //uint16_t l3 = htons(l2);
        //send(c, &l3, sizeof(l2), 0);
        str2[0]='4';
        str2[1]='\n';
        send(c, str2, sizeof(char)*3, 0);
        //printf("%c",ch);

        recv(c,mesaj3,sizeof(mesaj3),0);
        printf("%s\n",mesaj3);
        close(c);
}
