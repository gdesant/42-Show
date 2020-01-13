#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
	{
	   unsigned char temp[n];
	   unsigned int i = 0;
	   char *srctmp = (char*)src; 
	   char *destmp = (char*)dest; 
	  
	   while (i < n)
	   {
	   	temp[i] = srctmp[i];
	   	i++;
	   }
	   i = 0;
	   while (i < n)
	   {
	   	destmp[i] = temp[i];
	   	i++;
	   }
	   return(destmp);
	}