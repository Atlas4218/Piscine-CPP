# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rastie <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 17:56:03 by rastie            #+#    #+#              #
#    Updated: 2023/10/24 22:44:14 by rastie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex00 

SOURCE = main.cpp\
	newZombie.cpp\
	randomChump.cpp\
	Zombie.cpp\



OBJECT = ${SOURCE:.cpp=.o}

CXXFLAGS = -g3 -std=c++98 -Wall -Wextra -Werror
RM = rm -f
CXX = c++

${BIN}/%.o : ${SRC}/%.cpp 
	mkdir -p ${BIN};\
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
