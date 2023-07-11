/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   any_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femuzaff <femuzaff@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 14:30:50 by femuzaff          #+#    #+#             */
/*   Updated: 2023/07/02 21:40:56 by femuzaff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

bool	any_error(int argc, char **argv)
{
	char	*digits;

	if (argc < 2)
	{
		write(2, "Error: at least one argument is required\n", 41);
		return (true);
	}
	if (argc > 3)
	{
		write(2, "Error: too many argumnets\n", 26);
		return (true);
	}
	digits = argv[argc - 1];
	while (*digits)
	{
		if (!((*digits <= 0x39) && (*digits >= 0x30)))
		{
			write(1, "Error: <digits> or <path> <digits>\n", 36);
			return (true);
		}
		digits++;
	}
	return (false);
}
