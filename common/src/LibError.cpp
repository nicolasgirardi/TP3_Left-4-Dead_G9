#undef _GNU_SOURCE
#undef GNU_SOURCE

#include <cstdio>
#include <cstdarg>
#include <cstring>
#include "../include/LibError.h"


LibError::LibError(int error_code, const char* fmt, ...) noexcept {
    this->error_code = error_code;
    va_list args;
    va_start(args, fmt);

    int s = vsnprintf(msg_error, sizeof(msg_error), fmt, args);

    va_end(args);

    if (s < 0) {
        msg_error[0] = msg_error[1] = msg_error[2] = '?';
        msg_error[3] = ' ';
        msg_error[4] = '\0';

        s = 4;
    } else if (s == sizeof(msg_error)) {
    }

    strerror_r(error_code, msg_error+s, sizeof(msg_error)-s);

    msg_error[sizeof(msg_error)-1] = 0;
}

const char* LibError::what() const noexcept {
    return msg_error;
}

const int LibError::code() const noexcept {
    return error_code;
}

LibError::~LibError() {}