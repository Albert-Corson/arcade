##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

CC			=	g++

SRC			=	main.cpp			\
				Clock.cpp			\
				Resource.cpp		\
				GameStorage.cpp		\
				LibGraphStorage.cpp	\
				Core.cpp

OBJ			=	$(SRC:.cpp=.o)

DEBUG		=	-g

CXXFLAGS	=	$(COMMON_CXXFLAGS)
CXXFLAGS	+=	-I../ -I./
CXXFLAGS	+=	-ldl -lstdc++fs

NAME		=	../arcade

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CXXFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

debug:
	make all COMMON_CXXFLAGS="$(COMMON_CXXFLAGS) $(DEBUG)"

.PHONY: all clean fclean re