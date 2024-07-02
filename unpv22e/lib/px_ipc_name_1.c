#include "unpipc.h"

char *px_pc_name(const char *name)
{
    char *dir, *dst, *slash;

    if ((dst = malloc(PATH_MAX)) == NULL)
    {
        return (NULL);
    }

    if ((dir = getenv("PX_IPC_NAME")) == NULL)
    {
#ifdef POSIX_IPC_PREFIX
        dir = POSIX_IPC_PREFIX;
#else
        dir = "/tmp/";
#endif
    }
    // dir must end in a slash
    slash = (dir[strlen(dir) - 1] == '/') ? "" : "/";
    // sprintf,不检查
    snprintf(dst, PATH_MAX, "%s%s%s", dir, slash, name);

    return (dst);
}