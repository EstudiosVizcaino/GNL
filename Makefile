
NAME = libgetnextline.a
NAME_BONUS = libgetnextline_bonus.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRCS =	get_next_line.c\
		get_next_line_utils.c

SRCS_BONUS = get_next_line_bonus.c\
		get_next_line_utils_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -c $(SRCS)
	ar rc $(NAME) $(OBJS)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) -c $(SRCS)
	ar rc $(NAME_BONUS) $(OBJS_BONUS)

bonus: $(NAME_BONUS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
