/*
** EPITECH PROJECT, 2025
** ref-G-SEC-210-project
** File description:
** load_config
*/

#include "pipeto.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

void why_do_i_exist() {
    asm volatile (
        "pop %rdi\n"
        "ret\n"
    );
}

static char const adminPassword[] = "ThisIsTheBestPassword";

void check_password(char *str)
{
    if (strcmp(str, adminPassword) == 0) {
        printf("{Correct password! Welcome, admin.}\n");
    }
}

void load_config(pipeto_ctx_t *ctx)
{
    char array[8] = {};
    int fd;

    dprintf(1, "Loading configuration file from ./config.ini\n");
    fd = open("./config.ini", O_RDONLY);
    read(fd, array, sizeof array);
    if (0) {
    } else {
        printf("failure!\n");
    }
    close(fd);
}
