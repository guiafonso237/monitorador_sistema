compile: obj/main.o obj/functions.o obj/files_class.o
	g++ -o bin/main obj/main.o obj/functions.o obj/files_class.o
	clear

obj/main.o: src/main.cpp include/functions.h
	g++ -c src/main.cpp -o obj/main.o

obj/functions.o : src/functions.cpp include/functions.h include/files_class.h
	g++ -c src/functions.cpp -o obj/functions.o

obj/files_class.o : src/files_class.cpp include/files_class.h
	g++ -c src/files_class.cpp -o obj/files_class.o

clean:
	rm -f bin/main obj/*o
	clear
	
exec: compile
	@bin/./main
