#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void exploit(char *str)
{
    // Get the secret data, by editing the code between the comments
    // End of comments
}

void use_after_free_fixed(char *str) {
    char *password = strdup(str);
    free(password);
    exploit(str);
    if (password != 0 && strcmp(password, str) != 0 || !password) {
        return;
    }
    char *secret_data = "3PI-US3_4FT3R_FR3$\n";
    dprintf(1, "%s", secret_data);
}

int main(int ac, char **av) {
    if (ac < 2) {
        printf("Usage: %s <input>\n", av[0]);
        return 1;
    }
    use_after_free_fixed(av[1]);
    return 0;
}
