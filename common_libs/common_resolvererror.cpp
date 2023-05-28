#include "common_resolvererror.h"

#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>

ResolverError::ResolverError(int gai_errno) : gai_errno(gai_errno) { }

ResolverError::~ResolverError() {}
