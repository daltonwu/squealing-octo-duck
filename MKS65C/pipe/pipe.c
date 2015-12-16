/**
 * 15-12-14 Monday
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
	puts("");
	
	int pipefd[2];
	pipe(pipefd);
	
	printf("fd[0]: %d\tfd[1]: %d\n", pipefd[0], pipefd[1]);
	
	int f = fork();
	if(f == 0) {
		// child writes a float
		close(pipefd[0]); // don't need read end
		
		float c = 123.456;
		printf("Child writes %f; ", c);
		write(pipefd[1], &c, sizeof(c)); // write to pipe
		
		close(pipefd[1]); // finished
	}
	else {
		// parent reads the float
		close(pipefd[1]); // don't need write end
		
		float p;
		read(pipefd[0], &p, sizeof(p)); // read from pipe
		printf("parent sees %f.\n", p);
		
		close(pipefd[0]); // finished
	}
	
	puts("");
	return 0;
}
