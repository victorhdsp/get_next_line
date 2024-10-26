NAME=gnl.out
FILES=get_next_line.o get_next_line_utils.o main.o
CC=cc -Wall -Wextra -Werror -I . -g

all: $(NAME)

$(NAME): $(FILES)
	$(CC) $^ -o $(NAME)

.o: .c
	$(CC) -o $@ -c $<

clean:
	rm -rf $(FILES)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: all $(NAME) clean fclean re