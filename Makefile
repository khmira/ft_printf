NAME=libftprintf.a
SRCS=	ft_collector.c ft_nbrlen.c ft_printc.c ft_printdiu.c ft_printf.c \
		ft_printp.c ft_prints.c ft_printx.c ft_printX.c ft_putnbr.c ft_router.c
INC=	ft_printf.h
OBJS= $(SRCS:.c=.o)
CC = clang -Wall -Wextra -Werror
all: $(NAME)

$(NAME):
	echo $(SRCS)
	$(CC) -c $(INC) $(SRCS)
	ar -rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all 
