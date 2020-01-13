#include "libft.h"

void *ft_memcpy(void *dest, void *src, size_t n)
	{

	    char *tmp;
	    char *srctmp;
	    unsigned int i;

	    i = 0;
	    tmp = (char*)dest;
	    srctmp = (char*)src;
	    while (i < n)
	    {
	        tmp[i] = srctmp[i];
	        i++;
	    }
	    return(dest);
	}