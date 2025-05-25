/*
** EPITECH PROJECT, 2024
** Pipeto
** File description:
** activate_emergency_protocols
*/

#include <openssl/sha.h>
#include <stdio.h>
#include <string.h>

#include "pipeto.h" // pour pipeto_ctx_t

// SHA-256 240be518fabd2724ddb6f04eeb1da5967448d7e831c08c8fa822809f74c720a9
const unsigned char ADMIN_HASH[32] = {
    0x24, 0x0b, 0xe5, 0x18, 0xfa, 0xbd, 0x27, 0x24,
    0xdd, 0xb6, 0xf0, 0x4e, 0xeb, 0x1d, 0xa5, 0x96,
    0x74, 0x48, 0xd7, 0xe8, 0x31, 0xc0, 0x8c, 0x8f,
    0xa8, 0x22, 0x80, 0x9f, 0x74, 0xc7, 0x20, 0xa9
};

void activate_emergency_protocols(pipeto_ctx_t *ctx)
{
    char input[128];
    unsigned char hash[SHA256_DIGEST_LENGTH];

    printf("Enter emergency password: ");
    if (!fgets(input, sizeof(input), stdin))
        return;
    input[strcspn(input, "\n")] = 0;
    SHA256((unsigned char *)input, strlen(input), hash);
    if (memcmp(hash, ADMIN_HASH, SHA256_DIGEST_LENGTH) == 0) {
        ctx->is_admin = true;
        puts("{Emergency protocols activated, you are now admin !}");
    } else {
        puts("Incorrect password.");
    }
}
