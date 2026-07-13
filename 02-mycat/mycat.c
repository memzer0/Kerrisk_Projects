#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SZ          4096

int main(int argc, char* argv[]){
    if(argc == 1){
        puts("need more than one argument");
        exit(EXIT_SUCCESS);
    }

    ssize_t n = 0;
    int fd = 0;
    char buffer[BUF_SZ];
    
    for(int i = 1; i <= argc; i++){
        fd = open(argv[i],O_RDONLY);
        if(fd < 0){
            perror("open()");
            exit(EXIT_FAILURE);
        }

        while((n = read(fd,buffer,BUF_SZ)) > 0)
            if(write(STDOUT_FILENO,buffer,n) != n)
                perror("write");

        if(n < 0){
            perror("read");
            exit(EXIT_FAILURE);
        }
        close(fd);
    }
   exit(EXIT_SUCCESS);
    
}
