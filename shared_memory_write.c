

#include <stdio.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <stdlib.h>

#define MAX_LEN 80
#define SHM_KEY 0x1234

int main(int argc, char **argv)
{

    int shm_id = shmget(SHM_KEY, 4096, IPC_CREAT | 0666);
    if (shm_id < 0)
    {
        perror("shmget");
        exit(1);
    }

    char *buff = shmat(shm_id, NULL, 0);

    if (fgets(buff, MAX_LEN, stdin) == NULL)
    {
        perror("fgets");
        exit(1);
    }

    if (shmdt(buff) < 0)
    {
        perror("shmdt");
        exit(1);
    }
    else
    {
        printf("Memory detached\n");
    }
            
    return 0;
}