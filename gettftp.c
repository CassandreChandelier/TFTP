#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>

#define MAX_DATA_SIZE 512
#define SERVER_PORT 69
#define NBYTES 1024


void command(char *output,int exit){
        write(exit, output, strlen(output));
}

void gettftp(char *host, char *file){
                command("Downloading file from the server \n",STDOUT_FILENO);
}

int main(int argc, char *argv[]){

	char *host, *file;

        if (argc != 3) {
                command("Error, you need 3 arguments\n",STDOUT_FILENO);}


        else {
                host = argv[1];
                file = argv[2];


        gettftp(host,file);
}
	return EXIT_SUCCESS;

}
