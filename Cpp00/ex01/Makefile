# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rastie <rastie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 17:56:03 by rastie            #+#    #+#              #
#    Updated: 2024/01/05 15:56:16 by rastie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook 

SOURCE = Contact.cpp\
	PhoneBook.cpp\
	utils.cpp\


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
