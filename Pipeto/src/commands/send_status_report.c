/*
** EPITECH PROJECT, 2024
** Pipeto
** File description:
** send_status_report
*/

#include "openssl/sha.h"
#include "pipeto.h"
#include <stdbool.h>
#include <stdio.h>

void send_status_report(pipeto_ctx_t *ctx)
{
    FILE *file = fopen("Data/status_report.txt", "w");
    char encoded_report[SHA256_DIGEST_LENGTH];
    char report[256];
    const char *hostname = "localhost";
    const char *ip_address = "127.0.0.1";
    const char *process_info = "Process: pipeto (PID: 1234)";

    if (!file) {
        printf("Error: Unable to create a file in Data/, "
            "you must create a Data folder.\n");
        return;
    }
    snprintf(report, sizeof(report), "Hostname: %s\nIP Address: %s\n%s\n",
        hostname, ip_address, process_info);
    base64_encode(report, encoded_report);
    SHA256((unsigned char *)report, strlen(report), encoded_report);
    fprintf(file, "Encoded Status Report:\n%s\n", encoded_report);
    fclose(file);
    printf("Status report sent and saved to 'Data/status_report.txt'.\n");
}
