#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

void childs_play(int s) {
	printf("[CHILD] pid: %d\n", getpid());
	sleep(s);
	printf("[CHILD] I'm DONE!\n");
	exit(1);
}

void parents_work() {
	int i, x, status, c1, c2;
	printf("[PARENT] pid: %d\n", getpid());
	printf("[PARENT] running … \n");
	x = wait(&status);
	printf("[PARENT] wait returned: %d\tstatus: %d\n", x, WEXITSTATUS(status));
	exit(2);
}

int main() {
	pid_t c1, c2;
	c1 = fork();
	
	if(c1 == 0) {
		childs_play(3);
	}
	else {
		c2 = fork();
		if(c2 == 0) {
			childs_play(1);
		}
		else {
			parents_work();
		}
		childs_play(3);
	}
	return 0;
}
