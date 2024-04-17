#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/mman.h>
#include<sys/shm.h>
#include<sys/ipc.h>

int main() {
    void *shmptr;
    int shmid = shm_open("OS", O_RDONLY, 0666);
    ftruncate(shmid, 2048);
    shmptr = mmap(0, 2048, PROT_READ, MAP_SHARED, shmid, 0);
    printf("\nShared memory is attached at %p\n", shmptr);
    printf("\nThe string entered to the shared memory is:\n");
    printf("%s\n", (char *)shmptr);
    shm_unlink("OS");

    return 0;
}
