#include "../include/my_curl.h"

bool url_check(char *url){
    if (my_strlen(url) < 7){
        return false;
    }

    char init[8];
    int i = 0;
    for(;i<7;i++) {
        init[i] = url[i];
    }
    init[i] = '\0';

    if (my_strcmp(init, "http://") != 0){        
        return false;
    }

    i = 7;
    while (url[i] != '\0'){
        if (url[i] >= 'a' && url[i] <= 'z'){
        }
        else if (url[i] >= 'A' && url[i] <= 'Z'){ 
        }
        else if (url[i] >= '0' && url[i] <= '9'){ 
        }
        else if (url[i] == ';' || url[i] == ',' || url[i] == '/'
           || url[i] == '?' || url[i] == ':' || url[i] == '@' || url[i] == '&'
        || url[i] == '=' || url[i] == '+' || url[i] == '$' || url[i] == '-'
           || url[i] == '_' || url[i] == '.' || url[i] == '!' 
           || url[i] == '~' || url[i] == '*' || url[i] == '\''
           || url[i] == '(' || url[i] == ')' || url[i] == '#'){
        }else{
            return false;
        }
        i += 1;
    }
  
    return true;
}

char *get_domain(char *url, char *dst){

    int i = 0;
    int valid = 1;

    //check "http://"
    if(!url_check(url)){
        dst[0] = '\0';
        valid = 0;
    }else{
        i = 0;
        while(url[i + 7] != '/' && url[i + 7] != '\0' && i < 253){            
            dst[i] = url[i + 7];
            i++;
        }
        dst[i] = '\0';

        //too long
        if(url[i + 7] != '/' && url[i + 7] != '\0'){
            dst[0] = '\0';
            valid = 0;
        }        
    }
    
    if (valid == 1){
        return url + (7 + my_strlen(dst));  
    }else{
        return NULL;
    }
}
