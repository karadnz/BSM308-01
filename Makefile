AR	= ar rcs
RM	= rm -f

CC				= gcc
CFLAGS_DEBUG	= -g #-fsanitize=address
CFLAGS			= -I./libfdr/include -I./libmyio/include -I./include/  
CDEBUG			= -g 

SRC_DIR	= src
OBJ_DIR	= obj
BIN_DIR	= bin

MYIO_DIR = libmyio
LIBFDR_DIR = libfdr

MYIO = ./$(MYIO_DIR)/lib/libmyio.a
LIBFDR = ./$(LIBFDR_DIR)/lib/libfdr.a

SRC =	main.c utils.c \
		commands.c command_utils.c \
		write_utils.c
		

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))


BIN		= main.out
NAME	= $(BIN_DIR)/$(BIN)




all: $(NAME)

debug: $(OBJ)
	@cd ./$(MYIO_DIR) && $(MAKE)
	@cd ./$(LIBFDR_DIR) && $(MAKE)
	$(CC) $(CFLAGS) $(CFLAGS_DEBUG) $(OBJ) $(MYIO) $(LIBFDR) -o $(NAME)
	@echo "project is compiled in debug mode."

$(NAME): $(OBJ) $(MYIO) $(LIBFDR)
	$(CC) $(CFLAGS) $(OBJ) $(MYIO) $(LIBFDR) -o $(NAME)
	@echo "project is compiled."

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	$(CC) $(CFLAGS) -c $< -o $@

$(MYIO): 
	@cd ./$(MYIO_DIR) && $(MAKE)

$(LIBFDR): 
	@cd ./$(LIBFDR_DIR) && $(MAKE)

client:
	@gcc ./client.c -o client
	@echo "client is compiled."

run: all
	./$(NAME)

clean:
	@cd ./$(LIBFDR_DIR) && $(MAKE) clean
	@cd ./$(MYIO_DIR) && $(MAKE) clean
	rm -f $(OBJ)
	@echo "Cleaned"

fclean: clean
	rm -f $(NAME)
	rm -rf client
	@echo "Fully cleaned"
	

re: fclean
	@make all

.PHONY: all clean fclean run re client

