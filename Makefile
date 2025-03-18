# Variables
NAME = push_swap
LIBFT_DIR = ./Libft
FT_PRINTF_DIR = ./printf
CC = cc -g
CFLAGS = -Wall -Wextra -Werror

# Source files for server and client
SRCS = ./commands/push.c \
	   ./commands/reverse_rotate.c \
	   ./commands/rotate.c \
	   ./commands/swap.c \
	   check_errors.c \
	   init_a_to_b.c \
	   init_b_to_a.c \
	   init_list.c \
	   push_swap.c \
	   sort_list.c \
	   sort_utils.c \
	   split.c \
	   utils.c \

OBJS = $(SRCS:.c=.o)

# Libraries
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

# Rules
all: $(NAME)

# Build push_swap
$(NAME): Libft/libft.a printf/libftprintf.a $(OBJS)
	@echo "\033[1;32m [OK] \033[0m	\033[1;35m push_swap built successfully!\033[0m"
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf -o $(NAME)

# Build libft library
Libft/libft.a:
	@echo "\033[1;93m [WAIT]\033[0m\t\033[1;35m libft is being built...\033[0m"
	@$(MAKE) -s -C $(LIBFT_DIR)
	@echo "\033[1;32m [OK] \033[0m	\033[1;35m libft built successfully!\033[0m"

# Build ft_printf library
printf/libftprintf.a:
	@echo "\033[1;93m [WAIT]\033[0m\t\033[1;35m printf is being built...\033[0m"
	@$(MAKE) -s -C $(FT_PRINTF_DIR)
	@echo "\033[1;32m [OK] \033[0m	\033[1;35m ft_printf built successfully!\033[0m"

# Clean object files
clean:
	@echo "\033[1;32m [OK] \033[0m	\033[1;35m removing object files...\033[0m"
	@rm -f $(OBJS)
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@$(MAKE) -s -C $(FT_PRINTF_DIR) clean

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

# Clean everything (including compiled libraries and binaries)
fclean: clean
	@echo "\033[1;32m [OK] \033[0m	\033[1;35m removing binary and libraries...\033[0m"
	@rm -f $(NAME)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@$(MAKE) -s -C $(FT_PRINTF_DIR) fclean

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re libft printf
