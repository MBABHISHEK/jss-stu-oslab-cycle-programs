#include <stdio.h> 
#include <stdlib.h> #include <sys/stat.h> 
void print_usage(const char *prog_name) {     printf("Usage: %s <permissions> <file>\n", prog_name);     printf("Example: %s 755 example.txt\n", prog_name); 
} 
int main(int argc, char *argv[]) {     if (argc != 3) {         print_usage(argv[0]);         return 1; 
    } 
    char *permissions_str = argv[1];     char *file = argv[2];     mode_t permissions = strtol(permissions_str, NULL, 8);     if (permissions == 0 && permissions_str[0] != '0') {         perror("Invalid permissions");         return 1; 
    } 
    if (chmod(file, permissions) == -1) {         perror("chmod failed");         return 1; 
    } 
    printf("Permissions of '%s' changed to '%s'\n", file, permissions_str);     return 0; 
} 
