#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
	int sd;
	int *x;
	int key = ftok("15-12-03.c", 78);
	
	sd = shmget(key, sizeof(int), 0644 | IPC_CREAT);
	printf("sd: %d\n", sd)
	
	x = shmat(sd, 0, 0);
	
	printf("x = %p\n", x);
	printf
}
