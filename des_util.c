#include "des_util.h"
#include "des.h"
#include <string.h>

void des_encrypt(unsigned char *data, size_t length, const unsigned char key[8]) {
    DES_key des_key;
    memcpy(des_key, key, 8);

    for (size_t i = 0; i < length; i += 8) {
        unsigned char block[8] = {0};
        size_t bs = (i + 8 <= length) ? 8 : length - i;
        memcpy(block, data + i, bs);
        des_encrypt_block(block, block, des_key);
        memcpy(data + i, block, bs);
    }
}

void des_decrypt(unsigned char *data, size_t length, const unsigned char key[8]) {
    DES_key des_key;
    memcpy(des_key, key, 8);

    for (size_t i = 0; i < length; i += 8) {
        unsigned char block[8] = {0};
        size_t bs = (i + 8 <= length) ? 8 : length - i;
        memcpy(block, data + i, bs);
        des_decrypt_block(block, block, des_key);
        memcpy(data + i, block, bs);
    }
}
