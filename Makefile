SRCS =	main.c \
		check_map.c \
		ft_atoi.c \
		map_function.c \
		parsemap.c \
		create_map_file.c \
		ft_split.c \
		find_bsq.c \
		ft_strings.c

OBJS = ${SRCS:.c=.o}

NAME = bsq

CC = gcc

CFLAGS = -Wall -Wextra -Werror

${NAME}: ${OBJS}
		 ${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

.PHONY: all clean fclean
