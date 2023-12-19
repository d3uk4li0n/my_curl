#include "../include/my_curl.h"

int my_strlen(char *string){
    int i=0;
    if(string == NULL) return -1;

    while(string[i] != '\0') i++;

    return i;
}

int my_strcmp(char *s1, char *s2){
    int i = 0;

    while((s1[i] != '\0') && (s2[i] != '\0')){
        if(s1[i] > s2[i]) return 1;
        if(s1[i] < s2[i]) return -1;
        i++;
    }

    if (s1[i] != 0){
        return 1;
    }else  if (s2[i] != 0){
        return -1;
    }
    return 0;
}

char *my_strncpy(char *dst, char *src, int n){
    int i;
    
    for(i=0; i<n && src[i] != '\0';i++)
        dst[i] = src[i];

    dst[i] = '\0';
    return dst;
}

char *my_strcpy(char *dst, char *src){       
    return my_strncpy(dst, src, my_strlen(src));
}

void rev_string(char *begin, char *end){
    char aux;
      
    while(end>begin)
        aux=*end, *end--=*begin, *begin++=aux;
}

//convert string to integer, base 10
int my_atoi(char *str){
    int value = 0;
    char* temp = str;

    while (*temp != '\0')
    {
        value = value * 10 + (*temp - '0');
        temp++;
    }
    
    return value;
}

char *my_itoa(int value, char *str, int base){
    static char chars[] = "0123456789abcdefghijklmnopqrstuvwxyz";
    char *wstr = str;
    int sign;

    if((sign=value) < 0) 
        value = -value;

    do{
        *wstr++ = chars[value % base];
    }while(value /= base);
    
    if(sign < 0) *wstr++ = '-';
    *wstr = '\0';
    rev_string(str, wstr-1);
    return wstr;
}

void *my_memset(void *string, int fill, int length){
    unsigned char *s = string;
    while(length--){
        *s++ = (unsigned char)fill;
    }
    return string;
}

char* my_strcat(char *src, char*dst){

    int i = my_strlen(src);
    int j = 0;
    
    while (dst[j] != '\0'){
        src[i] = dst[j];
        i++;
        j++;
    }
    src[i] = '\0';

    return src;
}
