#ifndef RUSH02_H
# define RUSH02_H
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <stdio.h>

void	add_space(int len);
int		ft_atoi(char *str);
int		handle_file(char *path, int ds);
bool	any_error(int argc, char **argv);
void	next_digit(int *len, long int *temp, int *digit);
void	case_10(int digit, int *len, char *path, long int *temp);
void	case_100(int digit, int *len, char *path, long int *temp);
int		get_power(int base, int power);
int		print_values(int file);
void	get_value(int key, int key_len, char *path);
void	skip_null(long int *temp, int *len);

#endif