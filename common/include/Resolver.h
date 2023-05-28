#ifndef LEFT4DEAD_RESOLVER_H
#define LEFT4DEAD_RESOLVER_H
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>

class Resolver {
private:
    struct addrinfo *result;
    struct addrinfo *_next;

public:
    Resolver(const char* hostname, const char* servname, bool is_passive);

    Resolver(const Resolver&) = delete;
    Resolver& operator=(const Resolver&) = delete;

    Resolver(Resolver&&);
    Resolver& operator=(Resolver&&);

    bool has_next();

    struct addrinfo* next();

    ~Resolver();
};
#endif //LEFT4DEAD_RESOLVER_H
