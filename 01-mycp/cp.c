#include "header.h"

char buffer[BUF_SZ];


int copyFile(int srcfd,int destfd);

int main(int argc, char* argv[]){
    
    if(argc != 3){
        puts("arguments should be 3");
        exit(EXIT_FAILURE);
    }

    int srcfd,destfd;
    int status = 0;

    srcfd = open(argv[1],O_RDONLY);
    if(srcfd < 0){
        perror("open src:");
        exit(EXIT_FAILURE);
    }

    destfd = open(argv[2],O_RDWR | O_CREAT | O_TRUNC, MODE);
    if(destfd < 0){
        perror("open dest: ");
        exit(EXIT_FAILURE);
    }

    status = copyFile(srcfd,destfd);
    if(status == SUCCESSFUL){
        printf("%s is copied to %s successfully\n",argv[1],argv[2]);
        exit(EXIT_SUCCESS);
    }else{
        printf("!!! FAILURE OCCURED !!!");
        exit(EXIT_FAILURE);
    }
}

int copyFile(int srcfd,int destfd){
    ssize_t n = 0;

    while((n = read(srcfd,buffer,BUF_SZ)) > 0){
        if(write(destfd,buffer,n) != n)
            perror("write");
    }
    if(n < 0){
        perror("read()");
        return FAILURE;
    }

    return SUCCESSFUL;
}