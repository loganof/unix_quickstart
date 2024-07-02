#include "unpipc.h"

int main(int argc, char const *argv[])
{
    size_t n;
    char buff[MAXLINE], command[MAXLINE];
    FILE *fp;

    Fgets(buff, MAXLINE, stdin);
    n = strlen(buff);
    if (buff[n - 1] == '\n')
        n--; // delete \n
    snprintf(command, sizeof(command), "cat %s", buff);
    fp = Popen(command, "r");
    while (Fgets(buff, MAXLINE, fp) != NULL)
        Fputs(buff, stdout);

    Pclose(fp);
    return 0;
}
