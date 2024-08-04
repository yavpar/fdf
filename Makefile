NAME = fdf
NAME_BONUS = fdf

all: ${NAME}
	@echo "Compilation succesfull"

SRC_DIR = ./src/
OBJ_DIR = ./obj/
OBJ_DIR_BONUS = ./obj_bonus/
SRC_DIR_BONUS = ./src_bonus/
INCLUDE = include
INCLUDE_BONUS = include_bonus
CC = gcc
CFLAGS = -Wall -Wextra -Werror -O1 -g3 -fPIC
RM = rm -f
FLAGS = -ldl -Imlx -L./mlx/ -lm -lbsd -lXext -lX11 -fPIC
SMAKE = make --no-print-directory
SRC_FILE = fdf input init parse destroy draw color mat_operation parse_utils
SRC_FILES_BONUS = fdf_bonus input_bonus init_bonus parse_bonus destroy_bonus \
				draw_bonus color_bonus mat_operation_bonus \
				parse_utils_bonus

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILE)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILE)))
SRC_BONUS = $(addprefix $(SRC_DIR_BONUS), $(addsuffix .c, $(SRC_FILES_BONUS)))
OBJ_BONUS = $(addprefix $(OBJ_DIR_BONUS), $(addsuffix .o, $(SRC_FILES_BONUS)))

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
#Libft libray
$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

PATH_MLX = ./minilibx-linux/
MLX = $(PATH_MLX)libmlx.a
#MLX library
$(MLX):
	@$(MAKE) -C $(PATH_MLX)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR_BONUS):
	@mkdir -p $(OBJ_DIR_BONUS)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -lm -L$(LIBFT_PATH) -lft -L$(PATH_MLX) -lmlx $(FLAGS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

$(OBJ_DIR_BONUS)%.o: $(SRC_DIR_BONUS)%.c | $(OBJ_DIR_BONUS)
	@$(CC) $(CFLAGS) -I $(INCLUDE_BONUS) -c $< -o $@

bonus: $(LIBFT) $(MLX) $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -lm -L$(LIBFT_PATH) -lft -L$(PATH_MLX) -lmlx $(FLAGS) -o $(NAME_BONUS)
	@echo "Bonus compilation succesfull"

clean:
	@$(RM) -r $(OBJ_DIR) $(OBJ_DIR_BONUS)
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) -C $(PATH_MLX) clean

fclean:	clean
	@$(RM) $(NAME) $(NAME_BONUS)
	@$(SMAKE) -C $(LIBFT_PATH) fclean
	@echo "$(NAME) executable files cleaned!"

re: fclean all

.PHONY: bonus all clean fclean re