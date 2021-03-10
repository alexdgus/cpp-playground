#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int i = 0;

int main(int argc, char* argv[]) {
	int* value_ptr;
	pid_t pid = fork();

	value_ptr = (int*)malloc(sizeof(int));
	*value_ptr = 12;

	if(pid < 0) {
		printf("Error");
		return 1;
	} else if(pid == 0) {
		// Child Process
		for(int j = 0; j < 5; j++) {
			i += 5;
			printf("Child process: %i\n", i);
		}
		*value_ptr = 13;
		printf("Child process value_ptr: %p, value: %i\n", value_ptr, *value_ptr);
		sleep(10);
	} else {
		// Parent Process
		for(int j = 0; j < 5; j++) {
			i += 1;
			printf("Parent process: %i\n", i);
		}
		printf("Parent process value_ptr: %p, value: %i\n", value_ptr, *value_ptr);
		sleep(5);
	}
	return 0;
}

