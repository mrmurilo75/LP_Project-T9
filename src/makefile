all: ProjectT9

ProjectT9: bin Main.o BSTreeMap.o LinkedListMap.o String.o StringT9.o
	gcc Main.c BSTreeMap.h Dictionary.h LinkedListMap.h String.h StringT9.h -o ../bin/ProjectT9 `pkg-config --cflags --libs gtk+-3.0`

Main.o: bin
	gcc -Wall -B ../bin -o ../bin/Main.o Main.c Dictionary.h String.h `pkg-config --cflags --libs gtk+-3.0`

BSTreeMap.o: bin
	gcc  -Wall -B ../bin -o ../bin/BSTreeMap.o BSTreeMap.h

Dictionary.o: String.o
	gcc  -Wall -B ../bin -o ../bin/Dictionary.o Dictionary.h String.h

HashMap.o: bin
	gcc  -Wall -B ../bin -o ../bin/HashMap.o HashMap.h

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
