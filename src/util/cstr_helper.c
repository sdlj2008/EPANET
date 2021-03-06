/*
 ******************************************************************************
 Project:      OWA EPANET
 Version:      2.2
 Module:       util/cstr_helper.c
 Description:  Provides C string helper functions
 Authors:      see AUTHORS
 Copyright:    see AUTHORS
 License:      see LICENSE
 Last Updated: 04/02/2019
 ******************************************************************************
*/

#include <stdlib.h>
#include <string.h>

#include "cstr_helper.h"


int copy_cstr(const char *source, char **dest)
// Determines length, allocates memory, and returns a null terminated copy
// Be Aware: caller is responsible for freeing memory
{
    size_t size;

    size = 1 + strlen(source);
    *dest = (char *) calloc(size, sizeof(char));

    if (*dest == NULL)
        return -1;
    else {
#ifdef _MSC_VER
		strncpy_s(*dest, size, source, size);
#else
		strncpy(*dest, source, size);
#endif
    }
    return 0;
}


bool isnullterm_cstr(const char *source)
{
	if (strchr(source, '\0'))
		return true;
	else
		return false;
}
