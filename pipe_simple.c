#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define LEN 50


int main(int argc, char **argv)
{
    if (argc != 2 || (strcmp(argv[1], "read") != 0 && strcmp(argv[1], "write") != 0))
    {
        printf("Usage: %s <read|write>\n", argv[0]);
        return 1;
    }
    int fds[2];

    char buffer[LEN];
    char buffer_out[LEN];

    int ret = pipe(fds);

    char *str = fgets(buffer, LEN, stdin);

    write(fds[1], str, LEN);

    read(fds[0], buffer_out, LEN);

    printf("%s\n", buffer_out);
    return 0;
}

