#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
	{
		size_t i;
		unsigned char *t;

		t = (unsigned char *)s;
		i = 0;
		while (i < n)
		{
			if (t[i] == c)
				return(t+i);
			i++;
		}
		return(NULL);	
	}