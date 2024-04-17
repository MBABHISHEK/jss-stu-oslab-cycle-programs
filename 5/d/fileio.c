
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<fcntl.h>
#define BUFFER_SIZE 500

int main() {
    int fd1, fd2, n;
    char buffer[BUFFER_SIZE];
    fd1 = open("sample.txt", O_RDONLY);
    fd2 = open("copy.txt", O_CREAT|O_WRONLY, 0666);
    printf("\nFile descriptor for sample.txt is %d and for copy.txt is %d\n", fd1, fd2);
    if (fd1 == -1 || fd2 == -1) {
        printf("\nFailed to open file\n");
        exit(0);
    }

    n = read(fd1, buffer, BUFFER_SIZE);
    write(fd2, buffer, n);
    printf("\nFile has been created and copied successfully\n");
    return 0;
}
