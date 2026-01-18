#ifndef DES_H
#define DES_H

#include <stdint.h>

#define DES_BLOCK_SIZE 8

// Key type
typedef uint8_t DES_key[8];

// Encrypt/Decrypt one block (8 bytes)
void des_encrypt_block(const uint8_t input[DES_BLOCK_SIZE], uint8_t output[DES_BLOCK_SIZE], const DES_key key);
void des_decrypt_block(const uint8_t input[DES_BLOCK_SIZE], uint8_t output[DES_BLOCK_SIZE], const DES_key key);

#endif // DES_H
