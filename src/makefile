all: ProjectT9
ProjectT9: Main.o BSTreeMap.o LinkedListMap.o String.o StringT9.o
	gcc -Wall -o ProjectT9 BSTreeMap.o LinkedListMap.o Main.o String.o util.o StringT9.o
Main.o:
	gcc -Wall -B ../bin -o ../bin/Main.o Main.c `pkg-config --cflags --libs gtk+-3.0`
BSTreeMap.o:
	gcc  -Wall -B ../bin -o ../bin/BSTreeMap.o BSTreeMap.h
LinkedListMap.o:
	gcc  -Wall -B ../bin -o ../bin/LinkedListMap.o LinkedListMap.h
String.o:
	gcc  -Wall -B ../bin -o ../bin/String.o String.h
StringT9.o:
	gcc  -Wall -B ../bin -o ../bin/StringT9.o StringT9.h

