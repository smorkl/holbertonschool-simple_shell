#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>

char** tokenize(char* buffer);
size_t custom_strcspn(const char *str, const char *reject);

#endif
