#include <stdlib.h>
#include <stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>

int main() {
        int p1[2],p2[2],n,m;
        pipe(p1);
        pipe(p2);
        scanf("%d",&n);
        write(p1[1],n,sizeof(int));
        if(fork() == 0) {
                close(p1[1]);
                close(p2[0]);
                read(p1[0],&m,sizeof(int));
                m = m * 2;
                write(p2[1],m,sizeof(int));
                exit(0);
        }
        wait(0);
        read(p2[0],&n,sizeof(int));
        printf("%d",n);
        return 0;
}		
