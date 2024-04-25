#include "../inc/game_of_life.h"

int	ft_atoi(const char *str)
{
	long long int	result;
	int				i;
	int				minus;

	i = 0;
	result = 0;
	minus = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57 && str[i])
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * minus);
}
