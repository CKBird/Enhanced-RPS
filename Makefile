#Makefile for RPS LS
RPS.out : main.o RPS.o
	g++ -o RPS.out main.o RPS.o -Wall -g
main.o : main.cpp
	g++ -c main.cpp -Wall -g -o main.o
RPS.o : RPS.cpp RPS.h
	g++ -c RPS.cpp -Wall -g -o RPS.o
