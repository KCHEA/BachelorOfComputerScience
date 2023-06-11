#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
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
    if(write(fd_write,message,strlen(message)) == -1){
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
    
    //3.Read data past the end of the file by 100 bytes, write to it and check its size
    if((fd_read = open("./module4/example.txt",O_RDONLY)) == -1){
        printf("Error opening file for reading\n");
        return 1;
    }
    char buf[BUFSIZ];
    if(lseek(fd_read,100,SEEK_END) == -1){
        printf("Cannot set position to 100 bytes past end of the file\n");
        close(fd_read);
        return 1;
    }
    if(read(fd_read,buf,50) == -1){
        printf("Error reading 50 bytes after end of the file\n");
        close(fd_read);
        return 1;
    }
    close(fd_read);
    printf("%s\n",buf); //reading 50 bytes past 100 bytes of the end of file return an empty string

    if((fd_write = open("./module4/example.txt",O_WRONLY)) == -1){
        printf("Error opening file for writing\n");
        return 1;
    }
    if(lseek(fd_write,100,SEEK_END) == -1){
        printf("Error setting position 100 bytes past end of file\n");
        return 1;
    }
    char *string = "hello";
    if(write(fd_write,string,strlen(string)) == -1){
        printf("Error writing past end of file\n");
        return 1;
    }
    close(fd_write); //when writing past a certain bytes into a file the space in between will be NULL bytes or NULL character

    return 0;
}