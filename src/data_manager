#include "../include/my_curl.h"

void get_data(int sockfd, char* domain, char* path){
    
    char buffer[1024];
    int n = 0;

    char header[2049];

    //path is "" then path is /
    if (my_strlen(path) == 0){
        my_strcpy(path, "/");
    }
    my_strcpy(header, "GET ");
    my_strcat(header, path);
    my_strcat(header, " HTTP/1.1\r\nHost: ");
    my_strcat(header, domain);
    my_strcat(header, "\r\nConnection: close\r\n\r\n");
    
    //printf("%s\n", header);
    
    n = write(sockfd, header, my_strlen(header));
    
    while ((n = read(sockfd, buffer, 1023)) > 0){
        buffer[n] = '\0';
        printf("%s", buffer);
    }
}
