#include <stdio.h> 
#include <stdlib.h> 
#include <dirent.h> 
#include <sys/types.h> #include <errno.h> void list_files(const char *dir_path) {     struct dirent *entry;     DIR *dp = opendir(dir_path);     if (dp == NULL) {         perror("opendir");         return; 
    } 
    while ((entry = readdir(dp))) {         printf("%s\n", entry->d_name); 
    }     closedir(dp); 
} int main(int argc, char *argv[]) {     const char *dir_path;     if (argc > 2) {         fprintf(stderr, "Usage: %s [directory]\n", argv[0]);         return EXIT_FAILURE; 
    } 
    if (argc == 2) {         dir_path = argv[1]; 
    } else {         dir_path = "."; 
    }     list_files(dir_path); 
    return EXIT_SUCCESS; 
} 
