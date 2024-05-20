NAME		= libftprintf.a
CFLAGS		= -Wall -Wextra -Werror
SRCDIR		= srcs
OBJS		= $(addprefix $(SRCDIR)/, ft_printf.o utils.o)
SRCS		= $(OBJS:.o=.c)
LIBFT_PATH	= ./libft
LIBFT		= libft.a

.PHONY: all clean fclean re

all: $(NAME)


# $(NAME): $(OBJS)
# 	cc $(CFLAGS) $^ -o prog $(LIBFT_PATH)/$(LIBFT)


$(NAME): $(OBJS)
	@mv $(LIBFT_PATH)/$(LIBFT) $(NAME)
	ar qs $(NAME) $^


$(LIBFT_PATH)/$(LIBFT):
	make -C $(LIBFT_PATH)

$(SRCDIR)/%.o: $(SRCDIR)/%.c $(LIBFT_PATH)/$(LIBFT)
	gcc $(CFLAGS) -c $< -o $@ -I./includes -I$(LIBFT_PATH)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)
	make -C $(LIBFT_PATH) fclean

re: fclean all
