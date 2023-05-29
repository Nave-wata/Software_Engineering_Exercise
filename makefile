CC = g++
CFLAG = -Wall
ADDLIB = -lncurses

main: main.o SelectPlayerForm.o BaseBox.o
	$(CC) -o main obj/main.o obj/SelectPlayerForm.o obj/BaseBox.o $(CFLAG) $(ADDLIB)

main.o: main.cpp include/views/SelectPlayerForm.hpp
	$(CC) -c -I ./include main.cpp -o obj/main.o $(CFLAG) $(ADDLIB)

SelectPlayerForm.o: src/views/SelectPlayerForm.cpp include/views/SelectPlayerForm.hpp
	$(CC) -c -I ./include src/views/SelectPlayerForm.cpp -o obj/SelectPlayerForm.o $(CFLAG) $(ADDLIB)

BaseBox.o: src/views/BaseBox.cpp include/views/BaseBox.hpp
	$(CC) -c -I ./include src/views/BaseBox.cpp -o obj/BaseBox.o $(CFLAG) $(ADDLIB)

clean:
	rm -f ./obj/*