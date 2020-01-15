#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
int main(int argc, char* argv[]){
        int c01[2],n,c02[2],c2p[2],x;
        pipe(c01);
        pipe(c02);
        pipe(c2p);
        if(fork()==0){
                close(c01[0]);
                close(c02[0]);
                scanf("%d",&n);
                write(c01[1],&n,sizeof(int));
                write(c02[1],&n,sizeof(int));
                close(c01[1]);
                close(c02[1]);
                exit(0);
        }
        if(fork()==0){
                close(c01[1]);
                read(c01[0],&n,sizeof(int));
                for(int d=2;d<=n/2;d++)if(n%d==0)printf("%d ",d);
                close(c01[0]);
                exit(0);
        }
        if(fork()==0){
                close(c02[1]);
		read(c02[0],&n,sizeof(int));
                int nr=n/3;
                while(nr)
                {
                        //printf("%d\n",nr);
                        scanf("%d",&x);
                        write(c2p[1],&x,sizeof(int));
                        nr--;
                }
                exit(0);
        }
int s=0,c=0;
while(c!=3){
        read(c2p[0],&x,sizeof(int));
        s+=x;
        c++;
        }
int ma=s/c;
printf("media: %d",ma);
wait(0);wait(0);wait(0);
return 0;
}

