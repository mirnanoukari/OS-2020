#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>


typedef struct int_vector {
    size_t size, used;
    int * data;
}
int_vector;

void int_vector_init(int_vector * v) {
    v -> used = 0;
    v -> size = 1;
    v -> data = malloc(sizeof(int));
}

void int_vector_clear(int_vector * v) {
    free(v -> data);
}

void int_vector_expand(int_vector * v) {
    v -> data = realloc(v -> data, 2 * v -> size);
    v -> size *= 2;
}

void int_vector_push_back(int_vector * v, int val) {
    if (v -> used == v -> size) int_vector_expand(v);
    v -> data[v -> used++] = val;
}

int int_vector_belongs(int_vector * v, int val) {
    for (int idx = 0; idx < v -> used; idx++) {
        if (v -> data[idx] == val) {
            return 1;
        }
    }
    return 0;
}

void print_links(char * dir, ino_t inode) {
    DIR * dirp = opendir(dir);
    if (dirp == NULL) return; 

    char filepath[4097];
    struct stat sdata;
    struct dirent * dp;
    while ((dp = readdir(dirp)) != NULL) {
        sprintf(filepath, "%s/%s", dir, dp -> d_name);
        stat(filepath, & sdata);
        if (sdata.st_ino == inode) printf("%s ", dp -> d_name);
    }
}

int main() {
    DIR * dirp = opendir("./tmp");
    if (dirp == NULL) return 1;
    
    char filepath[4097];
    struct stat sdata;

    struct dirent * dp;

    int_vector flagged;
    int_vector_init( & flagged);

    while ((dp = readdir(dirp)) != NULL) {
        sprintf(filepath, "%s/%s", "./tmp", dp -> d_name);
        stat(filepath, & sdata);
        if (sdata.st_nlink >= 2 && strcmp(dp -> d_name, ".") != 0 &&
            strcmp(dp -> d_name, "..") != 0 &&
            int_vector_belongs( & flagged, sdata.st_ino) == 0) {
            printf("Inode number: %ld: %ld ", sdata.st_ino, sdata.st_nlink);
            print_links("./tmp", sdata.st_ino);
            printf("\n");
            int_vector_push_back( & flagged, sdata.st_ino);
        }
    }

    int_vector_clear( & flagged);

    return 0;
}
