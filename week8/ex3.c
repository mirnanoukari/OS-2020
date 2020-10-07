#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int main() {
    void *ptr[10];
    int s = 10 * 1024 * 1024;
    for (int i = 0; i < 10; i++) {
        ptr[i] = malloc(s);
        if (ptr[i] != NULL)
            memset(ptr[i], 0, s);
        sleep(1);
    }
    // we don't need to free the memory, but it's done for good practice.
    for (int i = 0; i < 10; i++)
        free(ptr[i]);
    return 0;
}
