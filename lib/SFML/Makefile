##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

CC			=	g++

SRC			=	LibGraphSFML.cpp	\
				lib_communs.cpp

OBJ			=	$(SRC:.cpp=.o)

CXXFLAGS	=	$(COMMON_CXXFLAGS)
CXXFLAGS	+=	-fPIC			\
				-I../ -I../../

LDLIBS		=	-lsfml-graphics	\
				-lsfml-window	\
				-lsfml-system	\
				-lsfml-audio

NAME		=	../lib_arcade_sfml.so

$(NAME): $(OBJ)
	$(CC) -shared -o $(NAME) $(OBJ) $(LDLIBS)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re