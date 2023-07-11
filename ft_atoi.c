/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femuzaff <femuzaff@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:19:47 by femuzaff          #+#    #+#             */
/*   Updated: 2023/06/27 21:16:33 by femuzaff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	sign;
	int	num;

	sign = 0;
	num = 0;
	while (((*str >= 0x9) && (*str <= 0xd)) || (*str == 0x20))
		str++;
	while ((*str == '+') || (*str == '-'))
	{
		if (*str == '-')
			sign++;
		str++;
	}
	while ((*str >= 0x30) && (*str <= 0x39))
	{
		num = 10 * num + (int)(*str - 0x30);
		str++;
	}
	if (!(sign % 2 == 0))
		num = -num;
	return (num);
}
