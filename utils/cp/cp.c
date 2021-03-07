#include <sys/types.h>
#include <sys/fcntl.h>
#include <sys/stat.h>
#include <sys/sendfile.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	if(argc == 1) {
		printf("cp requires a file operand\n");
	} else if(argc == 2) {
		printf("cp requires a destination file operand\n");
	} else if(argc > 3) {
		printf("Too many arguments for cp\n");
	} else {
		int sf = open(argv[1], O_RDONLY);
		int df = open(argv[2], O_RDONLY);
		if(sf < 0) {
			printf("Could not find file");
		} else if(df >= 0) {
			printf("File already exists at destination");
		} else {

			//Create destination file
			df = creat(argv[2], O_WRONLY);
			if(df < 0) {
				printf("Error creating destination file");
			} else {
				struct stat statbuf;
				int status = fstat(sf, &statbuf);

				if(status == 0) {
					sendfile(df, sf, NULL, statbuf.st_size);
				} else {
					printf("Could not determine file size");
				}
				if(fchmod(df, statbuf.st_mode)) {
					printf("Failed to set file permissions");
				}
			}
		}
		close(sf);
		close(df);
	}
}
