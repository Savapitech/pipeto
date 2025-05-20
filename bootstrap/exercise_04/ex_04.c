#include <stdio.h>
#include <stdlib.h>

void vulnerable_command(char *input) {
    char command[50];
    sprintf(command, "ls %s", input);
    system(command);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }
    vulnerable_command(argv[1]);
    return 0;
}
