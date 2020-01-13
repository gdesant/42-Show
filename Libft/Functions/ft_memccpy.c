#include "libft.h"

void *ft_memccpy(void *dest, const void *src,int c, size_t n)
	{

	    char *tmp;
	    const char *srctmp;
	    unsigned int i;

	    i = 0;
	    tmp = (char*)dest;
	    srctmp = (char*)src;
	    while (i < n)
	    {
	      if (srctmp[i] == c)
	      {
	      	tmp[i] = srctmp[i];
	    	return (&tmp[i]);
	      }
	      else
	      {
	      	tmp[i] = srctmp[i];
	        i++;
	      }
	    } 
	    return (&tmp[i]);
	}