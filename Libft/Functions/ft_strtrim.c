#include "libft.h"

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

char *prodchar(char *s1, int start, int end)
	{
		char *ptr;
		while (start <= end)
		{
			ptr[start] = s1[start];
			start++;
		}
		return (ptr);
	}

char *ft_strtrim(char const *s1, char const *set)
	{
		int start;
		int length;
		char *result;

		i = 0;
		if (!s1 || !set)
			return (ft_strdup(""));
		if (ft_strlen(set) == 0)
			return (ft_strdup(s1));
		lenght = ft_strlen(s1);
		while (s1[i] && what_chara(set, s1[i]))
			i++;
		while (s1[lenght] && what_chara(set, s1[lenght]))
			lenght--;
		if (s1 = (char*)malloc(sizeof(char) * lenght-i+1))
			result = prodchar(s1, i, lenght);
			return (result);
		else 
			return (NULL);

	}