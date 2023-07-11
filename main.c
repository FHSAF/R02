/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femuzaff <femuzaff@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:30:20 by femuzaff          #+#    #+#             */
/*   Updated: 2023/07/02 21:37:48 by femuzaff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>

int		ft_atoi(char *str);
int		handle_file(char *path, int ds);
bool	any_error(int argc, char **argv);
void	case_100(int digit, int *len, char *path, long int *temp);
int		get_power(int base, int power);
void	print_values(int file);
void	get_value(int key, int key_len, char *path);
void	skip_null(long int *temp, int *len, char *path);

int	rev_num(int num, long int *temp)
{
	int	len;

	*temp = 0;
	len = 0;
	while (num)
	{
		*temp = *temp * 10 + (num % 10);
		num /= 10;
		len++;
	}
	return (len);
}

void	write_num(int num, char *path)
{
	long int	temp;
	int			len;
	int			digit;

	if (num == 0)
	{
		get_value(0, 1, path);
		write(1, "\n", 1);
		return ;
	}
	len = rev_num(num, &temp);
	while (len > 0)
	{
		digit = (temp % 10);
		temp /= 10;
		case_100(digit, &len, path, &temp);
		if (len > 3)
			get_value(get_power(1, len - 1), len, path);
		len--;
		skip_null(&temp, &len, path);
	}
	write(1, "\n", 1);
}

void	rush02(char *path, int num)
{
	int		file;

	file = handle_file(path, 0);
	if (file == -1)
		return ;
	handle_file(0, file);
	write_num(num, path);
}

int	main(int argc, char **argv)
{
	int		num;
	char	*digits;
	char	*path;

	if (any_error(argc, argv))
		return (1);
	digits = argv[argc - 1];
	num = ft_atoi(digits);
	if (num < 0)
	{
		write(2, "Error: overflow\n", 17);
		return (1);
	}
	if (argc < 3)
		path = "numbers.dict";
	else
		path = argv[1];
	rush02(path, num);
	return (0);
}

void	case_100(int digit, int *len, char *path, long int *temp)
{
	int	rem;

	rem = *len % 3;
	if (rem == 1)
		get_value(digit, 1, path);
	else if (rem == 2)
	{
		if (digit == 1)
		{
			digit = digit * 10 + *temp % 10;
			*temp = *temp / 10;
			*len = *len - 1;
		}
		else
		{
			digit *= 10;
		}
		get_value(digit, 2, path);
	}
	else
	{
		get_value(digit, 1, path);
		get_value(100, 3, path);
	}
}
