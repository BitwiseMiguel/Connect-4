# Makefile

# Project name
PROJ_NAME = CONNECT4
PROJ_NAME_TEST = connect4_test.exe

# Compiler
CXX = g++

# Compilation flags
CXXFLAGS = -std=c++17 -o3
DEBUGFLAGS = -Wall -DDEBUG -g

# .cpp files
CPP_SOURCE=$(wildcard ./src/*.cpp) $(wildcard ./external/RNG/*.cpp)
CPP_TESTS=$(wildcard ./tests/*.cpp) runTests.cpp
 
# Object files
OBJ_SOURSCE=$(CPP_SOURCE:.cpp=.o)
OBJ_TESTS=$(CPP_TESTS:.cpp=.o)

# External Libs
EXT_LIBS=$(wildcard ./external/libs/*.a)


# Rule to build everything
all: $(PROJ_NAME)
all: clean

# Rule to build with debug information
debug: CXXFLAGS += $(DEBUGFLAGS)
debug: all

# Rule to build the test
tests: CXXFLAGS += $(DEBUGFLAGS)
tests: $(PROJ_NAME_TEST)
tests: cleanall

# Rule to build the main project
$(PROJ_NAME): $(OBJ_SOURSCE)
	@$(CXX) $(CXXFLAGS) -o $(PROJ_NAME) $(OBJ_SOURSCE) $(EXT_LIBS) main.cpp
	@./$(PROJ_NAME)

$(PROJ_NAME_TEST): $(OBJ_SOURSCE) $(OBJ_TESTS)
	@$(CXX) $(CXXFLAGS) -o $(PROJ_NAME_TEST) $(OBJ_SOURSCE) $(OBJ_TESTS) $(EXT_LIBS)
	@./$(PROJ_NAME_TEST)

# Rule to clean object files
clean:
	@rm -rf ./*.o
	@rm -rf ./src/*.o
	@rm -rf ./tests/*.o

# Rule to clean all generated files
cleanall: clean
	@rm -rf *.exe

# Rule to display available options
help:
	@echo "Available options:"
	@echo "  make all      - Compile and execute the main program (clean afterwards)"
	@echo "  make debug    - Compile and execute the main program with debug information"
	@echo "  make tests    - Compile and execute the test program (clean afterwards)"
	@echo "  make clean    - Clean object files"
	@echo "  make cleanall - Clean all generated files"
