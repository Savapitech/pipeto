/*
** EPITECH PROJECT, 2024
** Pipeto
** File description:
** log_system_events
*/

#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#include "pipeto.h"

void log_system_event(pipeto_ctx_t *ctx[[gnu::unused]])
{
    char command[100];
    char input[100];
    char secret_key[32] = "{SECRET_LOG_12PIERRE34}";
    FILE *log;
    int fd;

    printf("Enter command: ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%99s", command);
    log = fopen("Data/system.log", "a");
    if (!log) {
        printf("Error: Unable to open log file 'Data/system.log'.\n");
        return;
    }
    fd = fileno(log);
    if (fd < 0)
        return;
    flock(fd, LOCK_EX);
    printf("Logging event: %s\n", input);
    fprintf(log, "EVENT: %s\n", input);
    if (strstr(input, "leak"))
        fprintf(log, "SECRET_KEY_LEAKED: %s\n", secret_key);
    fclose(log);
}
