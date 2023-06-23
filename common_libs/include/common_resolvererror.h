#ifndef COMMON_RESOLVERERROR_H
#define COMMON_RESOLVERERROR_H


#include <exception>

class ResolverError : public std::exception {
private:
    int gai_errno;

public:
    explicit ResolverError(int gai_errno);

    /*
     * Siempre que heredemos debemos hacer a nuestros
     * destructores polimórficos (`virtual`)
     *
     * Esto garantiza que será llamado.
     * */
    virtual ~ResolverError();
};


#endif // COMMON_RESOLVERERROR_H