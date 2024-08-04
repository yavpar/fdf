# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 14:44:05 by yparthen          #+#    #+#              #
#    Updated: 2024/08/04 12:13:00 by yparthen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_DIR = src/
OBJS_DIR = objs/

SRC_FILES =	ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_putchar \
		ft_isprint ft_strlen  ft_bzero ft_print_str \
		ft_strlcpy ft_strlcat ft_printf \
		ft_toupper ft_tolower ft_strchr ft_strrchr ft_print_ptr \
		ft_strncmp  ft_strnstr ft_print_int \
		ft_calloc ft_strdup ft_substr ft_len_tab str_in_str \
		ft_strjoin ft_strtrim ft_split ft_itoa ft_print_char \
		ft_strmapi ft_striteri ft_putstr_fd\
		ft_outil_printf ft_char_in_str\
		ft_lstnew ft_lstadd_front ft_free_array ft_abs ft_atol \
		ft_lstsize ft_lstlast ft_lstadd_back ft_lstdelone ft_atoi \
		ft_lstclear ft_lstiter ft_lstmap ft_print_hexadecimal \
		ft_print_unsigned get_next_line get_next_line_utils ft_wc \
		ft_max ft_min ft_htoi ft_putchar_fd

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))
CC	=	clang
CFLAGS	=	-Wall -Wextra -Werror -I.

all : $(NAME)
	@echo "libft compiled"

$(NAME) : $(OBJ)
	@ar rc $@ $^

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o: $(SRC_DIR)%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJS_DIR)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

so:
	@ $(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	@ gcc -nostartfiles -shared -o libft.so $(OBJ)

.PHONY : re clean fclean so all