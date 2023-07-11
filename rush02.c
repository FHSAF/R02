/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femuzaff <femuzaff@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:44:40 by femuzaff          #+#    #+#             */
/*   Updated: 2023/07/02 21:17:58 by femuzaff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#define flag = 0

int	ft_atoi(char *str);
int	handle_file(char *path, int ds);

int	get_power(int base, int power)
{
	while (power)
	{
		base = base * 10;
		power--;
	}
	return (base);
}

int	print_values(int file)
{
	char	buf[1];
	int		current_byte;

	current_byte = read(file, buf, 1);
	while ((current_byte) && (*buf == 0x20))
		current_byte = read(file, buf, 1);
	if (*buf == 0x3A)
		current_byte = read(file, buf, 1);
	while ((current_byte) && (*buf == 0x20))
		current_byte = read(file, buf, 1);
	if ((current_byte) && (*buf != 0xA))
		write(1, " ", 1);
	while ((current_byte) && (*buf != 0xA))
	{
		if (*buf == 0x20)
		{
			write(1, " ", 1);
			while ((*buf == 0x20) && (current_byte))
				current_byte = read(file, buf, 1);
		}
		write(1, buf, 1);
		current_byte = read(file, buf, 1);
	}
	return (0);
}

void	search_key(int key, int file, char *key_buf, int i)
{
	char	buf[1];
	int		curent_byte;

	curent_byte = read(file, buf, 1);
	while (curent_byte)
	{
		curent_byte = read(file, buf, 1);
		if (*buf == 0xA)
		{
			curent_byte = read(file, buf, 1);
			while ((*buf >= 0x30) && (*buf <= 0x39) && curent_byte)
			{
				key_buf[i] = *buf;
				curent_byte = read(file, buf, 1);
				i++;
			}
		}
		if ((ft_atoi(key_buf) == key))
			curent_byte = print_values(file);
		else
			i = 0;
	}
}

void	get_value(int key, int key_len, char *path)
{
	char	new_buf[12];
	int		i;
	int		file;

	i = 0;
	new_buf[key_len] = 0;
	while (key_len--)
		new_buf[key_len] = 0;
	file = handle_file(path, 0);
	search_key(key, file, new_buf, i);
	handle_file(0, file);
}

void	skip_null(long int *temp, int *len, char *path)
{
	int	skip;
	int	base;
	int	power;

	skip = 0;
	while (((*temp % 10) == 0) && (*len > 0))
	{
		skip++;
		*temp /= 10;
		*len = *len - 1;
		if ((skip == 2) && (*len > 1))
		{
			base = *len;
			power = get_power(1, base);
			get_value(power, base + 1, path);
		}
	}
	skip = 0;
}
