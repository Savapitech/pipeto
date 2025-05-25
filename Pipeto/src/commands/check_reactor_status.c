/*
** EPITECH PROJECT, 2025
** __
** File description:
** _
*/

#include "pipeto.h"
#include <openssl/evp.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void encrypt_message_openssl(const char *plaintext,
    unsigned char *ciphertext, int *len)
{
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    const unsigned char key[32] = "my_very_secret_encryption_key_!";
    const unsigned char iv[17] = "initial_vector_iv";
    int len_out;
    int ciphertext_len;

    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);
    EVP_EncryptUpdate(ctx, ciphertext, &len_out,
        (const unsigned char *)plaintext, strlen(plaintext));
    ciphertext_len = len_out;
    EVP_EncryptFinal_ex(ctx, ciphertext + len_out, &len_out);
    ciphertext_len += len_out;
    *len = ciphertext_len;
    EVP_CIPHER_CTX_free(ctx);
}

void check_reactor_status(pipeto_ctx_t *ctx)
{
    const char *message = "ReactorStatusOK";
    unsigned char encrypted[128] = {0};
    int encrypted_len;

    printf("Starting reactor status check...\n");
    sleep(1);
    printf("Checking core temperature...\n");
    sleep(1);
    printf("Core temperature: Normal\n");
    sleep(1);
    printf("Checking coolant flow rate...\n");
    sleep(1);
    printf("Coolant flow rate: Stable\n");
    sleep(1);
    printf("Checking radiation levels...\n");
    sleep(2);
    printf("Radiation levels: Safe\n\n");
    printf("Encrypting critical reactor data...\n");
    encrypt_message_openssl(message, encrypted, &encrypted_len);
    sleep(1);
    printf("Encrypted message: ");
    for (int i = 0; i < encrypted_len; i++)
        printf("%02x", encrypted[i]);
    printf("\n\n");
    printf("Reactor status: OK\n");
    printf("Reactor status check complete.\n\n");
}
