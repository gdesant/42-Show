#include "libft.h"

char *ft_strnstr(const char *big, const char *little, size_t len)
	{
		unsigned int i;
		unsigned int j;
		char *tmp;

		tmp = (char*)big;
		i = 0;
		j = 0;
		if (little[0] == '\0')
			return (&tmp[0]);
		while (tmp[i] && i < len)
		{
			if(tmp[i] == little[j])
			{
				while (tmp[i+j] == little[j])
				{
					if (little[j+1] == '\0' && i+j < len)
						return (&tmp[i]);
					else
						j++;
				}
				j = 0;
			}
			i++;
		}
		return NULL;
	}