# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: polmo-lo <polmo-lo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 14:14:17 by polmo-lo          #+#    #+#              #
#    Updated: 2024/06/06 21:02:58 by polmo-lo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = clang

FILES = \
		ft_isalpha.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_isascii.c\
		ft_isalnum.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_strlen.c\
		ft_strlcat.c\
		ft_strlcpy.c\
		ft_strchr.c\
		ft_memset.c\
		ft_bzero.c\
		ft_strncmp.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_memcpy.c\
		ft_memcmp.c\
		ft_memchr.c\
		ft_memmove.c\
		ft_atoi.c\
		ft_calloc.c\
		ft_strdup.c\
		ft_putchar_fd.c\
		ft_substr.c\
		ft_strjoin.c\
		ft_putnbr_fd.c\
		ft_putendl_fd.c\
		ft_putstr_fd.c\
		ft_striteri.c\
		ft_strtrim.c\
		ft_strmapi.c\
		ft_itoa.c\
		ft_split.c\

BONUS_FILE = \
		ft_lstnew_bonus.c\
		ft_lstadd_front_bonus.c\
		ft_lstsize_bonus.c\
		ft_lstlast_bonus.c\
		ft_lstadd_back_bonus.c\
		ft_lstdelone_bonus.c\
		ft_lstclear_bonus.c\
		ft_lstiter_bonus.c\
		ft_lstmap_bonus.c\

OBJ = $(FILES:.c=.o)
BONUS_OBJ = $(BONUS_FILE:.c=.o)
FLAGS = -Wall -Werror -Wextra

$(NAME): $(OBJ)
	@$(CC) -c $(FLAGS) $(FILES)
	@ar rcs $(NAME) $(OBJ)

all: $(NAME)

bonus: $(BONUS_OBJ)
	@$(CC) -c $(FLAGS) $(BONUS_FILE)
	@ar rcs $(NAME) $(BONUS_OBJ)
	@echo "Bonus library $(NAME) created!"

clean:
	@rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

$(OBJ): %.o: %.c
	@$(CC) -c $(FLAGS) $< -o $@

.PHONY: all clean fclean re bonus