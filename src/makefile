all: ProjectT9

ProjectT9: bin Main.o BSTreeMap.o LinkedListMap.o String.o StringT9.o
	cd ../bin && gcc BSTreeMap.o LinkedListMap.o Main.o String.o StringT9.o -o ProjectT9

Main.o: bin
	gcc -Wall -B ../bin -o ../bin/Main.o Main.c `pkg-config --cflags --libs gtk+-3.0`

BSTreeMap.o: bin
	gcc  -Wall -B ../bin -o ../bin/BSTreeMap.o BSTreeMap.h

Dictionary.o: String.o
	gcc  -Wall -B ../bin -o ../bin/Dictionary.o Dictionary.h ../bin/String.o

Integer.o: bin
	gcc  -Wall -B ../bin -o ../bin/Integer.o Integer.h

LinkedListMap.o: bin
	gcc  -Wall -B ../bin -o ../bin/LinkedListMap.o LinkedListMap.h

String.o: bin
	gcc  -Wall -B ../bin -o ../bin/String.o String.h

StringT9.o: bin
	gcc  -Wall -B ../bin -o ../bin/StringT9.o StringT9.h

bin:
	mkdir -p ../bin

clean: 
	rm -r ../bin
