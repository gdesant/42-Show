#include "libft.h"

char *ft_itoa(int n)
{
	int i;
	int x;
	char *str;

	i = 0;
	x = 0;
	if (n = 0)
	{
		str[0] = '0';
		str[1] = '/0';
		if (!(str = malloc((3) * sizeof(char*))))
			return (NULL);
		return (str);
	}
	while (n =! 0)
	{
		i = n % 10;
		n = n / 10;
		if (x > 0)
			str[x] = i*10 + '0';
		x++;
	}
	str[x+1] = '/0';
	if (!(str = malloc((x + 1) * sizeof(char*))))
		return (NULL);
	else 
		return (str);
}