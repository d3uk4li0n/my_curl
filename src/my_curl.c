#include "../include/my_curl.h"

int get_socket(char *hostname){
    struct addrinfo hints, *res;
    int sockfd = 0;
    char buf[10];

    my_memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    my_itoa(PORT, buf, 10);

    //printf("buf:|%s|\n", buf);

    getaddrinfo(hostname, buf, &hints, &res);
    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if(sockfd == -1){
        printf("error instantiating socket\n");
        return -1;
    }

    if(connect(sockfd, res->ai_addr, res->ai_addrlen) == -1){
        printf("error in connect()\n");
        return -1;
    }
    //printf("socket successfully connected!\n");
    return sockfd;
}

void my_curl(char *url){
    int sockfd; 
    char domain[254]; //full domain name can have a maximum of 253 characters
    
    char* path = get_domain(url, domain);
    if (path == NULL){
        printf("Invalid url given: %s\n", url);
    }else{
        //printf("domain:|%s|\n", domain);
        sockfd = get_socket(domain);
      
        if (sockfd != -1){
            get_data(sockfd, domain, path);
            close(sockfd);
        }
    }
}
