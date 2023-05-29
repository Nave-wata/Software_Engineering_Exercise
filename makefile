CC = g++
CFLAG = -Wall
ADDLIB = -lncurses

main: main.o SelectPlayerForm.o
	$(CC) -o main obj/main.o obj/SelectPlayerForm.o $(CFLAG) $(ADDLIB)

main.o: main.cpp include/views/SelectPlayerForm.hpp
	$(CC) -c -I ./include main.cpp -o obj/main.o $(CFLAG) $(ADDLIB)

SelectPlayerForm.o: src/views/SelectPlayerForm.cpp include/views/SelectPlayerForm.hpp
	$(CC) -c -I ./include src/views/SelectPlayerForm.cpp -o obj/SelectPlayerForm.o $(CFLAG) $(ADDLIB)

clean:
	rm -f ./obj/*