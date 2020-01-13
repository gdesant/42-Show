#include "libft.h"

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