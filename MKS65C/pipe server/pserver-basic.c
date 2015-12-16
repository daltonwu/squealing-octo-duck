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
	
	mkfifo("mario", 0644);
	*from_client = open("mario", O_RDONLY);
	
	remove("mario");
	
	read(from_client, buffer, sizeof(buffer));
	
	to_client = open(buffer, O_WRONLY);
	
	strncpy(buffer, "it's-a-me, mario!", sizeof(buffer));
	
	write(to_client, buffer, sizeof(buffer));
	
	return to_client;
}

int main() {
	int to_client;
	int from_client;
	char buffer[100];
	
	to_client = server_handshake(&from_client);
	
	while(1) {
		read(from_client, buffer, sizeof(buffer));
		// do stuff to buffer
		write(to_client, buffer, sizeof(buffer));
	}
	
	return 0;
}
