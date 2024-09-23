#include "miniheader.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_ptr;
	unsigned char		*src_ptr;

	dest_ptr = (unsigned char *) dest;
	src_ptr = (unsigned char *) src;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (n > 0)
	{
		*dest_ptr = *src_ptr;
		if (dest != NULL)
			dest_ptr++;
		if (src != NULL)
			src_ptr++;
		n--;
	}
	return (dest);
}

char *ft_strjoin(const char *s1, const char *s2)
{
    if (!s1 && !s2)
        return NULL;
    if (!s1)
        return strdup(s2);
    if (!s2)
        return strdup(s1);

    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);
    char *str = malloc(len1 + len2 + 1);
    if (!str)
        return NULL;

    ft_memcpy(str, s1, len1);
    ft_memcpy(str + len1, s2, len2 + 1);  // +1 per includere il terminatore null
    return str;
}


int skip_spaces(char *input, int i)
{
    while (input[i] == ' ')
        i++;
    return i;
}