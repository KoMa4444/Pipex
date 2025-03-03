PROG =	pipex
MAIN =	src/main.c
SRC = 	src/error_handle.c src/main.c src/matrix_management.c 
OBJ =		$(SRC:.c=.o)

HEADER	= -Iincludes

CC = gcc
CFLAGS = -Wall -Wextra -Werror

.c.o:		%.o : %.c
					@gcc ${CFLAGS} ${HEADER} -c $< -o $(<:.c=.o)

all: 		${PROG}

${PROG}:	${OBJ}
					@echo "\033[33m----Compiling lib----"
					@make re -C lib
					@$(CC) ${OBJ} -Llib -lft -o ${PROG}
					@echo "\033[32mPipex Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"

clean:
					@make clean -C ./lib
					@rm -f ${OBJ}

fclean: 	clean
					@make fclean -C ./lib
					@rm -f ${PROG}
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

.PHONY: all clean fclean re re_bonus bonus party