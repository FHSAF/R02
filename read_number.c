#include "rush02.h"

void	next_digit(int *len, long int *temp, int *digit)
{
	*len = *len - 1;
	*temp = *temp / 10;
	*digit = *temp % 10;
}

void	add_space(int len)
{
	if (len != 0)
		write(1, " ", 1);
}

void	case_10(int digit, int *len, char *path, long int *temp)
{
	int	rem;

	rem = *len % 3;
	if (rem == 1)
	{
		get_value(digit, 1, path);
		next_digit(len, temp, &digit);
		add_space(*len);
	}
	else if (rem == 2)
	{
		if (digit == 1)
			digit = digit * 10 + (*temp/10) % 10;
		else
			digit *= 10;
		get_value(digit, 2, path);
		rem = digit;
		next_digit(len, temp, &digit);
		if ((rem >= 20) && (digit != 0))
			write(1, " ", 1);
		if ((rem >= 20) && (digit != 0))
			get_value(digit, 1, path);
		next_digit(len, temp, &digit);
		add_space(*len);
	}	
}

void	case_100(int digit, int *len, char *path, long int *temp)
{
	int	rem;
	int	i;

	rem = *len % 3;
	i = 2;
	if (rem == 0)
	{
		get_value(digit, 1, path);
		write(1, " ", 1);
		get_value(100, 3, path);
		next_digit(len, temp, &digit);
		while ((digit == 0) && (i > 0) && (*len > 0))
		{	
			next_digit(len, temp, &digit);
			i--;
		}
		add_space(*len);
	}
	if ((i != 0) && (*len > 0))
		case_10(digit, len, path, temp);
}