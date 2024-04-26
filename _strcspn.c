#include <stddef.h>
#include "shell.h"

size_t custom_strcspn(const char *str, const char *reject)
{
    size_t i, j;
    
    for (i = 0; str[i] != '\0'; ++i)
    {
        for (j = 0; reject[j] != '\0'; ++j)
        {
            if (str[i] == reject[j])
            {
                return i;
            }
        }
    }
    return i;
}