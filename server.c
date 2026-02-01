#include <stdio.h>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")
#define PORT 8080
void sdes(char *data, char *key) {
    for (int i = 0; i < 8; i++)
        data[i] = (data[i] == key[i % 10]) ? '0' : '1';
}
int main() {
    WSADATA wsa;
    SOCKET server_socket, client_socket;
    struct sockaddr_in server;
    char encrypted[9];
    char key[11] = "1010000010";
    WSAStartup(MAKEWORD(2,2), &wsa);
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);
    bind(server_socket, (struct sockaddr*)&server, sizeof(server));
    listen(server_socket, 3);
    printf("Server waiting...\n");
    client_socket = accept(server_socket, NULL, NULL);
    recv(client_socket, encrypted, 8, 0);
    encrypted[8] = '\0';
    printf("Encrypted data received: %s\n", encrypted);
    sdes(encrypted, key);
    printf("Decrypted data: %s\n", encrypted);
    closesocket(client_socket);
    closesocket(server_socket);
    WSACleanup();
    return 0;
}
