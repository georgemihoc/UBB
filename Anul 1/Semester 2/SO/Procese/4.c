#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc, char* argv[]){

	int fd;
	char* myfifo="/tmp/myfifo";

	mkfifo(myfifo, 0666);

	fd=open(myfifo, O_WRONLY);

	char string[101];

	fgets(string,100,stdin);

	write(fd,string,sizeof(string));

	unlink(myfifo);

	return 0;
}
