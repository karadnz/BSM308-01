

AR	= ar rcs
RM	= rm -f

CC				= gcc -g
CFLAGS_DEBUG	= -I ./include/ -fsanitize=address
CFLAGS			= -I ./libfdr/include -I ./include/  -L./libfdr/lib -lfdr #no lib prefix and .a suffix 
CDEBUG			= -g 




SRC_DIR	= src
OBJ_DIR	= obj
BIN_DIR	= bin



SRC =	main.c utils.c \
		commands.c command_utils.c


		
		

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))


BIN		= main
NAME	= $(BIN_DIR)/$(BIN)




all: $(NAME)

# despite its name -g is default this target adds -fsanitize=adress
debug: $(OBJ) | $(BIN_DIR)
	@$(CC) $(CFLAGS_DEBUG) $(OBJ) $(ARC) $(FRMS) -o $(NAME)
	@echo "server data is compiled."

$(NAME): $(OBJ) | $(BIN_DIR)
	@$(CC) $(CFLAGS) $(OBJ) $(ARC) $(FRMS) -o $(NAME)
	@echo "server is compiled."

$(CLIENT): $(OBJ) | $(BIN_DIR)
	@$(CC) $(CFLAGS) $(OBJ) $(ARC) $(FRMS) -o $(NAME)
	@echo "server is compiled."

# find better way to debug
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC)  $(CFLAGS) $(CDEBUG) -c $< -o $@

client:
	@gcc ./client.c -o client
	@echo "client is compiled."

run: all
	./$(NAME) giris.dat

clean:
	rm -f $(OBJ)
	@echo "Cleaned"

fclean: clean
	rm -f $(NAME)
	rm -rf client
	@echo "Fully cleaned"
	

re: fclean
	@make all

.PHONY: all clean fclean run re client

