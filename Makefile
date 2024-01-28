NAME = pipex

SRCS = main.c message_error.c path.c

OBJS=$(SRCS:.c=.o)

RM=rm -f

CC= clang

CFLAGS= -Wall -Wextra -Werror -I./libft/includes -g

all: $(NAME)

$(NAME) : $(OBJS)
	@$(MAKE) --directory ./libft > /dev/null 2>&1
	@$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a -o $@
	@if [ $$? -eq 0 ]; then \
		echo "\033[32;1mCompilation successful!\033[0m"; \
	fi

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ 

clean: 
	@$(RM) $(OBJS)
fclean: clean
	@$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re