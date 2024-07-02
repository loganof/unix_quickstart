#include "unpipc.h"

int main(int argc, char const *argv[])
{
    int fd[2], n;
    char c;
    pid_t childpid;

    Pipe(fd); // assume a full-duplex pipe
    if ((childpid = Fork()) == 0)
    {
        sleep(3);
        if ((n = Read(fd[0], &c, 1)) != 1)
            err_quit("child: read returned %d", n);
        printf("child read %c\n", c);
        Write(fd[0], "c", 1);
        exit(0);
    }
    // parent
    Write(fd[1], "p", 1);
    if ((n = Read(fd[1], &c, 1)) != 1)
        err_quit("parent: read returned %d\n", n);
    printf("parent read %c\n", c);
    return 0;
}
