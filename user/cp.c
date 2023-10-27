#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fcntl.h"

char buffer[512];

void cp(int fd1, int fd2)
{
    int n;

    while ((n = read(fd1, buffer, sizeof(buffer))) > 0)
    {
        if (write(fd2, buffer, n) != n)
        {
            fprintf(2, "cp: write error\n");
            exit(1);
        }
    }
    if (n < 0)
    {
        fprintf(2, "cp: read error\n");
        exit(1);
    }
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(2, "Invalid usage!\n");
        exit(1);
    }

    int src = open(argv[1], O_RDONLY); // TU upravte kod
    int des = open(argv[2], O_WRONLY | O_CREATE);
    // TU upravte kod

    if (src < 0 || des < 0)
    {
        fprintf(2, "Error read file or files");
        exit(1);
    }
    else
    {
        cp(src, des);
    }

    // TU doplnte kod

    exit(0);
}