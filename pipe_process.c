#include <unistd.h>
#include <stdio.h>
#include <sys/types.h> 
#include <sys/wait.h>

#define LEN 50

static void parent_process(int fd)
{
    char buffer[LEN];

    while (fgets(buffer, LEN, stdin) != NULL)
    {
        write(fd, buffer, LEN);
    }

    int ret = wait(NULL);
}

static void child_process(int fd)
{
    char buffer[LEN];

    while (read(fd, buffer, LEN) > 0)
    {
        printf("%s", buffer);
    }
}

int main(int argc, char **argv)
{
    int fds[2];

    int ret = pipe(fds);

    pid_t pid = fork();

    if (pid == 0) 
    {
        child_process(fds[0]);
    }
    else
    {
        parent_process(fds[1]);
    }
    return 0;
}

