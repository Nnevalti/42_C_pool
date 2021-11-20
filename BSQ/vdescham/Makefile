NAME = bsq

SRCS = 	srcs/ft_utils.c srcs/ft_manageerr.c \
		srcs/ft_parsing.c srcs/ft_chars.c srcs/ft_launch.c \
		srcs/ft_gridsolving.c srcs/ft_free.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

RM = /bin/rm -f

.c.o:
	gcc $(FLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	gcc -o $(NAME) main.c $(OBJS)
	make clean

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
