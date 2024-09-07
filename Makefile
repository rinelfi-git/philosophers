NAME = philo
CC = cc
CARG = -Werror -Wextra -Wall
INCs = -Iinclude
SRCs = src/fork/new.c \
		src/fork/to_fork.c \
		src/philo/check_state.c \
		src/philo/eat.c \
		src/philo/exec.c \
		src/philo/free_fork.c \
		src/philo/new.c \
		src/philo/set_time.c \
		src/philo/sleep.c \
		src/philo/take_fork.c \
		src/philo/think.c \
		src/philo/to_philo.c \
		src/philo/to_thread.c \
		src/table/init_times.c \
		src/table/free.c \
		src/table/new.c \
		src/utils/pl_utl_atoi.c \
		src/utils/pl_utl_error.c \
		src/utils/pl_utl_lst_foreach.c \
		src/utils/pl_utl_timestamp.c \
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
