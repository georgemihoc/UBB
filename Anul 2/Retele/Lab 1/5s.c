#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
int main() {
        int s;
        struct sockaddr_in server, client;
        int c, l;

        s = socket(AF_INET, SOCK_STREAM, 0);
        if (s < 0) {
                printf("Eroare la crearea socketului server\n");
                return 1;
        }

        memset(&server, 0, sizeof(server));
        server.sin_port = htons(1255);
        server.sin_family = AF_INET;
        server.sin_addr.s_addr = INADDR_ANY;

        if (bind(s, (struct sockaddr *) &server, sizeof(server)) < 0) {
                printf("Eroare la bind\n");
                return 1;
        }

        listen(s, 5);

        l = sizeof(client);
        memset(&client, 0, sizeof(client));
        while (1) {
                uint16_t a, n, d[50],div;
                c = accept(s, (struct sockaddr *) &client, &l);
                if(fork()==0){
                        printf("S-a conectat un client.\n");
                        recv(c, &a, sizeof(a), MSG_WAITALL);
                        a = ntohs(a);
                        n = 0;
                        int i;
                        for(i = 1;i <= a;++i)
                                if(a % i == 0) {
                                        d[n] = i;
                                        n += 1;
                                }
                        n = htons(n);
                        send(c, &n, sizeof(n), 0);
                        for(i = 0;i < n;++i) {
                                div = d[i];
                                div = htons(div);
                                send(c, &div, sizeof(div), 0);
                        }

                        close(c);
                        exit(0);
                }
        }
}
