# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 14:44:05 by yparthen          #+#    #+#              #
#    Updated: 2024/05/08 15:33:17 by yparthen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_putchar.c \
		ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_print_str.c \
		ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_printf.c \
		ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_print_ptr.c \
		ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_print_int.c \
		ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_len_tab.c\
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_print_char.c \
		ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_outil_printf.c ft_char_in_str.c\
		ft_lstnew.c ft_lstadd_front.c ft_free_array.c ft_abs.c ft_atol.c \
		ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
		ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_print_hexadecimal.c \
		ft_print_unsigned.c get_next_line.c get_next_line_utils.c ft_wc.c

CC	=	clang
CFLAGS	=	-Wall -Wextra -Werror -I.

OBJ =    $(SRC:.c=.o)


all : $(NAME)

$(NAME) : $(OBJ)
	@ ar rcv $@ $^

%.o : %.c
	@ $(CC) $(CFLAGS) -c $< -o $@

clean :
	@ rm -rf $(OBJ)

fclean : clean
	@ rm -rf $(NAME)

re : fclean all

# so:
# 	@ $(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
# 	@ gcc -nostartfiles -shared -o libft.so $(OBJ)

.PHONY : re clean fclean so all
