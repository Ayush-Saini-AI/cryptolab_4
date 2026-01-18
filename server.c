#include <stdio.h>
#include <winsock2.h>
#include "des_util.h"

#pragma comment(lib,"ws2_32.lib")

int main() {
    WSADATA wsa;
    SOCKET s, c;
    struct sockaddr_in addr;
    unsigned char buffer[1024];
    unsigned char key[8] = "DESKEY12";

    WSAStartup(MAKEWORD(2,2), &wsa);
    s = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(8080);

    bind(s, (struct sockaddr*)&addr, sizeof(addr));
    listen(s, 1);

    printf("[SERVER] Waiting...\n");
    c = accept(s, NULL, NULL);

    int len = recv(c, (char*)buffer, sizeof(buffer), 0);

    printf("[SERVER] Ciphertext (hex): ");
    for(int i=0;i<len;i++) printf("%02X ", buffer[i]);
    printf("\n");

    des_decrypt(buffer, len, key);

    printf("[SERVER] Decrypted text: %s\n", buffer);

    closesocket(c);
    closesocket(s);
    WSACleanup();
    return 0;
}
