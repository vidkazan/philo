NAME = philo

CC = gcc

#FLAGS = -Wall -Wextra -Werror -I./
FLAGS = -I./
SRC = 	main.c time.c forks.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) philo.h
	@$(CC) -o $(NAME) $(FLAGS) $(OBJ)
	@echo OK!

%.o:%.c
	@$(CC) $(FLAGS) -c -o $@ $<

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
