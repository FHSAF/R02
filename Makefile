# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkremer <femuzaff@student.42heilbronn.de   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/01 18:28:14 by dkremer           #+#    #+#              #
#    Updated: 2023/07/02 21:09:04 by dkremer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
cc		= gcc

CFLAGS	= -Wall -Wextra -Werror

SRC		= main.c handlefile.c ft_atoi.c any_error.c rush02.c read_number.c

OBJ		= $(SRC:.c=.o)

NAME	= rush-02

${NAME} :	${OBJ}
	${CC} ${CFLAGS} -o ${NAME} ${OBJ}

clean:
	rm -f ${OBJ}

fclean:	clean
	rm -f ${NAME}

.PHONY: clean fclean
