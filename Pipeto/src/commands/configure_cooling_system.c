/*
** EPITECH PROJECT, 2024
** Pipeto
** File description:
** configure_cooling_system
*/

#include "pipeto.h"
#include <stdio.h>
#include <stdlib.h>

void configure_cooling_system(pipeto_ctx_t *ctx)
{
    char *config_file = "Data/cooling_config.txt";
    char buffer[64];
    FILE *file = fopen(config_file, "r");
    int result;

    if (!file) {
        printf("Error: Unable to open configuration file: %s\n", config_file);
        return;
    }
    printf("Reading configuration file: %s\n", config_file);
    fread(buffer, 1, sizeof(buffer) - 1, file);
    buffer[sizeof(buffer) - 1] = '\0';
    fclose(file);
    printf("Applying configuration: %s\n", buffer);
    result = system(buffer);
    if (result == 0) {
        printf("Configuration applied successfully.\n");
    } else
        printf("Failed to apply configuration. Command returned: %d\n",
            result);
}
