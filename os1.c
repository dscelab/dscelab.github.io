#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

int main()
{
    char dirname[10];
    DIR *p;
    struct dirent *d;

    printf("Enter directory name\n");
    scanf("%s", dirname);

    p = opendir(dirname);
    if (p == NULL)
    {
        perror("cannot find directory!");
    }

    while ((d = readdir(p)) != NULL)
    {
        printf("%s\n", d->d_name);
    }

    return 0;
}




#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int f1, f2;
    char buff[50];
    long int n;

    if (((f1 = open(argv[1], O_RDONLY)) == -1 || (f2 = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0700)) == 1))
    {
        perror("problem in file");
        exit(1);
    }

    while ((n = read(f1, buff, 50)) > 0)
    {
        if (write(f2, buff, n) != n)
        {
            perror("problem in writing");
            exit(3);
        }
    }

    if (n == -1)
    {
        perror("problem in reading");
        exit(2);
    }

    close(f2);
    exit(0);
}
