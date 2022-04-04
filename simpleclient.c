#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int sockfd;
    int len;
    struct sockaddr_in address;
    int result;
    char ch = 'A';
    char buf[1024] = "HEAD / HTTP/1.0\n";

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_port = htons(10000);
    len = sizeof(address);
    result = connect(sockfd, (struct sockaddr *)&address, len);
    if (result == -1)
    {
        perror("oops: client1");
        exit(1);
    }

    // write(sockfd, &ch, 1);
    // read(sockfd, &ch, 1);
    // printf("char from server = %c\n", ch);

    write(sockfd, buf, strlen(buf));
    result = read(sockfd, buf, sizeof(buf));
    buf[result] = '\0';
    printf("%s", buf);

    close(sockfd);
    exit(0);
}
