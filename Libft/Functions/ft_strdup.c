#include "libft.h"

char *ft_strdup(const char *s)
  	{
  		int size;
  		char *str;
  		int i;

  		i = -1;
  		size = -1;
  		while(s[++size]);
  		if ((str = (char *)malloc(sizeof(const char) * size+1)))
  			str[size+1] = '\0';
  		else
  			return (NULL);
  		while(s[++i])
  			str[i] = s[i];
  		return (str);
  	}