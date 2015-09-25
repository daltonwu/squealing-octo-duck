#include <stdio.h>
#include <stdlib.h>

int main() {
	int bob = -1;
	int a[5] = {1, 2, 3, 4, 5};
	printf("bob = %d\n", bob);
	int i;
	for(i=0; i<5; i++) {
		printf("a[%d] = %d\n", i, a[i]);
	}
	i=0;
	for(i=0; i>=-5; i--) {
		printf("a[%d] = %d\n", i, a[i]);
	}
	return 0;
}
