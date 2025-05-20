/*
** EPITECH PROJECT, 2024
** Pipeto
** File description:
** unlock_secret_mode
*/

#include <stdbool.h>
#include <stdio.h>

#include "pipeto.h"

void unlock_secret_mode(void)
{
    if (IS_ADMIN) {
        printf("Secret mode unlocked! Welcome, admin.\n");
        printf("{ADMIN4242}\n");
    } else {
        printf("Access denied. You do not have the required privileges.\n");
    }
}
