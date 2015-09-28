#include <stdio.h>
#include <stdlib.h>

int main() {
	int i;
	double d;
	char c;

	int *I = &i;
	double *D = &d;
	char *C = &c;
	
	printf("%lu\n%lu\n%lu\n\n", I, D, C);
	
	I++;
	D++;
	C++;
	
	printf("%lu\n%lu\n%lu\n\n", I, D, C);
	
	return 0;
}
