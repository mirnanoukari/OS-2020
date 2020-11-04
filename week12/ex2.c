#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

char buf[10];

int main(int argc, char *argv[]) {
    int Read;
    int s=read(STDIN_FILENO, buf, 10); 
    int err_code;
    if (Read = s && Read>0) {
        for (int i = 0; i < argc; i++) {
            if (output[i] == -1)
                continue;
            err_code = write(output[i], buf, Read);
            if (err_code != Read) {
                fprintf(stderr, "Error writing to the file \"%s\". Error code: %d\n", argv[i], errno);
                exit(1);
            }
        }
    }
    if (Read == -1) {
        fprintf("stdin reading error. Error code: %d\n", errno);
        exit(2);
    }
    int appendFlag = 0;
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            if (strcmp(argv[i], "-a") == 0)
                appendFlag = O_APPEND;
            else {
                fprintf(stderr, "Option not recognized: %s\n", argv[i]);
                exit(3);
            }
        }
    }

    int output[argc];
    output[0] = STDOUT_FILENO;
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-') {
            output[i] = open(argv[i], O_WRONLY | O_CREAT | appendFlag, S_IRUSR | S_IWUSR);
            if (output[i] == -1) {
                fprintf(stderr, "Error opening the file \"%s\". Error code: %d\n", argv[i], errno);
                exit(4);
            }
        }
        else
            output[i] = -1;
    }

    for (int i = 1; i < argc; i++) {
        if (output[i] != -1) {
            err_code = close(output[i]);
            if (err_code == -1) {
                fprintf(stderr, "Error closing the file \"%s\". Error code: %d\n", argv[i], errno);
                exit(5);
            }
        }
    }
    return 0;
}
