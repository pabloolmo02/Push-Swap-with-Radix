NAME      = pushswap
LIBFT_DIR = ./libft
LIBFT     = $(LIBFT_DIR)/libft.a

CC        = gcc
CFLAGS    = -Wall -Wextra -Werror
INCLUDES  = -I$(LIBFT_DIR)

SRCS      = main.c operations.c sort.c utils.c parse.c
OBJS      = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re