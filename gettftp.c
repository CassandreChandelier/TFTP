#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <netdb.h>

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
	struct addrinfo hints;
	struct addrinfo *result;
	int s;


        if (argc != 3) {
                command("Error, you need 3 arguments\n",STDOUT_FILENO);}


        else {
                host = argv[1];
                file = argv[2];

	}

	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_DGRAM;
	hints.ai_flags = AI_PASSIVE;
	hints.ai_protocol = 0;

	s = getaddrinfo(argv[1],"69", &hints, &result);
	if (s != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
		exit(EXIT_FAILURE);
	}

        host=host;
	file=file;

	gettftp(host,file);

	return EXIT_SUCCESS;

}
