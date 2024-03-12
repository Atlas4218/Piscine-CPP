# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rastie <rastie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 19:19:31 by rastie            #+#    #+#              #
#    Updated: 2024/03/12 18:02:29 by rastie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = RPN

SOURCE = main.cpp\
		RPN.cpp\
		
OBJECT = ${SOURCE:.cpp=.o}

CXXFLAGS = -std=c++98 -Wall -Wextra -Werror -g3
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
