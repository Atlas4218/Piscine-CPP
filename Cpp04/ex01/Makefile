# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rastie <rastie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 19:19:31 by rastie            #+#    #+#              #
#    Updated: 2024/01/20 16:57:09 by rastie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = ex00

SOURCE = main.cpp\
	 Animal.cpp\
	 Brain.cpp\
	 Cat.cpp\
	 Dog.cpp\
	 WrongAnimal.cpp\
	 WrongCat.cpp\



OBJECT = ${SOURCE:.cpp=.o}

CXXFLAGS = -g3 -std=c++98 -Wall -Wextra -Werror
RM = rm -f
CXX = c++

%.o : ${SRC}/%.cpp 
	${CXX} ${CXXFLAGS} -c $< -o $@

all:	${NAME}

${NAME}: ${OBJECT}
		${CXX} -o ${NAME} ${OBJECT};

clean:
	${RM} ${OBJECT}

fclean:	clean
		${RM} ${NAME};\

re:	fclean all

.PHONY: all clean fclean re
