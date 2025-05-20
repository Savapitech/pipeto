/*
** EPITECH PROJECT, 2025
** __
** File description:
** _
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "history.h"

#define HISTORY_FILE ".pipeto_history"
#define MAX_HISTORY_SIZE 1000

static char **HISTORY = NULL;
static int HIS_SZ = 0;
static int HISTORY_SIZE = 0;

static
void read_file(char *line)
{
    line[strcspn(line, "\n")] = '\0';
    if (strlen(line) > 0) {
        HISTORY[HIS_SZ] = strdup(line);
        if (HISTORY[HIS_SZ])
            HIS_SZ++;
    }
}

void history_init(void)
{
    FILE *file;
    char line[MAX_COMMAND_LENGTH];

    HISTORY = malloc(sizeof(char *) * MAX_HISTORY_SIZE);
    if (!HISTORY)
        return;
    HISTORY_SIZE = MAX_HISTORY_SIZE;
    HIS_SZ = 0;
    file = fopen(HISTORY_FILE, "r");
    if (file) {
        while (fgets(line, sizeof(line), file) && HIS_SZ
            < MAX_HISTORY_SIZE) {
            read_file(line);
        }
        fclose(file);
    }
}

void history_add(const char *command)
{
    FILE *file;

    if (!command || strlen(command) == 0 ||
        (HIS_SZ > 0 && strcmp(HISTORY[HIS_SZ - 1], command) == 0))
        return;
    if (HIS_SZ == HISTORY_SIZE) {
        free(HISTORY[0]);
        for (int i = 0; i < HIS_SZ - 1; i++)
            HISTORY[i] = HISTORY[i + 1];
        HIS_SZ--;
    }
    HISTORY[HIS_SZ] = strdup(command);
    if (HISTORY[HIS_SZ])
        HIS_SZ++;
    file = fopen(HISTORY_FILE, "w");
    if (file) {
        for (int i = 0; i < HIS_SZ; i++)
            fprintf(file, "%s\n", HISTORY[i]);
        fclose(file);
    }
}

void history_clear(void)
{
    FILE *file;

    for (int i = 0; i < HIS_SZ; i++)
        free(HISTORY[i]);
    HIS_SZ = 0;
    file = fopen(HISTORY_FILE, "w");
    if (file)
        fclose(file);
}

void history_free(void)
{
    for (int i = 0; i < HIS_SZ; i++)
        free(HISTORY[i]);
    free(HISTORY);
    HISTORY = NULL;
    HIS_SZ = 0;
    HISTORY_SIZE = 0;
}

void history_show(void)
{
    for (int i = 0; i < HIS_SZ; i++)
        printf(" %d  %s\n", i + 1, HISTORY[i]);
}

const char *history_get(int index)
{
    if (index < 0 || index >= HIS_SZ)
        return NULL;
    return HISTORY[index];
}

int history_count_get(void)
{
    return HIS_SZ;
}
