LIBFT_DIR=libft/
INCL_DIR=head/
SRC_DIR=code/
OBJ_DIR=code/

NAME = libftprintf.a

LIBFT_OBJ = ft_lstadd_back.o ft_lstclear.o ft_lstiter.o ft_lstnew.o ft_strchr.o ft_strlen.o ft_lstlast.o
LIBFT_OBJS = $(addprefix $(LIBFT_DIR), $(LIBFT_OBJ))

LIBFT_OBJ_BONUS = ft_lstadd_back.o ft_lstclear.o ft_lstiter.o ft_lstnew.o ft_strchr.o ft_strlen.o ft_lstlast.o ft_atoi.o ft_isdigit.o
LIBFT_OBJS_BONUS = $(addprefix $(LIBFT_DIR), $(LIBFT_OBJ_BONUS))

SRC_FILES = ft_printf.c split_format_str.c parse_format_str.c output_general.c \
output_type.c
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS = ${SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o}


BONUS_FILES = ft_printf_bonus.c split_format_str_bonus.c \
parse_format_str_bonus.c output_general_bonus.c output_general_bonus2.c \
output_str_char_bonus.c output_hex_int_ptr_bonus.c inner_length_bonus.c
BONUS_SRCS = $(addprefix $(SRC_DIR), $(BONUS_FILES))
BONUS_OBJS = ${BONUS_SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o}

CC = cc

CFLAGS = -Wall -Werror -Wextra -I$(LIBFT_DIR) -I$(INCL_DIR)

$(NAME): $(OBJS)
	make -C libft
	ar rcs $(NAME) $(OBJS) $(LIBFT_OBJS)

bonus: $(BONUS_OBJS)
	make -C libft
	rm -f $(NAME)
	ar rcs $(NAME) $(BONUS_OBJS) $(LIBFT_OBJS_BONUS)

all: $(NAME) bonus

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ ${@:$(OBJ_DIR)%.o=$(SRC_DIR)%.c}

$(BONUS_OBJS): $(BONUS_SRCS)
	$(CC) $(CFLAGS) -c -o $@ ${@:$(OBJ_DIR)%.o=$(SRC_DIR)%.c}

clean:
	make clean -C ./libft
	rm -f $(OBJS) $(BONUS_OBJS)

fclean:
	make fclean -C ./libft
	rm -f $(OBJS) $(BONUS_OBJS)
	rm -rf $(NAME)

re: fclean all
