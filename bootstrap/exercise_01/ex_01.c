#include <stdio.h>

int main(int argc, char **argv) {
    if (argc != 2)
        return printf("Usage: %s <input>\n", argv[0]), 1;
    return puts(argv[1]), 0;
}
