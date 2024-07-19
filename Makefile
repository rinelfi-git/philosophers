NAME = philosopher
CC = gcc
CARG = -Werror -Wextra -Wall
INCLUDE = -Iinclude
SRCs = src/philo/ft_new.c \
		src/philo/ft_cast.c \
		src/main.c
OBJs = $(SRCs:.c=.o)

all: $(NAME)

$(NAME) : $(OBJs) 
	$(CC) $(CARG) $(OBJs) -o $@
clean :
	rm -rf $(OBJs)

fclean : clean
	rm -rf $(NAME)

re : fclean all

%.o : %.c
	$(CC) $(CARG) $(INCLUDE) -c $< -o $@
