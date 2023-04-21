#include "shell.h"
int _path()
{
    char *pathway = getenv("PATH");

    if(pathway)
        _puts(pathway);
    else
       _puts("pathway not set");
    return (0);
}
