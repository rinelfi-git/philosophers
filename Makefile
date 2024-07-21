NAME = philo
CC = gcc
CARG = -Werror -Wextra -Wall
INCs = -Iinclude
SRCs = src/philo/pl_new.c \
		src/philo/to_philo.c \
		src/philo/to_thread.c \
		src/utils/pl_utl_atoi.c \
		src/utils/pl_utl_lst_foreach.c \
		src/philosopher.c \
		src/main.c
OBJs = $(SRCs:.c=.o)
LIBs = -lpthread

all: $(NAME)

$(NAME) : $(OBJs)
	$(CC) $(CARG) $(OBJs) -o $@
clean :
	rm -rf $(OBJs)

fclean : clean
	rm -rf $(NAME)

re : fclean all

%.o : %.c
	$(CC) $(CARG) $(INCs) $(LIBs) -c $< -o $@
