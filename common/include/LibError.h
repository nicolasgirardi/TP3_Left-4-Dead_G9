#ifndef LEFT4DEAD_LIBERROR_H
#define LEFT4DEAD_LIBERROR_H

#include <exception>

class LibError : public std::exception {
    char msg_error[256];
    int error_code;

public:
    LibError(int error_code, const char* fmt, ...) noexcept;

    virtual const char* what() const noexcept;

    virtual ~LibError();

    const int code() const noexcept;
};

#endif //LEFT4DEAD_LIBERROR_H
