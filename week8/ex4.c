#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <unistd.h>

int main() {
    void *ptr[10];
    struct rusage rs;
    int s=10 * 1024 * 1024;

    for (int i = 0; i < 10; i++) {
        ptr[i] = malloc(s);
        if (ptr[i] != NULL)
            memset(ptr[i], 0, s);

        getrusage(RUSAGE_SELF, &rs);
        printf("%s: %ld\n", "Maximum resident set size", rs.ru_maxrss);

        sleep(1);
    }

    for (int i = 0; i < 10; i++){
        free(ptr[i]);
        }
        
    printf("Memory is freed\n");
    getrusage(RUSAGE_SELF, &rs);
    printf("%s: %ld\n", "Maximum resident set size", rs.ru_maxrss);
        
    return 0;
}
