/*
** EPITECH PROJECT, 2025
** __
** File description:
** _
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#include "ansicolors.h"

void write_color(int fd, const char *color, const char *str)
{
    if (fd < 0 || !color || !str)
        return;
    dprintf(fd, "%s%s%s", color, str, CRESET);
}

void load_pipetorc(void)
{
    FILE *rc_file;
    char *home;
    char line[1024];
    char cmd[1100];
    char home_rc[1024];

    rc_file = fopen(".pipetorc", "r");
    if (!rc_file) {
        home = getenv("HOME");
        if (home) {
            snprintf(home_rc, sizeof(home_rc), "%s/.pipetorc", home);
            rc_file = fopen(home_rc, "r");
        }
    }
    if (!rc_file) {
        return;
    }
    while (fgets(line, sizeof(line), rc_file)) {
        if (line[0] == '#' || line[0] == '\n') {
            continue;
        }
        line[strcspn(line, "\n")] = '\0';
        if (strncmp(line, "exec ", 5) == 0) {
            snprintf(cmd, sizeof(cmd), "%s", line + 5);
            system(cmd);
        } else {
            printf("Pipeto command: ");
            printf("%s", line);
            printf("\n");
        }
    }
    fclose(rc_file);
}
