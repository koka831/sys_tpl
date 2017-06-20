#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>

#include "get_num.h"

static void
gnFail(const char *fname, const char *msg, const char *arg, const char *name)
{

}

static long
getNum(const char *fname, const char *arg, int flags, const char *name)
{
    long res;
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
