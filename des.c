#include "des.h"
#include <string.h>
#include <stdio.h>

// Simple placeholder permutation/substitution for demonstration
// Not secure for real cryptography

static void simple_xor(uint8_t a[DES_BLOCK_SIZE], const uint8_t b[DES_BLOCK_SIZE]) {
    for(int i=0;i<DES_BLOCK_SIZE;i++)
        a[i] ^= b[i];
}

void des_encrypt_block(const uint8_t input[DES_BLOCK_SIZE], uint8_t output[DES_BLOCK_SIZE], const DES_key key) {
    memcpy(output, input, DES_BLOCK_SIZE);
    // Simple "encryption": XOR with key
    simple_xor(output, key);
}

void des_decrypt_block(const uint8_t input[DES_BLOCK_SIZE], uint8_t output[DES_BLOCK_SIZE], const DES_key key) {
    memcpy(output, input, DES_BLOCK_SIZE);
    // Simple "decryption": XOR with key (same as encryption)
    simple_xor(output, key);
}

// Optional: test main
#ifdef DES_TEST
int main() {
    DES_key key = {0x13,0x34,0x57,0x79,0x9B,0xBC,0xDF,0xF1};
    uint8_t plaintext[DES_BLOCK_SIZE] = "ABCDEFGH";
    uint8_t ciphertext[DES_BLOCK_SIZE];
    uint8_t decrypted[DES_BLOCK_SIZE];

    des_encrypt_block(plaintext, ciphertext, key);
    des_decrypt_block(ciphertext, decrypted, key);

    printf("Plaintext:  %s\n", plaintext);
    printf("Ciphertext: ");
    for(int i=0;i<DES_BLOCK_SIZE;i++) printf("%02X ", ciphertext[i]);
    printf("\nDecrypted:  %s\n", decrypted);

    return 0;
}
#endif
