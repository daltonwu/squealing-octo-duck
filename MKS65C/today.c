#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	int c = 42;
	printf("\nBefore forking, int c = %d\n", c);
	if(fork()) {
		printf("In parent, c = %d\n", c);
		wait(NULL);
	}
	else {
		c = -88;
		printf("In child, c = %d\n", c);
		exit(0);
	}
	printf(" - END OF PROGRAM - \n\n");
	return 0;
}
