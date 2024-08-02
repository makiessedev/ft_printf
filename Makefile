NAME	= libftprintf.a
CC	= cc
CFLAGS	= -Wall -Wextra -Werror -I.
RM	= rm -rf

C_FILES	= ft_printf.c util_numbers.c util_strings.c
C_OBJ	= $(C_FILES:.c=.o)

all: $(NAME)

$(NAME): $(C_OBJ)
	ar rcs $@ $?

clean:
	$(RM) $(C_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean
	make

.PHONY: all clean fclean re
