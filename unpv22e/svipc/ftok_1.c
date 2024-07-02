#include "unpipc.h"

int main(int argc, char const *argv[])
{
    struct stat stat;

    if (argc != 2)
    {
        err_quit("usage: ftok <pathname>");
    }

    Stat(argv[1], &stat);
    print("st_dev: %lx, st_ino: %lx, key: %x\n",
          (u_long)stat.st_dev, (u_long)stat.st_ino,
          Ftok(argv[1], 0x57));

    // return 0;
    exit(0);
}
