NAME 	= cub3d

CC 		= gcc

 CFLAGS 	= -g -fsanitize=address #-Wall -Wextra -Werror

SRCS = $(wildcard *.c) $(wildcard */*.c)

all: $(NAME)

OBJS	= $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	@$(CC) -g -fsanitize=address -lmlx -framework OpenGL -framework AppKit  $^ -o $@
%.o:%.c
	@$(CC) $(CFLAGS) -c $^ -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all