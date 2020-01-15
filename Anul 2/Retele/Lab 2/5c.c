#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>

int main() {
        int c;
        struct sockaddr_in server;
        uint16_t a, n, d[50], div;
        int i;

        c = socket(AF_INET, SOCK_STREAM, 0);
        if (c < 0) {
                printf("Eroare la crearea socketului client\n");
                return 1;
        }

        memset(&server, 0, sizeof(server));
        server.sin_port = htons(1255);
        server.sin_family = AF_INET;
        server.sin_addr.s_addr = inet_addr("127.0.0.1");

        if (connect(c, (struct sockaddr *) &server, sizeof(server)) < 0) {
                printf("Eroare la conectarea la server\n");
                return 1;
        }

        printf("nr = ");
        scanf("%hu", &a);
        a = htons(a);
        send(c, &a, sizeof(a), 0);
        recv(c, &n, sizeof(n), 0);
        n = ntohs(n);
        for(i = 0;i < n; i++) {
                recv(c, &div, sizeof(div), 0);
                div = ntohs(div);
                d[i]=div;
        }
        for(i = 0;i < n; i++)
                printf("%d ",d[i]);
        printf("\n");
        //printf("Suma este %hu\n", n);
        close(c);
}
