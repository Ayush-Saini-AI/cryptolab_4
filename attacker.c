#include <stdio.h>
#include <string.h>
#include "des_util.h"

int main() {
    unsigned char intercepted[8] = { /* paste ciphertext from Wireshark */ };
    unsigned char trial_key[8] = {0};
    unsigned char out[8];

    printf("[ATTACKER] Starting limited brute force...\n");

    for(int k=0; k<100000; k++) {  // VERY small search space
        memset(trial_key, 0, 8);
        trial_key[7] = k & 0xFF;

        memcpy(out, intercepted, 8);
        des_decrypt(out, 8, trial_key);

        if(out[0] >= 'A' && out[0] <= 'Z') {
            printf("Key tried: %02X | Output: %c...\n", trial_key[7], out[0]);
        }
    }

    printf("[ATTACKER] Failed to crack DES in feasible time.\n");
    return 0;
}
