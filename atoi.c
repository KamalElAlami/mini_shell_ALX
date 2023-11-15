#include "main.h"

int	_skipper(char *str, int *i, int sign)
{
	while (str[*i] == 32 || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = sign * -1;
		(*i)++;
	}
	return (sign);
}

int	_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned long	number;

	i = 0;
	sign = 1;
	sign = _skipper((char *)str, &i, sign);
	number = 0;
	while (_isdigit(str[i]))
	{
		number = number * 10 + str[i] - '0';
		if (number > LONG_MAX && sign == 1)
			return (-1);
		if (number > (unsigned long)LONG_MAX + 1 && sign == -1)
			return (0);
		i++;
	}
	return (number * sign);
}
