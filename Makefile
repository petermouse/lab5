all:lab5.o HugeInt.o
	g++ -o lab5 lab5.o HugeInt.o
lab5.o:lab5.cpp HugeInt.h
	g++ -c lab5.cpp HugeInt.h
HugeInt.o:HugeInt.cpp HugeInt.h
	g++ -c HugeInt.cpp HugeInt.h
