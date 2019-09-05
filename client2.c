#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main()
{
    int sock;
    char buf[] = "HI!\n";
    struct sockaddr_in addr;
    socklen_t size = 1;
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if(sock < 0)
    {
        perror("sock");
        exit(-1);
    }
    addr.sin_family = AF_INET;
    addr.sin_port = htons(3936);
    addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    sendto(sock, buf, sizeof(buf), MSG_CONFIRM, (struct sockaddr *)&addr, sizeof(addr));
    printf("client out\n");
    close(sock);
    exit(0);
}
