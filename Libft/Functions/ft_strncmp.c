#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
	{
		unsigned int i;
		int src;

		src = 0;
		i = 0;
		while (i < n)
		{
			src = src + (s1[i] - s2[i]);
			if (s1[i] != s2[i])
				return (src);
			i++;
		}
		return (src);
	}