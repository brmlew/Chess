CXX = g++-5
CXXFLAGS = -g -std=c++14 -Wall -MMD -Werror=vla
#CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = chess
OBJECTS = main.o board.o display.o piece.o king.o queen.o knight.o bishop.o rook.o pawn.o empty.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
		${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
		rm ${OBJECTS} ${EXEC} ${DEPENDS}

