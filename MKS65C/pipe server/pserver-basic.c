#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int server_handshake(int *from_client) {
	int to_client;
	char buffer[100];
	
	mkfifo("mario", 0644); // create WKP
	*from_client = open("mario", O_RDONLY); // open and wait for connection
	
	remove("mario"); // once connected, remove the pipe file
	
	read(from_client, buffer, sizeof(buffer)); // read from client
	printf("<server> connection established: [%s]\n", buffer);
	to_client = open(buffer, O_WRONLY); // connect downstream
	
	strncpy(buffer, "it's-a-me, mario!", sizeof(buffer));
	write(to_client, buffer, sizeof(buffer)); // send initial message
	
	return to_client;
}

int main() {
	int to_client;
	int from_client;
	char buffer[100];
	
	to_client = server_handshake(&from_client);
	
	while(1) {
		read(from_client, buffer, sizeof(buffer));
		printf("<server> received [%s]\n", buffer);
		strncat(buffer, "purple monkey dishwasher", sizeof(buffer)-1);
		write(to_client, buffer, sizeof(buffer));
	}
	
	close(to_client);
	close(from_client);
	return 0;
}
