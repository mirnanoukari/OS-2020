#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main() {
	char buffer[10];
	setvbuf(stdout, buffer, _IOLBF, 10);

	printf("H");
	sleep(1);	
	printf("e");
	sleep(1);
	printf("l");
	sleep(1);
	printf("l");
	sleep(1);
	printf("o");
	sleep(1);
	printf("\n");

	return 0;
}
