#include <stdio.h>

int main() {
	char str[] = "hippo";
	int i=0;
	while(str[i]) i++;
	printf("%d\n\n", i);
	return 0;
}
