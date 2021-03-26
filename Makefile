SRCS		= 	prompt.c \
				operations.c \
				stack_operation.c \
				print.c \
				quicksort.c \
				insertsort.c \
				customsort.c \
				utils_cmp.c \
				utils_stack.c
OBJS		= ${SRCS:.c=.o}
CC			= clang
CFLAGS		= -Wall -Wextra -Werror
CHECKER		= checker
RM			= rm -f

%.o :			%.c
				${CC} ${CFLAGS} -Ilibft -c $<
all :			${CHECKER}
${CHECKER} :	checker.o push_swap.o ${OBJS}
				cd libft && make
				clang -o ${CHECKER} checker.o ${OBJS} libft/libft.a
				clang -o push_swap push_swap.o ${OBJS} libft/libft.a
clean :
				${RM} ${OBJS} checker.o push_swap.o
				cd libft && make clean
fclean :		clean
				${RM} ${CHECKER} push_swap
				cd libft && make fclean
re :			fclean all
.PHONY :
			all ${CHECKER} clean fclean re
