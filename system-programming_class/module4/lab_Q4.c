#include        <stdio.h>
#include        <unistd.h>
#include        <fcntl.h>
#include        <stdlib.h>

#define BUFFERSIZE      4096
#define COPYMODE        0644

void oops(char *, char *);
main(int ac, char *av[])
{
    //4.If you try to cp file file the os will tell you that they are the same file

    int     in_fd, out_fd, n_chars;
    char    buf[BUFFERSIZE];
                                                /* check args   */
    if ( ac != 3 ){
        fprintf( stderr, "usage: %s source destination\n", *av);
        exit(1);
    }
                                                /* open files   */
    //We need to check if the two file attribute are the same by using lstat(), if they are then they are the same file
    struct stat stat_source, stat_dest;
    if (lstat(av[1], &stat_source) == -1)
        oops("Cannot get stat for ", av[1]);
    if (lstat(av[2], &stat_dest) == -1)
        oops("Cannot get stat for ", av[2]);

    if (stat_source.st_dev == stat_dest.st_dev && stat_source.st_ino == stat_dest.st_ino) {
        printf("%s and %s are the same file\n", av[1], av[2]);
        exit(1);
    }

    if ( (in_fd=open(av[1], O_RDONLY)) == -1 )
        oops("Cannot open ", av[1]);

    if ( (out_fd=creat( av[2], COPYMODE)) == -1 )
        oops( "Cannot creat", av[2]);

                                                /* copy files   */
while ( (n_chars = read(in_fd , buf, BUFFERSIZE)) > 0 )
        if ( write( out_fd, buf, n_chars ) != n_chars )
                oops("Write error to ", av[2]);
        if ( n_chars == -1 )
                oops("Read error from ", av[1]);

                                                /* close files  */

 if ( close(in_fd) == -1 || close(out_fd) == -1 )
                oops("Error closing files","");
}

void oops(char *s1, char *s2)
{
        fprintf(stderr,"Error: %s ", s1);
        perror(s2);
        exit(1);
}
