CC = g++
CFLAG = -Wall
ADDLIB = -lncurses

main: main.o SelectPlayerForm.o CreateOrJoinRoomForm.o BaseBox.o
	$(CC) -o main \
		obj/main.o \
		obj/SelectPlayerForm.o \
		obj/CreateOrJoinRoomForm.o \
		obj/BaseBox.o $(CFLAG) $(ADDLIB)

main.o: main.cpp include/views/SelectPlayerForm.hpp include/views/CreateOrJoinRoomForm.hpp
	$(CC) -c -I ./include main.cpp -o obj/main.o $(CFLAG) $(ADDLIB)

SelectPlayerForm.o: src/views/SelectPlayerForm.cpp include/views/SelectPlayerForm.hpp
	$(CC) -c -I ./include src/views/SelectPlayerForm.cpp -o obj/SelectPlayerForm.o $(CFLAG) $(ADDLIB)

CreateOrJoinRoomForm.o: src/views/CreateOrJoinRoomForm.cpp include/views/CreateOrJoinRoomForm.hpp
	$(CC) -c -I ./include src/views/CreateOrJoinRoomForm.cpp -o obj/CreateOrJoinRoomForm.o $(CFLAG) $(ADDLIB)

BaseBox.o: src/views/BaseBox.cpp include/views/BaseBox.hpp
	$(CC) -c -I ./include src/views/BaseBox.cpp -o obj/BaseBox.o $(CFLAG) $(ADDLIB)

clean:
	rm -f ./obj/*