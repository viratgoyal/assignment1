all:hello
hello:main.o
	g++ main.o -o main
main.o:main.cpp array.h
	g++ -c main.cpp