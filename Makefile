NAME = pipex
SRC = src/error_handle.c src/main.c

all:

	@echo Creando la librería...
	@make re -C lib
	@echo Compilando el programa...
	@gcc -Wall -Wextra -Werror -g $(SRC) ./lib/inc_lib.a -o $(NAME)
	@echo Enhorabuena, pipex fue compilado con éxito