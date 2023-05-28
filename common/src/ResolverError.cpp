#include "../include/ResolverError.h"
#include <netdb.h>

ResolverError::ResolverError(int gai_errno) : gai_errno(gai_errno) { }

const char* ResolverError::what() const noexcept {
    return gai_strerror(gai_errno);
}

ResolverError::~ResolverError() {}
