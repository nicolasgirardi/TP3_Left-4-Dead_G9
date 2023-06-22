#include "common_resolvererror.h"

ResolverError::ResolverError(int gai_errno) : gai_errno(gai_errno) { }

ResolverError::~ResolverError() {}
