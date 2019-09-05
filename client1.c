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
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
    {
        perror("sock");
        exit(-1);
    }
    addr.sin_family = AF_INET;
    addr.sin_port = htons(3935);
    addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    if(connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        perror("connect");
        exit(-1);
    }
    send(sock, buf, sizeof(buf), 0);
    printf("client out\n");
    close(sock);
    exit(0);
}
