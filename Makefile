 # **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mramadan <mramadan@studentodam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/31 10:04:26 by mramadan       #+#    #+#                 #
#    Updated: 2019/12/20 10:32:11 by mramadan      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = 		libftprintf.a

SRC =	 	printf printf_utils printf_digit printf_cs \
			printf_flags printf_x printf_u printf_digit_hex \
			printf_ptr printf_n printf_utils_2

CFILES = $(SRC:%=%.c)

OFILES = $(SRC:%=%.o)

BCFILES = $(SRC:%=%_bonus.c)

BOFILES = $(SRC:%=%_bonus.o)

all: $(NAME)

$(NAME):
	gcc -c -Wall -Werror -Wextra $(CFILES)
	ar rc $(NAME) $(OFILES)

bonus:
	gcc -c -Wall -Werror -Wextra $(BCFILES)
	ar rc $(NAME) $(BOFILES)

clean:
	/bin/rm -f $(OFILES) $(BOFILES)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
