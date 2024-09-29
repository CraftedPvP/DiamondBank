# SETTINGS
BUILD_DIR = build/
OBJ_DIR = obj/
SRC_DIR = src/

OUTPUT = $(BUILD_DIR)main
CXX = g++

SOURCES = $(wildcard $(SRC_DIR)*.cpp) $(wildcard $(SRC_DIR)*/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.o, $(SOURCES))

# INSTRUCTIONS
all: $(OUTPUT)

# this makes the executable
$(OUTPUT): $(OBJECTS)
	@echo "** Gathering Sources ($(SRC_DIR)*.cpp) **"
# @echo $(SOURCES)
# @echo "----"
	
	@echo "** Making Objects ($(OBJ_DIR)*.o) **"
# @echo $(OBJECTS)
# @echo "----"
	
	@mkdir -p $(BUILD_DIR)
	@echo "Compiling main"
	@$(CXX) $(OBJECTS) -o $@

# these just makes the objects
$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(dir $@)
	@$(CXX) -c $< -o $@

run:
	@$(OUTPUT)
clean:
	@echo "** Cleaning project **"
# delete directory recursively and ignore non-existent file/folder if they don't exist
	@rm -rf $(OBJ_DIR)
# delete one file and ignore non-existent file if they don't exist
	@rm -f $(OUTPUT) 