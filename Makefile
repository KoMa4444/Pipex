NAME =	pipex

SRC = 	src/main.c src/error_handle.c src/matrix_management.c 	\
				src/find_path.c src/execute_comm.c
OBJ =		$(SRC:.c=.o)

HEADER	= -Iinc

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

%.o : %.c
	@$(CC) ${CFLAGS} ${HEADER} -c $< -o $@

all: 		${NAME}

${NAME}:	${OBJ}
	@echo "\033[33m----Compiling lib----"
	@make re -C lib
	@$(CC) -g ${OBJ} -Llib -lft -o ${NAME}
	@echo "\033[32mPipex Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"

clean:
	@make clean -C ./lib
	@rm -f ${OBJ}

fclean: 	clean
	@make fclean -C ./lib
	@rm -f ${NAME}
	@echo "\n\033[31mDeleting EVERYTHING! ⌐(ಠ۾ಠ)¬\n"

re:			fclean all

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

.PHONY: all clean fclean re party