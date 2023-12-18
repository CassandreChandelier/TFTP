#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <netdb.h>

#define MAX_DATA_SIZE 1024
#define SOCKET_ERROR "Error while creating the socket"

void command(char *output,int exit){
	write(exit, output, strlen(output));
}

void gettftp(char *host, char *file){
	command("Downloading file from the server\r\n",STDOUT_FILENO);

	struct addrinfo hints,*result,*p;
	int status,sock;

	memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_DGRAM;
	hints.ai_flags = AI_PASSIVE;
    hints.ai_protocol = IPPROTO_UDP;

	status = getaddrinfo(host,"69", &hints, &result);
    if (status != 0) {
        fprintf(stderr, "Error getaddrinfo: %s\r\n", gai_strerror(status));
		exit(EXIT_FAILURE);}

	int client_socket = -1;
    for (p = result; p != NULL; p = p->ai_next) {
        client_socket = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (client_socket == -1) {
            continue; // Fail for the creation of the socket
        }

        if (connect(client_socket, p->ai_addr, p->ai_addrlen) != -1) {
            break; // success for the connection
        }

        close(client_socket); // close the socket if fail of connection
    }

	freeaddrinfo(result);

	if (p == NULL){
		fprintf(stderr,"Can't connect to the server\n");
		exit(EXIT_FAILURE);
		}

}


int main(int argc, char *argv[]){

	char *host, *file;

	if (argc != 3) {
        command("Error, you need 3 arguments\r\n",STDOUT_FILENO);
		exit(EXIT_FAILURE);}


    else {
        host = argv[1];
        file = argv[2];

    }

   gettftp(host,file);

   return 0;


}
