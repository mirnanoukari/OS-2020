#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

/*
what you type will get executed in a separate child process and printed to /dev/null (unless you specify another place)
ex: "pstree > output.txt" will print into a file then the process will go zombie
*/
int main() {	
	char command[200];	
	pid_t pid = getpid();	
	while(1) {		
		char message[256];
		printf("BackgroundShell~$: ");

		fgets(command, 200, stdin);
		strcat(message, command);

		message[strcspn(message, "\n")] = 0;
		strcat(message, " > /dev/null\n");	// add /dev/null to avoid receiving the output

		pid = fork();
		if (pid == 0) {	// if the process is the child process execute the command 
			system(message);	// otherwise continue 
			exit(0);
		}
	}

	return 0;
}
