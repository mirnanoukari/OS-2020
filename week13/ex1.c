#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Determine the number of processed and number of resources from the input
// file. Note that the input file is not rewinded afterwards.
void parse_input_params(FILE *input, int *N, int *M) {
#define BUFFER_SIZE 1024
    char inpstr[BUFFER_SIZE], ignore[BUFFER_SIZE];
    
    fscanf(input, "%[^\n]", inpstr);
    
    *M = 0;
    for (char *tok = strtok(inpstr, " "); tok; tok = strtok(NULL, " "))
        (*M)++;
    
    fscanf(input, "%[\n]", ignore);
    fscanf(input, "%[^\n]", ignore);
    fscanf(input, "%[\n]", ignore);
    
    *N = 0;
    while(!feof(input)) {
        (*N)++;
        fscanf(input, "%[^\n]", ignore);
        fscanf(input, "%[\n]", inpstr);
        if (strlen(inpstr) == 2)
            break;
    }

#undef BUFFER_SIZE
}

int main(int argc, char *argv[]) {
    FILE* input;
    if (argc < 2) {
        printf("Not enough arguments, exiting.\n");
        return 1;
    }
    input = fopen(argv[1], "r");
    if (!input) {
        printf("Problem opening input file, exiting.\n");
        return 2;
    }
    int N, M;
    parse_input_params(input, &N, &M);
    fclose(input);
    
    int E[M], A[M];
    int C[N][M], R[N][M];

    input = fopen(argv[1], "r");
    
    for (int i = 0; i < M; i++)
        fscanf(input, "%d", &E[i]);
    
    for (int i = 0; i < M; i++)
        fscanf(input, "%d", &A[i]);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            fscanf(input, "%d", &C[i][j]);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            fscanf(input, "%d", &R[i][j]);

    fclose(input);

    int flag[N];
    for (int i = 0; i < N; i++)
        flag[i] = 0;

    for (int done = 0; done == 0;) {
        done = 1;
        for (int i = 0; i < N; i++) {
            if (flag[i] == 1)
                continue;
            int less = 1;
            for (int j = 0; j < M; j++)
                if (R[i][j] > A[j])
                    less = 0;
            if (less == 1) {
                for (int j = 0; j < M; j++)
                    A[j] += C[i][j];
                done = 0;
                flag[i] = 1;
                break;
            }
        }
    }

    int deadlock_found = 0;
    for (int i = 0; i < N; i++) {
        if (flag[i] == 0) {
            deadlock_found = 1;
            printf("Process %d is deadlocked.\n", i);
        }
    }

    if (deadlock_found == 0)
        printf("No deadlocks detected.\n");
    return 0;
}