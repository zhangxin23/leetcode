#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <ctype.h>

int atoi(const char* c) {
    extern int errno;

    long long result = 0;
    int sign = 1;

    if(c == NULL) {
        errno = EINVAL;
        return 0;
    }

    while(isspace(*c))
        c++;

    if(*c == '-') {
        sign = -1;
        c++;
    } else {
        sign = 1;
        if(*c == '+')
            c++;
    }

    while(*c) {
        if(*c < '0' || *c > '9') {
            return result;
        }

        result = result * 10 + (*c - '0');
        if((sign == 1 && result > INT_MAX) || (sign == -1 && -result < INT_MIN)) {
            errno = EOVERFLOW;
            if(sign == 1)
                return INT_MAX;
            else if(sign == -1)
                return INT_MIN;
        }

        c++;
    }

    if(sign == 1)
        return result;
    else if(sign == -1)
        return -result;
}
