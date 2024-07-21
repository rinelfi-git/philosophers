NAME = philo
CC = gcc
CARG = -Werror -Wextra -Wall
INCs = -Iinclude -Ilib/librj/include
SRCs = src/philo/pl_new.c \
		src/philo/to_philo.c \
		src/philo/to_thread.c \
		src/utils/pl_utl_atoi.c \
		src/utils/pl_utl_lst_foreach.c \
		src/philosopher.c \
		src/main.c
OBJs = $(SRCs:.c=.o)
LIBs = -lpthread \
		-Llib/librj -lrj
LIBRJ = lib/librj/librj.a

all: $(NAME)

$(NAME) : $(OBJs) $(LIBRJ)
	$(CC) $(CARG) $(OBJs) -o $@

clean :
	rm -rf $(OBJs)
	make -C lib/librj $@

fclean : clean
	rm -rf $(NAME)
	make -C lib/librj $@

re : fclean all

%.o : %.c
	$(CC) $(CARG) $(INCs) $(LIBs) -c $< -o $@

$(LIBRJ) :
	make -C lib/librj
