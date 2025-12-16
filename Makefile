CC = cc
FLAG = -Wall -Wextra -Werror

NAME = pipex

LIBFT = libft/libft.a

SRCS = 	pipex.c \
		pipex_utils.c

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(FLAG) -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT):
	make -C libft

%.o: %.c
	$(CC) $(FLAG) -c $< -o $@

clean:
	rm -rf $(OBJS)
	make clean -C libft

fclean: clean
	rm -rf $(NAME)
	rm -rf libft/libft.a
	rm -rf libft.a

re:	fclean all

.PHONY: all, clean, fclean, re