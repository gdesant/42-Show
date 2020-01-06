#include <string.h>

	void *ft_memset(void *s, int c, size_t n)
	{
		unsigned int i;
		char *tmp;

		i = 0;
		tmp = (char*)s;
		while (i < n)
		{
			tmp[i] = c;
			i++;
		}
		return (tmp);
	}