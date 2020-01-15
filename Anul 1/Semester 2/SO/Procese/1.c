#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<string.h>

int main(int argc,char* argv[]) {
        int p[2];
        char s[100];
        gets(s);
        int i;

        pipe(p);
        if(fork()==0) {
                int nrn=0,nrmici=0,nrmari=0;
                close(p[0]);
                for(i = 0;i < strlen(s); i++) {
                        if(s[i] >= '0' && s[i] <= '9')
                                nrn+=1;
                        if(s[i] >= 'a' && s[i] <= 'z')
                                nrmici+=1;
                        if(s[i] >= 'A' && s[i] <= 'Z')
                                nrmari+=1;
                }
                write(p[1],&nrn,sizeof(int));
                write(p[1],&nrmici,sizeof(int));
                write(p[1],&nrmari,sizeof(int));
                close(p[1]);
                exit(0);
        }
        int a,b,c;
        wait(0);
        read(p[0],&a,sizeof(int));
        read(p[0],&b,sizeof(int));
        read(p[0],&c,sizeof(int));
        printf("Numere: %d, Mici: %d, Mari: %d \n",a,b,c);


        return 0;
}
