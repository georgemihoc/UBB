#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main(int argc,char* argv[]) {
        int c1[2],c2[2],p[2];
        pipe(c1);
        pipe(c2);
        pipe(p);
        int n;
        if(fork() == 0) {
                close(c1[0]);
                close(c2[0]);
                scanf("%d",&n);
                write(c1[1],&n,sizeof(int));
                write(c2[1],&n,sizeof(int));
                exit(0);
        }
        if(fork() == 0) {
                close(c1[1]);
                read(c1[0],&n,sizeof(int));
                printf("Divizorii lui n sunt: ");
                for(int d = 1; d <=n; ++d)
                        if(n % d == 0)
                                printf("%d ",d);
                printf("\n");
                exit(0);
        }
        if(fork() == 0) {
                int v[10];
                close(c2[1]);
                close(p[0]);
                read(c2[0],&n,sizeof(int));
                write(p[1],&n,sizeof(int));
                for(int i = 1; i <= n/3; ++i)
                        scanf("%d",&v[i]);
                for(int i = 1; i <= n/3; ++i)
                                write(p[1],&v[i],sizeof(int));
                exit(0);
        }
        int s = 0,nr;
        read(p[0],&n,sizeof(int));
        for(int i = 1;i <= n/3; ++i) {
                read(p[0],&nr,sizeof(int));
                s += nr;
        }
        s = s / (n/3);
        printf("Media aritmetica: %d\n",s);

        wait(0);
        wait(0);
        wait(0);
        return 0;
}
