#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <strings.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define PORT 80

#ifndef MY_CURL_H
#define MY_CURL_H

int get_socket(char *);
void my_curl(char *);

#endif  

#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

void get_data(int, char*, char*);

#endif

#ifndef UTILS_H
#define UTILS_H

bool url_check(char *);
char *get_domain(char *, char *);

#endif

#ifndef STRING_UTILS_H
#define STRING_UTILS_H

int my_strlen(char *);
int my_strcmp(char *, char *);
char *my_strncpy(char *, char *, int);
char *my_strcpy(char *, char *);
void rev_string(char *, char *);
int my_atoi(char *);
char *my_itoa(int, char *, int);
void *my_memset(void *, int, int);
char* my_strcat(char *, char*);
#endif
