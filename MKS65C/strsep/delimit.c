#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int main() {
	
	char line[100] = "wow-this-is-cool";
	char *s1, *s2;
	s1 = line;
	
	int i=5;
	while(i) {
		s2 = strsep(&s1, "-");
		
		printf("s1: %s\n", s1);
		printf("s2: %s\n", s2);
		printf("line: %s\n\n", line);
		
		i--;
	}
}
