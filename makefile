BUILD_DIR = build
OUTPUT = $(BUILD_DIR)/main.exe
CXX = g++
OBJECT_DIR = obj
SRC_DIR = src
objects = main.o \
			Menu.o
			# Bank.o

all: main

main: $(objects)
	@echo "Compiling main"
	@$(CXX) $(objects) -o $(OUTPUT)


main.o: Menu.o
	@$(CXX) -c $(SRC_DIR)/main.cpp

Bank.o: $(SRC_DIR)/Bank/*.h
	@$(CXX) -c $(SRC_DIR)/Bank/Bank.cpp 

Menu.o: $(SRC_DIR)/UI/Menu.h
	@$(CXX) -c $(SRC_DIR)/UI/Menu.cpp 
run:
	@$(OUTPUT)
clean:
	@echo "Cleaning project"
	@rm *.o
	@rm $(OBJECT_DIR)\*.o $(OUTPUT)