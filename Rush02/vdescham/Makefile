NAME	=	rush-02

DIR		=	srcs/

SRCS	=	$(DIR)main.c \
			$(DIR)check_nbr.c \
			$(DIR)ft_tools.c \
			$(DIR)findaname.c \
			$(DIR)manage_err.c \
			$(DIR)manage_dup.c \
			$(DIR)ft_end.c \

DIRH	=	includes/

OBJS	=	$(SRCS:%.c=%.o)

CFLAGS	=	-Wall -Wextra -Werror

CC		=	gcc

RM		=	rm -f

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I./$(DIRH)

$(NAME):	$(OBJS)
			$(CC) -o $(NAME) $(OBJS)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		re all clean fclean