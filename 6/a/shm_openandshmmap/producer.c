

//Header files to be linked
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h> //POSIX Library is linked
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/shm.h>
#include<sys/mman.h>
#include<sys/ipc.h>

int main() {
    void *shmptr;
    char buffer[25];
    int shmid;
    shmid = shm_open("OS", O_CREAT|O_RDWR, 0666);
    ftruncate(shmid, 2048);
    shmptr = mmap(0, 2048, PROT_WRITE, MAP_SHARED, shmid, 0);
    printf("\nKey/Id/Fd of the shared memory is %d\n", shmid);
    printf("Shared memory is attached at %p\n", shmptr);
    printf("\nEnter the string to be written into the shared memory:\n");
    read(0, buffer, 25);
    sprintf(shmptr, "%s", buffer);

    return 0;
}
