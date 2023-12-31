NAME = ex03

SOURCE = main.cpp\
	HumanA.cpp\
	HumanB.cpp\
	Weapon.cpp\
	
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
