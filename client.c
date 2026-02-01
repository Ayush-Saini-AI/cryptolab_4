#include <stdio.h>
#include <string.h>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")
#define PORT 8080
void pad(char *input, char *output) {
    int len = strlen(input);
    strncpy(output, input, 8);
    for (int i = len; i < 8; i++)
        output[i] = '0';
    output[8] = '\0';
}
void sdes(char *data, char *key) {
    for (int i = 0; i < 8; i++)
        data[i] = (data[i] == key[i % 10]) ? '0' : '1';
}
int main() {
    WSADATA wsa;
    SOCKET sock;
    struct sockaddr_in server;
    char input[50], data[9];
    char key[11] = "1010000010";
    printf("Enter binary data: ");
    scanf("%s", input);
    pad(input, data);
    printf("Padded data: %s\n", data);
    sdes(data, key);
    printf("Encrypted data: %s\n", data);
    WSAStartup(MAKEWORD(2,2), &wsa);
    sock = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    connect(sock, (struct sockaddr*)&server, sizeof(server));
    send(sock, data, 8, 0);
    closesocket(sock);
    WSACleanup();
    return 0;
}
