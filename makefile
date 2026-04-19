compile: obj/main.o obj/functions.o obj/files_class.o
	g++ -std=c++17 -o bin/main obj/main.o obj/functions.o obj/files_class.o
	

obj/main.o: src/main.cpp include/functions.h
	g++ -std=c++17 -c src/main.cpp -o obj/main.o
	clear

obj/functions.o : src/functions.cpp include/functions.h include/files_class.h
	g++ -std=c++17 -c src/functions.cpp -o obj/functions.o
	clear

obj/files_class.o : src/files_class.cpp include/files_class.h
	g++ -std=c++17 -c src/files_class.cpp -o obj/files_class.o
	clear
clean:
	rm -f bin/main obj/*o
	clear
	
exec: compile
	@bin/./main
