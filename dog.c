#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <err.h>
#include <fcntl.h>
#include <unistd.h>  
#include <string.h>
#include <stdint.h>
                                 
int main(int argc, char* argv[]) {                              // parameters are the int argc and char* argv
    int fd;                                       	            // file descriptor
	int bUFSIZ = 3000;                               	        // buffer size
	uint8_t buf[bUFSIZ];                                        // buffer and uint8_t helps with binary files
	int read_size;                                              // reads size of input
	int read_file_size;                                         // reads size of the file.
	if(argc < 2) {                                              // if argc is null
		while ((read_size = read(STDIN_FILENO, buf, bUFSIZ))) { // while loop reads stdin and writes it out. 
			write(1, buf, read_size);                           // Buffer increases based on size of read.
			memset(buf, 0, bUFSIZ);                             // copies the characters of stdin to buf for bUFSIZ
		}
	}
 	for(size_t i = (size_t)argc-1; i > 0; --i) {                // opens files in reverse order till we get to dog.c arg
		//printf("0");
		//printf("%s", argv[i]);                                // will read multiple files by iterating
		//const char file = argv[i];    	                    // then it should stop.
		if (*argv[i] == '-') {       		                    // if one of the names is '-', read from stdin
			while ((read_size = read(STDIN_FILENO, buf, bUFSIZ))) {
				write(1, buf, read_size);
				memset(buf, 0, bUFSIZ);
				//printf("0");
			}
		} 
		else { 
			fd = open(argv[i], O_RDONLY);	          	         // opens file
			if (fd == -1) {
        		err(1, argv[i]);   	                             // Will display error message
				//printf("0");
		    }                                                    // fail = -1 and success = 0
			
			while ((read_file_size = read(fd, buf, bUFSIZ))) {
				write(1, buf, read_file_size);
				memset(buf, fd, bUFSIZ);
				//printf("0");
			}
			close(fd);
		}                            		   		             
	
	}
}
