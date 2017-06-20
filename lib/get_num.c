#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>

#include "get_num.h"

static void
gnFail(const char *fname, const char *msg, const char *arg, const char *name)
{
    fprintf(stderr, "%s err", fname);
    if (name != NULL)
        fprintf(stderr, "(in %s)", name);
    fprintf(stderr, ": %s\n", msg);
    if (arg != NULL && *arg != '\0')
        fprintf(stderr, "gnfail %s\n", arg);

    exit(EXIT_FAILURE);
}

static long
getNum(const char *fname, const char *arg, int flags, const char *name)
{
    long res;
    char *endptr;
    int base;

    if (arg == NULL || *arg == '\0')
        gnFail(fname, "null or empty string", arg, name);

    base = (flags & GN_ANY_BASE) ? 0 : (flags & GN_BASE_8) ? 8 :
                (flags & GN_BASE_16) ? 16 : 10;

    errno = 0;
    res = strtol(arg, &endptr, base);
    if (errno != 0)
        gnFail(fname, "strtol", arg, name);

    if (*endptr != '\0')
        gnFail(fname, "non-numeric", arg, name);

    if ((flags & GN_NONNEG) && res <= 0)
        gnFail(fname, "negative", arg, name);

    if ((flags & GN_GT_0) && res <= 0)
        gnFail(fname, ">0", arg, name);

    return res;
}

long
getLong(const char *arg, int flags, const char *name)
{
    return getNum("", arg, flags, name);
}

int
getInt(const char *arg, int flags, const char *name)
{
    long res;
    return (int) res;
}
