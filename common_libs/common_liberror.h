#ifndef LEFT4DEAD_COMMON_LIBERROR_H
#define LEFT4DEAD_COMMON_LIBERROR_H


#include <exception>

class LibError : public std::exception{
    char msg_error[256];
    int error_code;


public:
    /*
     * Dado que `errno` es una variable global y puede ser modificada por
     * cualquier función, hay que hacer una copia apenas se haya detectado
     * el error, para luego lanzar `LibError` o bien lanzar `LibError` apenas
     * ya se haya detectado el error.
     *
     * El constructor `LibError` es variadico y recibe, ademas del `errno`,
     * un format-string (como `printf`) y cero o más argumentos que
     * formaran parte del mensaje.
     *
     * int ret = foo();
     * if (ret == -1)
     *      throw LibError(errno, "The function %s has failed: ", "foo");
     *  */
    LibError(int error_code, const char* fmt, ...) noexcept;

    virtual const char* what() const noexcept;

    virtual ~LibError();

    const int code() const noexcept;
};


#endif //LEFT4DEAD_COMMON_LIBERROR_H
