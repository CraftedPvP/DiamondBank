# SETTINGS

# Executable name
PROGRAM_NAME := DiamondBank

# Folder paths
BUILD_DIR = build/
OBJ_DIR = obj/
SRC_DIR = src/

DATABASE_PATH = database.txt

# This is the executable file path and file name
OUTPUT := $(BUILD_DIR)$(PROGRAM_NAME)

# Compiler
CXX := g++
# Compiler options
CXXFLAGS := -std=c++17
# Custom defines
CUSTOM_DEFINES := -DDEVHELP

# recursively search for source root folder and all sub-folders inside it.
# note: it doesn't include nested folders within the sub-folders
SOURCES = $(wildcard $(SRC_DIR)*.cpp) $(wildcard $(SRC_DIR)*/*.cpp)
# recursively create a list of all objects in the object folder while keeping the folder structure.
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
	@echo "** Compiling $@ **"
	@$(CXX) $(OBJECTS) -o $@
	@echo "** Compiled $@ successfully **"

# these just makes the objects
$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
# recursively create a directory for the object since they need to have their sub-folders
	@mkdir -p $(dir $@)
# compile the object
	@$(CXX) $(CXXFLAGS) $(CUSTOM_DEFINES) -c $< -o $@

run:
# runs the executable with some notes I've added along the way
	@$(OUTPUT)
clean:
	@echo "** Cleaning project **"
# delete directory recursively and ignore non-existent file/folder if they don't exist
	@rm -rf $(OBJ_DIR)
# delete one file and ignore non-existent file if they don't exist
	@rm -f $(OUTPUT)
	@rm -f $(DATABASE_PATH)
	@rm -f $(DATABASE_PATH)copy
	@echo "** Cleaning completed **"