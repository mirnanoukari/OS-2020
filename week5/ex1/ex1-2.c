#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

#define N 10

void * print_some_text(void* i) {
	printf("Printing some text from thread %d with number %d\n", (int) pthread_self(), *(int*)(i));
	pthread_exit(NULL);
	
}

int main() {
	pthread_t threads[N];
	for (int i = 0; i < N; i++) {
		pthread_create(&threads[i], NULL, print_some_text, &i);
		printf("Thread %d created.\n", i);
		pthread_join(threads[i], NULL);
	}
	pthread_exit(NULL);
}
