#include "libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t size)
	{
	  unsigned int d;
	  unsigned int s;
	  unsigned int l;

	  s = 0;
	  d = 0;
	  l = 0;
	  while(src[s])
	    s++;
	  while(dst[d])
	    d++;
	  while(l+d < size-1)
	  {
	    dst[d+l] = src[l];
	    l++;
	  }
	  dst[d+l] = '\0';
	  if (d-1 < size)
	    return(d+s);
	  else
	    return(s+size);
	}