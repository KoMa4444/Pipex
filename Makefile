NAME = pipex
SRC = 	src/error_handle.c src/main.c src/matrix_management.c 

all:

	@echo Creando la librería...
	@make re -C lib
	@echo Compilando el programa...
	@gcc -Wall -Wextra -Werror -g $(SRC) ./lib/inc_lib.a -o $(NAME)
	@echo Enhorabuena, pipex fue compilado con éxito

party:
					@printf "\033c"
					@echo "\n\033[35m♪┏(・o･)┛♪"
					@sleep 0.5
					@printf "\033c"
					@echo "\033[1;33m♪┗(・o･)┓♪"
					@sleep 0.5
					@printf "\033c"
					@echo "\n\033[36m♪┏(・o･)┛♪"
					@sleep 0.5
					@printf "\033c"
					@echo "\033[34m♪┗(・o･)┓♪\n"
					@sleep 0.5
					@printf "\033c"
					@echo "\n\033[32m♪┏(・o･)┛♪"
					@sleep 0.5
					@printf "\033c"
					@echo "\033[1;33m♪┗(・o･)┓♪"
					@sleep 0.5
					@printf "\033c"
					@echo "\n\033[36m♪┏(・o･)┛♪"
					@sleep 0.5
					@printf "\033c"
					@echo "\033[37m♪┗(・o･)┓♪\n"
					@printf "\033c"
					@echo "\033[33mhola buenos dias"

