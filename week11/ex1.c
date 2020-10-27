#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int main() {
	int f = open("ex1.txt", O_RDWR);
	if (f == -1) printf("error opening the file");
	
	struct stat st;
	fstat(f, &st);
	if (fstat(f, &st) == -1) printf("cannot get file stat");
	
	char* str = "This is a nice day";
	char* fm = mmap(NULL, st.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, f, 0);
	
	for (int i = 0; i < strlen(str); i++) {
	fm[i] = str[i];
	}
	
	fm[strlen(str)] = '\0';
	msync(fm, strlen(str) + 1, MS_SYNC);
	munmap(fm, st.st_size);
	
	close(f);
	return 0;
}
