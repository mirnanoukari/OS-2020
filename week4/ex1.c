#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/*

The fork() creates a copy of the process that was executing. The fork() is called once but returns twice (once in the parent and once in the child).
Process IDs may be the one assigned to the parent or the child. Due to the fact that these processes are run concurrently, their output lines are intermixed in a rather unpredictable way. Moreover, the order of these lines are determined by the CPU scheduler. Hence, if you run this program again, you may get a totally different result.
*/
int main(){
	int n = 0;
	if (fork() == 0){
		printf("Hello from child [%d - %d]\n",getpid(),n);
	}else{
		printf("Hello from parent [%d - %d]\n",getpid(),n);
	}
}
