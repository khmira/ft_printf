NAME=libftprintf.a
SRCS=ft_atoi.c ft_isdigit.c ft_putchar.c ft_putnbr.c ft_putnbrU.c ft_putstr.c ft_strlen.c ft_strlenD.c ft_router.c ft_printX.c ft_printx.c ft_printu.c ft_prints.c ft_printp.c ft_printi.c ft_printd.c ft_printc.c ft_nrblen.c ft_collector.c 
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
