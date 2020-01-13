#include "libft.h"

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