#include "libft.h"

char *ft_strrchr(const char *s, int c)
	{
		int i;
		char *t;
		int n;

		t = (char*)s;
		i = -1;
		n = -1;
		while (s[++i])
		{
			if (s[i] == c)
				n = i;
		}
		if (n == -1)
			return(NULL);
		else 
			return(&t[n]);	
	}