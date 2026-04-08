compile: obj/main.o obj/functions.o
	g++ -o bin/main obj/main.o obj/functions.o

obj/main.o: src/main.cpp include/functions.h
	g++ -c src/main.cpp -o obj/main.o

obj/functions.o : src/functions.cpp include/functions.h
	g++ -c src/functions.cpp -o obj/functions.o

clean:
	rm -f bin/main obj/*o
	clear
exec: compile
	@bin/./main
