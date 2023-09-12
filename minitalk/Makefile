NAME_C = client
NAME_S = server
NAME_C_B = client_bonus
NAME_S_B = server_bonus
FLAGS = -Wall -Wextra -Werror
FILE1 = client.c 
FILE2 = server.c
FILE3 = client_bonus.c
FILE4 = server_bonus.c
CC = gcc

all: 
	$(CC) $(FLAGS) $(FILE1) -o $(NAME_C) 

	$(CC) $(FLAGS) $(FILE2) -o $(NAME_S)
 
clean:
	rm -f server
	rm -f client

bonus: 
		$(CC) $(FLAGS) $(FILE3) -o $(NAME_C_B)

		$(CC) $(FLAGS) $(FILE4) -o $(NAME_S_B)

fclean:
	rm -f $(NAME_C_B)
	rm -f $(NAME_S_B)

re: clean all 

rebonus: 
	fclean	bonus

.PHONY: all clean re bonus fclean rebonus  