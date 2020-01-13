#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
  	{
  		char *ptr;

  		if ((ptr = (char *)malloc(sizeof(const char) * (len-start)+1)))
  		{
  			while(++start <= len)
  				ptr[start-1] = s[start-1];
  			ptr[len] = '\0';
  			return (ptr);
  		}
  		return (NULL);
  	}
