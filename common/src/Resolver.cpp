#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netdb.h>
#include "../include/Resolver.h"
#include "../include/LibError.h"
#include "../include/ResolverError.h"

Resolver::Resolver(const char* hostname, const char* servname, bool is_passive) {
    struct addrinfo hints;
    this->result = this->_next = nullptr;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = is_passive ? AI_PASSIVE : 0;

    int s = getaddrinfo(hostname, servname, &hints, &this->result);

    if (s != 0) {
        if (s == EAI_SYSTEM) {
            throw LibError(errno, "Name resolution failed for hostname '%s' y servname '%s'",
                           (hostname ? hostname : ""), (servname ? servname : ""));
        } else {
            throw ResolverError(s);
        }
    }
    this->_next = this->result;
}

Resolver::Resolver(Resolver&& other) {
    this->result = other.result;
    this->_next = other._next;

    other.result = nullptr;
    other._next = nullptr;
}

Resolver& Resolver::operator=(Resolver&& other) {
    if (this == &other)
        return *this;

    if (this->result)
        freeaddrinfo(this->result);

    this->result = other.result;
    this->_next = other._next;
    other.result = nullptr;
    other._next = nullptr;

    return *this;
}

bool Resolver::has_next() {
    return this->_next != NULL;
}

struct addrinfo* Resolver::next() {
    struct addrinfo *ret = this->_next;
    this->_next = ret->ai_next;
    return ret;
}

Resolver::~Resolver() {
    if (this->result)
        freeaddrinfo(this->result);
}
