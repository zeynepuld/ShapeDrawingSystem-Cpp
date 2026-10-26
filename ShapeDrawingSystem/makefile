all: derle calistir

derle:
	g++ -I ./include/ -o ./lib/MainList.o -c ./src/MainList.cpp
	g++ -I ./include/ -o ./lib/Rectangle.o -c ./src/Rectangle.cpp
	g++ -I ./include/ -o ./lib/Shape.o -c ./src/Shape.cpp
	g++ -I ./include/ -o ./lib/ShapesList.o -c ./src/ShapesList.cpp
	g++ -I ./include/ -o ./lib/Star.o -c ./src/Star.cpp
	g++ -I ./include/ -o ./lib/Triangle.o -c ./src/Triangle.cpp
	g++ -I ./include/ -o ./lib/ReadFile.o -c ./src/ReadFile.cpp
	g++ -I ./include/ -o ./lib/Application.o -c ./src/Application.cpp
	g++ -I ./include/ -o ./lib/main.o -c ./src/main.cpp

	g++ -I ./include/ -o ./bin/main ./lib/Application.o ./lib/MainList.o ./lib/ReadFile.o ./lib/Rectangle.o ./lib/Shape.o ./lib/ShapesList.o ./lib/Star.o ./lib/Triangle.o ./lib/main.o

calistir:
	./bin/main