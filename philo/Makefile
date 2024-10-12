NAME = philo
CC = cc
CARG = -Werror -Wextra -Wall
INCs = -Iinclude
SRCs = src/fork/init.c \
		src/fork/to_fork.c \
		src/philo/lock/state.c \
		src/philo/lock/running.c \
		src/philo/check_state.c \
		src/philo/exec.c \
		src/philo/free_fork.c \
		src/philo/init.c \
		src/philo/is_full.c \
		src/philo/take_fork.c \
		src/philo/to_philo.c \
		src/philo/to_thread.c \
		src/table/lock/dead.c \
		src/table/end.c \
		src/table/free.c \
		src/table/init_times.c \
		src/table/init.c \
		src/table/to_table.c \
		src/utils/pl_utl_atoi.c \
		src/utils/pl_utl_error.c \
		src/utils/pl_utl_is_digit.c \
		src/utils/pl_utl_lst_foreach.c \
		src/utils/pl_utl_message.c \
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
