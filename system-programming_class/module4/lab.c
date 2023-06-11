#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>


int fd_read, fd_write, fd_read2;
char buffer[BUFSIZ];

int main(){
    //2.a. open the file for reading
    if((fd_read = open("./module4/example.txt",O_RDONLY)) == -1){
        perror("Error can't open file for reading\n");
        return 1;
    }

    //2.b. open the file for writing
    if((fd_write = open("./module4/example.txt",O_WRONLY)) == -1){
        perror("Error, can't open file for writing\n");
        return 1;
    }

    //2.c. open the file for reading
    if((fd_read2 = open("./module4/example.txt",O_RDONLY)) == -1){
        perror("Error, can't open file for reading 2\n");
        return 1;
    }

    //2.d. read 50 bytes using the 1st fd and print what you get
    if(read(fd_read,buffer,50) == -1){
        printf("Error, cannot read from file descriptor\n");
        return 1;
    }
    printf("%s\n",buffer);

    //2.e. write the string "testing 1 2 3.." using the 2nd fd
    char *message = "testing 1 2 3...";
    if(write(fd_write,message,sizeof(message)) == -1){
        printf("Error, can't write into file descriptor\n");
        return 1;
    }

    //2.f. read 50 bytes using the 3rd fd and print what you get
    if(read(fd_read2,buffer,50) == -1){
        printf("Error, can't read from file descriptor\n");
        return 1;
    }
    printf("%s\n",buffer);

    close(fd_read);
    close(fd_write);
    close(fd_read2);

    return 0;
}