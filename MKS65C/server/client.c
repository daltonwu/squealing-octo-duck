#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char **argv) {
	int socket_id;
	char buffer[256];
	int i;
	
	// create the socket
	socket_id = socket(AF_INET, SOCK_STREAM, 0);
	
	// bind to port/address
	struct sockaddr_in sock;
	sock.sin_family = AF_INET;
	sock.sin_port = htons(5000);
	inet_aton("127.0.0.1", &(sock.sin_addr));
	bind(socket_id, (struct sockaddr *)&sock, sizeof(sock));
	
	// attempt a connection
	i = connect(socket_id, (struct sockaddr *)&sock, sizeof(sock));
	printf("<client> connect returned: %d\n", i);
	if(
}
