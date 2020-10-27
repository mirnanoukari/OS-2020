#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int main(){
    int fsrc, fdst;
    char *src, *dst;
    struct stat st;

    fsrc = open("ex1.txt", O_RDONLY);
    fdst = open("ex1.memcpy.txt", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if(fsrc == -1) printf("error opening the file");
 
    if(fstat(fsrc, &st) == -1) printf("cannot get file stat"); 
    if(st.st_size == 0) return 0;
    
    ftruncate(fdst, st.st_size);
    
    src = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fsrc, 0);
    dst = mmap(NULL, st.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fdst, 0);
    
    if(src == MAP_FAILED || dst == MAP_FAILED) return 1;
    
    memcpy(dst, src, st.st_size);
    
    close(fsrc);
    close(fdst);
}
