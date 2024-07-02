#include "unpipc.h"

void client(int, int), server(int, int);

int main(int argc, char const *argv[])
{
    int pipe1[2], pipe2[2];
    // pid_t int的别名
    pid_t childpid;

    Pipe(pipe1); // create two pipes
    Pipe(pipe2);
    // child
    if ((childpid = Fork()) == 0)
    {
        Close(pipe1[1]);
        Close(pipe2[0]);

        server(pipe1[0], pipe2[1]);
        exit(0);
    }
    // parent
    Close(pipe1[0]);
    Close(pipe2[1]);
    client(pipe2[0], pipe1[1]);
    // wait for child to terminate
    Waitpid(childpid, NULL, 0);

    exit(0);
}
