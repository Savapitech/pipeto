/*
** EPITECH PROJECT, 2024
** Pipeto
** File description:
** monitor_radiation_levels
*/

#include "pipeto.h"
#include <stdio.h>
#include <string.h>
void secret_function(void)
{
    printf("{The stone isn't in the pocket anymore ...}\n");
}

void monitor_radiation_levels(pipeto_ctx_t *ctx)
{
    char buffer[10];
    void(*function_ptr)(void) = NULL;

    printf("Enter radiation levels: ");
    fgets(buffer, sizeof buffer, stdin);
    printf("Radiation Levels: %s\n", buffer);
    if (function_ptr)
        function_ptr();
    else
        printf("Function Pointer: %p\n", (void *)function_ptr);
}
