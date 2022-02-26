# 	raylib	 #
raylib_things = -lraylib -lopengl32 -lgdi32 -lwinmm
include = ../../srcRaylib/include/
lib = ../../srcRaylib/lib/

# 	compile	 #
flags = -O2 -Wall -Wno-missing-braces -flto
CXX ?= g++ 

# 	files	 #
filename = Snake
objects = game.o main.o snake.o apple.o board.o

.PHONY: all clean run


all: run clean

run: ${objects}
	${CXX} -o ${filename} ${objects} ${flags} -I ${include} -L ${lib} ${raylib_things}

main.o:
	${CXX} -o main.o -c ../main.cpp -I ${include}

game.o:
	${CXX} -o game.o -c ../game.cxx -I ${include}

board.o:
	${CXX} -o board.o -c ../Resources/board.cxx -I ${include}

snake.o:
	${CXX} -o snake.o -c ../Resources/snake.cxx -I ${include}

apple.o:
	${CXX} -o apple.o -c ../Resources/apple.cxx -I ${include}


# 	make command need "rm *.o" to be there				#
# 	unless u use mingw32-make then it will cause error 	#
# 	and u need to change it to "del *.o" 				#
clean: 
	rm *.o
	${filename}