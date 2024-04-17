//Headers to be included
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/ipc.h>

int main() {
    void *shmptr;
    char buffer[25];
    int shmid = shmget((key_t)1122, 2048, 0666);
    printf("Key of the shared memory is %d\n", shmid);
    shmptr = shmat(shmid, NULL, 0666);
    printf("The memory is attached at %p\n", shmptr);
    printf("\nThe data read from the shared memory is %s\n", (char *)shmptr);
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}
