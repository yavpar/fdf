NAME = fdf

all: ${NAME}
	@echo "Compilation réussie"

SRC_DIR = ./src/
OBJ_DIR = ./obj/
INCLUDE = include
CC = cc
CFLAGS = -Wall -Wextra -Werror -fPIC -g3 -O3
RM = rm -f
FLAGS = -ldl -Imlx -L./mlx/ -lm -lbsd -lXext -lX11 -Wl,-rpath=./bass/,-rpath=./mlx/,-rpath=./delay/ -fPIC
SMAKE = make --no-print-directory

SRC_FILES = fdf get_map parse destroy draw get_color mat_operation

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

PATH_MLX = ./minilibx-linux/
MLX = $(PATH_MLX)libmlx.a
$(MLX):
	@$(MAKE) -C ./minilibx-linux

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -lm -L$(LIBFT_PATH) -lft -L$(PATH_MLX) -lmlx -lXext -lX11 $(FLAGS) -o $(NAME)

.c.o:
	@${CC} ${CFLAGS} -lm -Imlx $(LIBFT) -lft -Ibass -c $< -o ${<:.c=.o}

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

clean:
	@$(RM) -r $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) -C ./minilibx-linux clean

fclean:	clean
	@$(RM) $(NAME)
	@$(SMAKE) -C $(LIBFT_PATH) fclean
	@echo "$(CYAN)$(NAME) executable files cleaned!$(DEF_COLOR)"

forbidden:
	nm -gu $(NAME)

re: fclean all

.PHONY: bonus all clean fclean re









############################################################################################################

# PROGNAME = fdf

# #	Folders
# SRC_DIR = src
# INC_DIR = include

# #	Dir library
# LIBFT_DIR = libft

# #	library name
# LIBFT = $(LIBFT_DIR)/libft.a

# #	Compiler & flags
# CC = cc -g
# CFLAGS = -Wall -Wextra -Werror
# INC_FLAGS = -I$(INC_DIR)

# #	source files
# SRCS = 	fdf.c destroy.c parse.c get_map.c

# # Objetivos predeterminados
# all : $(LIBFT) $(PROGNAME)

# # Rule for libft
# $(LIBFT) :
# 	@ $(MAKE) -C $(LIBFT_DIR)

# # Archivos objeto
# OBJS := $(SRCS:%.c=$(SRC_DIR)/%.o)

# # Rules
# all: $(PROGNAME)

# $(PROGNAME): $(OBJS) $(LIBFT)
# 	@ $(CC) $(CFLAGS) $(INC_FLAGS) -o $@ $^

# $(SRC_DIR)/%.o: $(SRC_DIR)/%.c
# 	@ $(CC) $(CFLAGS) $(INC_FLAGS) -c -o $@ $<

# # Cleanning
# clean :
# 	@ $(MAKE) -C $(LIBFT_DIR) clean
# 	@ rm -f $(OBJS)

# fclean : clean
# 	@ $(MAKE) -C $(LIBFT_DIR) fclean
# 	@ rm -f $(PROGNAME)

# re: fclean all

# .PHONY: all clean fclean re
