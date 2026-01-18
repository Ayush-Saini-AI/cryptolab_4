#ifndef DES_UTIL_H
#define DES_UTIL_H

#include <stddef.h>

void des_encrypt(unsigned char *data, size_t length, const unsigned char key[8]);
void des_decrypt(unsigned char *data, size_t length, const unsigned char key[8]);

#endif
