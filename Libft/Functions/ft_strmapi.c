#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int i;
	char *rtrn;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	if (!(str = malloc((ft_strlen(s) + 1) * sizeof(char*))))
		return (NULL);
	ft_strcpy(rtrn, s);
	while (s[i])
	{
		rtrn[i] = (*f)(i, rtrn[i])
		i++;
	}
	rtrn[i+1] = '/0';
	return (rtrn);
}