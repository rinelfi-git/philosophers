NAME = librj.a
CC = cc
ARCH = ar rcs
CARG = -Werror -Wextra -Wall
INCs = -Iinclude
SRCs = src/to_obj.c
OBJs = $(SRCs:.c=.o)
LIBs = \

all: $(NAME)

$(NAME) : $(OBJs)
	$(ARCH) $(NAME) $(OBJs)
clean :
	rm -rf $(OBJs)

fclean : clean
	rm -rf $(NAME)

re : fclean all

%.o : %.c
	$(CC) $(CARG) $(INCs) $(LIBs) -c $< -o $@
