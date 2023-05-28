#ifndef LEFT4DEAD_RESOLVERERROR_H
#define LEFT4DEAD_RESOLVERERROR_H

#include <exception>

class ResolverError : public std::exception {
private:
    int gai_errno;

public:
    explicit ResolverError(int gai_errno);

    virtual const char* what() const noexcept;

    virtual ~ResolverError();
};
#endif //LEFT4DEAD_RESOLVERERROR_H
