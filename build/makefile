OBJECTS = main.o stringUtils.o userInput.o cell.o position.o car.o world.o
CFLAGS = -c -Wall -std=c++14

informedSearch: $(OBJECTS)
	g++  $(OBJECTS) -o informedSearch -g
	mv *.o ../objects
	mv informedSearch ../bin

main.o: ../src/main.cc
	g++ $(CFLAGS) ../src/main.cc

stringUtils.o: ../src/stringUtils.cc ../include/stringUtils.h
	g++ $(CFLAGS) ../src/stringUtils.cc

userInput.o: ../src/userInput.cc ../include/userInput.h
	g++ $(CFLAGS) ../src/userInput.cc

cell.o: ../src/cell.cc ../include/cell.h
	g++ $(CFLAGS) ../src/cell.cc

position.o: ../src/position.cc ../include/position.h
	g++ $(CFLAGS) ../src/position.cc

car.o: ../src/car.cc ../include/car.h
	g++ $(CFLAGS) ../src/car.cc

world.o:  ../src/world.cc ../include/world.h
	g++ $(CFLAGS) ../src/world.cc

.PHONY: clean
clean:
	rm -rf ../objects/*.o
	rm -rf ../bin/*
	clear