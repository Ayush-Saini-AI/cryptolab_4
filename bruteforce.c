#include <stdio.h>
#include <string.h>
void sdes(char *data, char *key) {
    for (int i = 0; i < 8; i++)
        data[i] = (data[i] == key[i % 10]) ? '0' : '1';
}
void int_to_bin(int n, char *bin) {
    for (int i = 9; i >= 0; i--) {
        bin[i] = (n % 2) + '0';
        n /= 2;
    }
    bin[10] = '\0';
}
int main() {
    char encrypted[9];
    printf("Enter captured encrypted data: ");
    scanf("%s", encrypted);
    for (int i = 0; i < 1024; i++) {
        char key[11], temp[9];
        int_to_bin(i, key);
        strcpy(temp, encrypted);
        sdes(temp, key);
        printf("Key: %s -> Plaintext: %s\n", key, temp);
    }
    return 0;
}
