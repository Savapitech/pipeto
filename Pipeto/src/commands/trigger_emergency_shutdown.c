/*
** EPITECH PROJECT, 2024
** Pipeto
** File description:
** trigger_emergency_shutdown
*/

#include <stdio.h>
#include <stdlib.h>

#include "pipeto.h"

void trigger_emergency_shutdown(pipeto_ctx_t *ctx)
{
    if (!ctx->is_admin) {
        printf("You are not authorized to trigger an emergency shutdown.\n");
        return;
    }
    printf("{SHUTDOWN}");
    exit(0);
}
