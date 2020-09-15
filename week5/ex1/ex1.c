#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

#define N 10

void * print_some_text(int i) {
	printf("Printing some text from thread %d with number %d\n", (int) pthread_self(), i);
	pthread_exit(NULL);
	
}

int main() {
	int threads[N];
	for (int i = 0; i < N; i++) {
		pthread_create(&threads[i], NULL, print_some_text, i);
		printf("Thread %d created.\n", i);
	}
	pthread_exit(NULL);
}
