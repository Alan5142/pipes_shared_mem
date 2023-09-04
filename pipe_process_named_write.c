#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#define LEN 50

int main(int argc, char **argv)
{
    int fdp = mkfifo("/tmp/myfifo", 0666);
    
    int fd = open("/tmp/myfifo", O_WRONLY);

    char buffer[LEN];

    while (1)
    {
        char *str = fgets(buffer, LEN, stdin);
        write(fd, str, LEN);
    }

    close(fd);

    return 0;
}

