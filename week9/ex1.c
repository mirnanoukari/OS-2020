#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

#define AGE_LIMIT 32 //32 bit by page age
#define MAX_PAGES 999

unsigned int *page_table; //page_table is an array of indexes of pages
unsigned int PageCounter[MAX_PAGES];
unsigned int pframesCount;
int hits=0, misses=0;

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        fprintf(stderr,"Page frames number is not passed.\n");
        return 1;
    }

    FILE *input = fopen("Lab 09 input.txt", "r");

    if (input == NULL) {
        fprintf(stderr, "Cannot open input file.\n");
        return 2;
    }
    pframesCount = atoi(argv[1]);
    page_table = (unsigned int *)calloc(pframesCount, sizeof(int)); 
    for (int page; fscanf(input, "%d", &page) == 1;) {
        int flag = 0;
        for (int i = 0; i < pframesCount; i++) {
            if (page == page_table[i]) {
                hits++;
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            misses++;
            int empty_flag = 0;
            // to deal with page table sizes greater than AGE_LIMIT, althgout this doesn't really make much sense as a design decision.
            for (int i = 0; i < pframesCount; i++) {
                if (page_table[i] == 0) {
                    page_table[i] = page;
                    empty_flag = 1;
                    break;
                }
            }
            if (empty_flag == 0) {
                unsigned int swap_counter = UINT_MAX;
                int swap_index = 0;
                for (int i = 0; i < pframesCount; i++) {
                    unsigned int candidate = PageCounter[page_table[i]];
                    if (candidate < swap_counter)
                        swap_counter = candidate, swap_index = i;
                }
                page_table[swap_index] = page;
            }
        }

        for (int i = 0; i < MAX_PAGES; i++)
            PageCounter[i] >>= 1;
        PageCounter[page] |= 1 << (AGE_LIMIT - 1);
    }

    printf("Hit ratio:\t\t%.3f\n", 100.0 * hits / misses);

    return 0;
}
