#include "../include/my_curl.h"

//Usage: ./my_cur <url>
int main(int argc, char **argv){
    if (argc != 2){
        printf("usage: %s <url>\n", argv[0]);
        return 1;
    }

    my_curl(argv[1]);

    //my_curl("http://www.columbia.edu/~fdc/sample.html");   
    //my_curl(http://www.example.com)

    return 0;
}
