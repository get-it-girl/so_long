NAME	= libft.a

HEADER	= libft.h

SRC		=	ft_isascii.c            ft_memmove.c            ft_strdup.c             ft_strnstr.c\
			ft_isdigit.c            ft_memset.c             ft_striteri.c           ft_strrchr.c\
			ft_isprint.c            ft_putchar_fd.c         ft_strjoin.c            ft_strtrim.c\
			ft_itoa.c               ft_putendl_fd.c         ft_strlcat.c            ft_substr.c\
			ft_putnbr_fd.c          ft_strlcpy.c            ft_tolower.c\
			ft_memchr.c             ft_putstr_fd.c          ft_strlen.c             ft_toupper.c\
			ft_memcmp.c             ft_split.c              ft_strmapi.c            ft_atoi.c\
			ft_memcpy.c             ft_strchr.c             ft_strncmp.c            ft_bzero.c\
			ft_calloc.c             ft_isalnum.c            ft_isalpha.c		

SRC_B	=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstsize.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c

OBJ		= ${patsubst %.c,%.o,${SRC}}

OBJ_B	= ${patsubst %.c,%.o,${SRC_B}}

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

all:		${NAME}

${NAME}:	${OBJ} ${HEADER}
			ar rcs ${NAME} $?

%.o : %.c
			${CC} ${CFLAGS} -c $< -o $@

bonus:		${HEADER} ${OBJ_B}
			make OBJ="${OBJ_B}" all

clean:	
			${RM} ${OBJ} ${OBJ_B}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
