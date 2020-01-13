#include "libft.h"

size_t ft_strlcpy(char *dst, const char *src, size_t size)
	{
	  unsigned int i;

	  i = 0;
	  while (i < size - 1)
	  {
	    dst[i] = src[i];
	    ++i;
	  }
	  dst[i] = '\0';
	  return(dst[i]);
	}
