NAME = philo
CC = cc
CARG = -Werror -Wextra -Wall
INCs = -Iinclude
SRCs = src/monitor/lock/dead.c \
		src/monitor/end.c \
		src/monitor/init.c \
		src/philo/lock/meal.c \
		src/philo/lock/running.c \
		src/philo/lock/state.c \
		src/philo/fork.c \
		src/philo/init.c \
		src/philo/routine.c \
		src/utils/fts.c \
		src/utils/loop.c \
		src/utils/output.c \
		src/utils/timestamp.c \
		src/utils/usleep.c \
		src/philosopher.c \
		src/main.c
OBJs = $(SRCs:.c=.o)
LIBs = -lpthread

all: $(NAME)

$(NAME) : $(OBJs)
	$(CC) $(CARG) $(LIBs) $(OBJs) -o $@

clean :
	rm -rf $(OBJs)

fclean : clean
	rm -rf $(NAME)

re : fclean all

%.o : %.c
	$(CC) $(CARG) $(INCs) -c $< -o $@
