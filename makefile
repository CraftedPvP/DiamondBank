# SETTINGS
BUILD_DIR = build
OBJ_DIR = obj
SRC_DIR = src

OUTPUT = $(BUILD_DIR)/main.exe
CXX = g++

SOURCES = $(wildcard $(SRC_DIR)/*.cpp) \
		$(wildcard $(SRC_DIR)/Bank/*.cpp) \
		$(wildcard $(SRC_DIR)/DiamondBank/*.cpp) \
		$(wildcard $(SRC_DIR)/UI/*.cpp)
OBJECTS = $(pathsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES)) \
		$(pathsubst $(SRC_DIR)/Bank/%.cpp, $(OBJ_DIR)/DiamondBank/%.o, $(SOURCES)) \
		$(pathsubst $(SRC_DIR)/DiamondBank/%.cpp, $(OBJ_DIR)/DiamondBank/%.o, $(SOURCES)) \
		$(pathsubst $(SRC_DIR)/UI/%.cpp, $(OBJ_DIR)/UI/%.o, $(SOURCES))

# INSTRUCTIONS
all: main

# this makes the executable
main: $(OBJECTS)
	@mkdir -p $(BUILD_DIR)
	@echo "Compiling main"
	@$(CXX) $(OBJECTS) -o $(OUTPUT)

# these just makes the objects
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CXX) -c $< -o $@
$(OBJ_DIR)/DiamondBank/%.o: $(SRC_DIR)/DiamondBank/%.cpp
	@mkdir -p $(OBJ_DIR)/DiamondBank
	@$(CXX) -c $< -o $@
$(OBJ_DIR)/Bank/%.o: $(SRC_DIR)/Bank/%.cpp
	@mkdir -p $(OBJ_DIR)/Bank
	@$(CXX) -c $< -o $@
$(OBJ_DIR)/UI/%.o: $(SRC_DIR)/UI/%.cpp
	@mkdir -p $(OBJ_DIR)/UI
	@$(CXX) -c $< -o $@

run:
	@$(OUTPUT)
clean:
	@echo "Cleaning project"
	@rm *.o
	@rm $(OBJ_DIR)\*.o $(OUTPUT)