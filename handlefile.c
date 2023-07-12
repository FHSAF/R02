/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlefile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femuzaff <femuzaff@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 20:12:29 by femuzaff          #+#    #+#             */
/*   Updated: 2023/07/02 17:04:48 by femuzaff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	handle_file(char *path, int ds)
{
	int	file;

	file = 1;
	if (ds)
		close(ds);
	else
	{
		file = open(path, O_RDONLY);
		if (file == -1)
		{
			write(2, "Dict Error\n", 11);
			return (-1);
		}
	}
	return (file);
}
