/*
** EPITECH PROJECT, 2024
** Pipeto
** File description:
** check_cooling_pressure
*/

#include "pipeto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void load_data(char *data)
{
    strcpy(data, "Pressure OK");
}

static void log_pressure_status(const char *status)
{
    printf("Cooling pressure status: %s\n", status);
}

static void simulate_sensor_reading(void)
{
    printf("Simulating sensor reading...\n");
    sleep(1);
    printf("Sensor reading complete.\n");
}

void check_cooling_pressure(pipeto_ctx_t *ctx)
{
    char *data = (char *)malloc(16);
    char sensitive_info[32] = "{Sensitive Data}";
    char temp_buffer[32];

    load_data(data);
    printf("Cooling pressure check in progress...\n");
    sleep(2);
    simulate_sensor_reading();
    printf("Checking cooling pressure...\n");
    sleep(1);
    log_pressure_status(data);
    sleep(3);
    if (strcmp(data, "Pressure OK") != 0)
        printf("Sensitive Info: %s\n", sensitive_info);
    snprintf(temp_buffer, sizeof temp_buffer,
        "Temporary data: %d", rand() % 100);
    printf("Temporary buffer: %s\n", temp_buffer);
    simulate_sensor_reading();
    printf("Cooling pressure check complete.\n");
    free(data);
}
