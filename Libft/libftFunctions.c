/*Start EASY ONES*/
	/*FT_MEMSET Function*/
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

	/*BZERO Function*/
	#include <strings.h>

	void ft_bzero(void *s, size_t n)
	{
	    unsigned char *tmp;
	    unsigned int i;

	    i = 0;
	    tmp = s;
	    while (i != n)
	    {
	        tmp[i] = '\0';
	        i++;
	    }
	    return;

	}

	/*MEMCPY Function*/

	#include <string.h>

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
		
	/*MEMCCPY Function*/

	#include <string.h>

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

	/*MEMMOVE Function*/
	#include <string.h>

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

	/*FT_MEMCHR Function*/
	void *ft_memchr(const void *s, int c, size_t n)
	{
		size_t i;
		unsigned char *t;

		t = (unsigned char *)s;
		i = 0;
		while (i < n)
		{
			if (t[i] == c)
				return(t+i);
			i++;
		}
		return(NULL);	
	}

	/*FT_MEMCMP Function*/
	int ft_memcmp(const void *s1, const void *s2, size_t n)
	{
		unsigned char *tmp1;
		unsigned char *tmp2;

		size_t i;

		tmp1 = (unsigned char *)s1;
		tmp2 = (unsigned char *)s2;
		i = 0;
		while (i < n)
		{
			if (*tmp1 != *tmp2)
				return(*tmp1 - *tmp2);
			tmp1++;
			tmp2++;
			i++;
		}
		return(0);	
	}

	/*STRLEN Function*/
	#include <string.h>

	size_t ft_strlen(const char *s)
	{
		unsigned int i;

		i = 0;
		while (s[i] != '\0')
			i++;
		return(i);
	}

	/*ISALPHA Function */
	int ft_isalpha(int c)
	{
	    if ((c > 64 && c < 91) || 
	        (c > 96 && c < 123))
	        return(1024);
	    else 
	        return(0);
	}

	/*ISDIGIT Function*/
	int ft_isdigit(int c)
	{
	    if (c > 47 && c < 58)
	        return(2048);
	    else 
	        return(0);
	}

	/*ISALNUM Function*/
	int ft_isalnum(int c)
	{
	    if ((c > 64 && c < 91) || 
	        (c > 96 && c < 123))
	        return(8);
	    else if (c > 47 && c < 58)
	        return(8);
	    else 
	        return(0);
	}

	/*ISASCII Function*/
	int ft_isascii(int c)
	{
	    if (c >= 0 && c <= 127)
	    	return(1);
	    else 
	        return(0);
	}

	/*ISPRINT Function*/
	int ft_isprint(int c)
	{
		if (c > 31 && c < 127)
			return(16384);
		else
			return(0);
	}

	/*TOUPPER Function*/
	int ft_toupper(int c)
	{
		if(c > 96 && c < 123)
			return(c - 32);
		else
			return(c);
	}

	/*TOLOWER Function*/
	int ft_tolower(int c)
	{
		if(c > 64 && c < 91)
			return(c + 32);
		else
			return(c);
	}

	/*FT_STRCHR Function*/
	char *ft_strchr(const char *s, int c)
	{
		int i;
		char *t;

		t = (char*)s;
		i = -1;
		while (t[++i])
		{
			if (t[i] == c)
				return(&t[i]);
		}
		return(NULL);	
	}

	/*FT_STRRCHR Function*/
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

	/*FT_STRNCMP Function*/
	int ft_strncmp(const char *s1, const char *s2, size_t n)
	{
		unsigned int i;
		int src;

		src = 0;
		i = 0;
		while (i < n)
		{
			src = src + (s1[i] - s2[i]);
			if (s1[i] != s2[i])
				return (src);
			i++;
		}
		return (src);
	}

	/*FT_STRLCPY Function*/
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

	/*FT_STRLCAT Function*/

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

	/*FT_STRNSTR Function*/
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

	/*FT_ATOI Function*/

	int ft_atoi(const char *nptr)
	{
		int	n;
		int	i;
		int	res;
		int	negative;

		n = 0;
		while (nptr[n] != '\0' && (nptr[n] == ' ' || nptr[n] == '\t' ||
				nptr[n] == '\r' || nptr[n] == '\n'))
			n++;
		i = n;
		res = 0;
		negative = 0;
		while (nptr[i] != '\0' && ((nptr[i] >= '0' && nptr[i] <= '9') ||
					(i == n && (nptr[i] == '-' || nptr[i] == '+'))))
		{
			if (nptr[i] == '-')
				negative = 1;
			if (nptr[i] >= '0' && nptr[i] <= '9')
				res = (res * 10) + (nptr[i] - 48);
			++i;
		}
		if (negative)
			res *= -1;
		return (res);
	}
/*End EASY ONES*/
/*Start HARD ONES*/

	/*FT_CALLOC Funtcion*/
	#include <stdlib.h>

	void *ft_calloc(size_t nmemb, size_t size)
	{
		void *pt;

		pt = malloc(nmemb*size);
		return pt;
	}

	/*FT_STRDUP Funtcion*/
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

  	/*Start SUP ONES*/

  	/*FT_SUBSTR Function*/
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




  	/*FT_STRJOIN Function*/
  	#include <string.h>
	#include <stdlib.h>

	unsigned int	ft_strlen(char *str)
	{
		int i;

		i = 0;
		while (str[i])
			i++;
		return (i);
	}

	unsigned int	get_len(int size, char **strs, char *sep)
	{
		int		len;
		int		i;

		i = 0;
		len = (size - 1) * ft_strlen(sep);
		while (i < size)
		{
			len += ft_strlen(strs[i]);
			i++;
		}
		len++;
		return (len);
	}

	char			*ft_strcat(char *dest, char *src)
	{
		unsigned int i;
		unsigned int n;

		i = 0;
		while (dest[i] != '\0')
		{
			i++;
		}
		n = 0;
		while (src[n] != '\0')
		{
			dest[i] = src[n];
			n++;
			i++;
		}
		dest[i] = '\0';
		return (dest);
	}

	char			*ft_strjoin(int size, char **strs, char *sep)
	{
		char	*tmp;
		int		i;

		i = -1;
		if (size == 0)
		{
			if (!(tmp = (char*)malloc(sizeof(char) * get_len(size, strs, sep))))
				return (NULL);
			*tmp = '\0';
		}
		else
		{
			if (!(tmp = (char*)malloc(sizeof(char) * get_len(size, strs, sep))))
				return (NULL);
			tmp[0] = '\0';
			while (++i < size)
			{
				tmp = ft_strcat(tmp, strs[i]);
				if (i == size - 1)
					tmp[get_len(size, strs, sep) - 1] = '\0';
				else
					tmp = ft_strcat(tmp, sep);
			}
		}
		return (tmp);
	}
  	/*FT_STRJOIN End*/



  	/*FT_STRTTRIM Function*/
  	#include <stdlib.h>

	unsigned int what_chara(char const *set, char s)
	{
		int i;

		i = -1;
		while (set[++i])
		{
			if (s == set[i])
				return(1);
		}
		return (0);
	}

	char *ft_strtrim(char const *s1, char const *set)
	{
		int i;
		int length;

		i = 0;
		if (!s1 || !set)
			return (ft_strdup(""));
		if (ft_strlen(set) == 0)
			return (ft_strdup(s1));
		lenght = ft_strlen(s1);
		while (s1[i] && s1[i])
			i++;

	}
  	/*FT_STRTRIM End*/


  	/*FT_SPLIT Function*/
  	int			diviseur(char c, char *charset)
	{
		int i;

		i = 0;
		while (charset[i])
		{
			if (charset[i++] == c)
				return (1);
		}
		return (0);
	}

	int			next_word(char *str, char *charset)
	{
		int i;

		i = 0;
		while (str[i])
		{
			if (diviseur(str[i], charset))
				return (i);
			i++;
		}
		return (i - 1);
	}

	int			c_w(char *str, char *charset)
	{
		int count;
		int i;
		int b;

		count = 0;
		i = 0;
		while (str[i])
		{
			b = 0;
			if (!diviseur(str[i], charset))
			{
				i = i + next_word(str + i, charset);
				count++;
			}
			i++;
		}
		return (count);
	}

	void		copy(char *dest, char *src, int length)
	{
		int i;

		i = 0;
		while (src[i] && i < length)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
		return ;
	}

	char		**ft_split(char *str, char *charset)
	{
		char	**tmp;
		int		i;
		int		c;
		int		last;

		c = 0;
		i = -1;
		if ((tmp = (char**)malloc(sizeof(char*) * (c_w(str, charset) + 1))) == NULL)
			return (NULL);
		while (str[++i])
			if (!diviseur(str[i], charset))
			{
				last = i;
				i += next_word(str + i, charset);
				if ((tmp[c] = (char*)malloc(sizeof(char) * (i - last + 1))) == NULL)
					return (NULL);
				copy(tmp[c++], str + last, i - last + \
						(diviseur(str[last + (i - last)], charset) ? 0 : 1));
			}
		tmp[c] = 0;
		return (tmp);
	}
	/*End FT_Split*/


  	/*End SUP ONES*/

/*End HARD ONES*/