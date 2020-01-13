#include "libft.h"

char *ft_strchr(const char *s, int c)
	{
		int i;
		char *t;

		t = (char*)s;
		i = -1;
		while (t[++i])
		{
			if (t[i] == c)
				return(&t[i]);
		}
		return(NULL);	
	}