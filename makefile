CC = g++
CFLAG = -Wall
ADDLIB = -lncurses

main: main.o SelectPlayerMenu.o
	$(CC) -o main obj/main.o obj/SelectPlayerMenu.o $(CFLAG) $(ADDLIB)

main.o: main.cpp include/SelectPlayerMenu.hpp
	$(CC) -c -I ./include main.cpp -o obj/main.o $(CFLAG) $(ADDLIB)

SelectPlayerMenu.o: src/SelectPlayerMenu.cpp include/SelectPlayerMenu.hpp
	$(CC) -c -I ./include src/SelectPlayerMenu.cpp -o obj/SelectPlayerMenu.o $(CFLAG) $(ADDLIB)

clean:
	rm -f \
		obj/* \
		main