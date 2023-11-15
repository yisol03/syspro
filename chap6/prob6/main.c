#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argv[1] == NULL)
        perror("could not open file");

    if (link(argv[1], argv[2]) == -1)
        exit(1);

    exit(2);
}
