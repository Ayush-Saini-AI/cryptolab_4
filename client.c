#include <stdio.h>
#include <winsock2.h>
#include <string.h>
#include "des_util.h"

#pragma comment(lib,"ws2_32.lib")

int main() {
    WSADATA wsa;
    SOCKET s;
    struct sockaddr_in addr;
    unsigned char msg[1024];
    unsigned char key[8] = "DESKEY12";

    WSAStartup(MAKEWORD(2,2), &wsa);
    s = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons(8080);

    connect(s, (struct sockaddr*)&addr, sizeof(addr));

    printf("[CLIENT] Enter message: ");
    fgets((char*)msg, sizeof(msg), stdin);

    int len = strlen((char*)msg);
    des_encrypt(msg, len, key);

    send(s, (char*)msg, len, 0);
    printf("[CLIENT] Encrypted data sent.\n");

    closesocket(s);
    WSACleanup();
    return 0;
}
