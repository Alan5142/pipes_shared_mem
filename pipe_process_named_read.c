#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define LEN 50

int main(int argc, char **argv)
{    
    int fd = open("/tmp/myfifo", O_RDONLY);

    char buffer[LEN];

    while (read(fd, buffer, LEN) > 0)
    {
        printf("%s", buffer);
    }

    close(fd);

    return 0;
}

