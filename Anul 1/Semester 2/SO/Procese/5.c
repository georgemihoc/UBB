#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>
int main(int argc, char* argv[]){
        int fd;
        char* myfifo="/tmp/myfifo";
        char buf[256];
        int nrn=0,nrmici=0,nrmari=0;
        fd=open(myfifo, O_RDONLY);
        read(fd, buf, 256);
        for(int i=0;i<strlen(buf);i++){
                if(buf[i]>='0' && buf[i]<='9')nrn++;
                if(buf[i]>='a' && buf[i]<='z')nrmici++;
                if(buf[i]>='A' && buf[i]<='Z')nrmari++;
        }
        printf("numere: %d, mari: %d, mici: %d",nrn,nrmari,nrmici);
        close(fd);
        return 0;
}
