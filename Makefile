# Variables
NAME = push_swap
LIBFT_DIR = ./Libft
FT_PRINTF_DIR = ./printf
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Source files for server and client
SRCS = server.c

OBJS = $(SRCS:.c=.o)

# Libraries
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

# Rules
all: $(LIBFT) $(FT_PRINTF) $(NAME)

# Build server
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf -o $(NAME)

# Build libft library
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Build ft_printf library
$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

# Clean object files
clean:
	rm -f $(OBJS) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean

# Clean everything (including compiled libraries and binaries)
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re