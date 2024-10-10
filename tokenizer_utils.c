#include "miniheader.h"

int skip_spaces(char *input, int i)
{
    while (input[i] == ' ')
        i++;
    return i;
}