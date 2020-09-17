NAME=libftprintf.a
SRCS=ft_atoi.c ft_isdigit.c ft_putchar.c ft_putnbr.c ft_putnbrU.c ft_putstr.c ft_strlen.c ft_strlenD.c test.c
OBJS= $(SRCS:.c=.o)
CC = gcc
all: $(NAME)

$(NAME):
	echo $(SRCS)
	$(CC) -c $(SRCS)
	ar -rc $(NAME) $(OBJS)
	ranlib $(NAME)
	rm -rf $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all 
