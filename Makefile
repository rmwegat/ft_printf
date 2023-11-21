# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 12:57:11 by rwegat            #+#    #+#              #
#    Updated: 2023/11/17 16:51:15 by rwegat           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
LIBFTNAME = libft.a
LIBFTDIR = ./libft

CFILES =	ft_printchar.c ft_printf.c ft_printptr.c ft_printint.c \
			ft_printunsigned.c ft_printhex.c ft_printpercent.c ft_printstr.c
OFILES = $(CFILES:.c=.o)

all: $(NAME)
$(NAME): $(LIBFTNAME) $(OFILES)
	cp $(LIBFTDIR)/$(LIBFTNAME) $(NAME)
	ar rcs $(NAME) $(OFILES) $(LIBFTDIR)/$(LIBFTNAME)
$(LIBFTNAME):
	make -C $(LIBFTDIR)
clean:
	rm -f $(OFILES)
	cd $(LIBFTDIR) && make clean
fclean: clean
	rm -f $(NAME) $(LIBFTNAME)
	cd $(LIBFTDIR) && make fclean
re: fclean $(NAME)
.PHONY: all clean fclean re