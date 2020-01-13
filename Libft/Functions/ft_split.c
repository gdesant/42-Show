#include "libft.h"

int		sep_chara(char *str, char *charstr)
{
	while (*charstr)
	{
		if (*str == *charstr)
			return (1);
		*charstr++;
	}
	return (0);
}

int		word_lenght(char *str, char *charset)
{
	int i;

	i = 0;
	while (str[i] && sep_chara(str + i, charset) == 0)
		i++;
	return (i);
}

int		word_count(char *str, char *charset)
{
	int i;
	int x;

	x = 0;
	while (*str)
	{
		while (*str && sep_chara(str, charset))
			str++;
		i = word_lenght(str, charset);
		str += i;
		if (i)
			x++;
	}
	return (x);
}

char	*word_copy(char *src, int k)
{
	char	*dest;

	if (!(dest = malloc((k + 1) * sizeof(char))))
		return (NULL);
	dest[k] = '\0';
	while (k--)
		dest[k] = src[k];
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	char	**rtrn;
	int		size;
	int		i;
	int		x;

	size = word_count(str, charset);
	if (!(rtrn = malloc((size + 1) * sizeof(char*))))
		return (NULL);
	i = -1;
	while (++i < size)
	{
		while (*str && sep_chara(str, charset))
			str++;
		x = word_lenght(str, charset);
		if (!(rtrn[i] = word_copy(str, x)))
			return (NULL);
		str += x;
	}
	rtrn[size] = 0;
	return (rtrn);
}