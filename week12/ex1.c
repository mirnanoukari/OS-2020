#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    char buf[20];
    int ran = open("/dev/random", O_RDONLY);
    
    read(ran, buf, 20);
    printf("%s\n" ,buf);
    
    close(ran);
    
    return 0;
}

