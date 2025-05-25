/*
** EPITECH PROJECT, 2024
** Pepito library
** File description:
** turbine_temperature
*/

#include "pepito.h"

void turbine_temperature() {
    char input[128];
    long long degress;
    
    printf("Enter the number of degrees you want to increase or decrease the turbine temperature : ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    degrees = strtoll(input, NULL, 10);
    if (degrees == INT_MAX - 1 || degrees == INT_MIN + 1) {
        printf("Turbine temperature is too unstable.\n");
        printf("{ERR0R TURBINE WILL EXPLODE}\n");
        exit(1);
    }
    printf("Turbine temperature is %d degrees.\n", 20);
    if (degrees < 0) {
        printf("Turbine temperature is decreasing : %lld\n", (20 + degrees));
        return;
    }
    if (degrees > 0) {
        printf("Turbine temperature is increasing : %lld\n", (20 + degrees));
        return;
    }
}
