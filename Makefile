CXX ?= g++
CXXFLAGS = -g -Wall
RM := rm -rf

# path #
SRC_PATH = src
INCLUDE_PATH = include
BUILD_PATH = obj
BIN_PATH = bin

# sources #
SRC := $(wildcard src/*.cpp)
OBJ := $(subst src, obj, $(SRC:.cpp=.o))



all : $(BIN_PATH)/alarmSystem


$(BIN_PATH)/alarmSystem: $(OBJ)
	$(CXX) $(CXXFLAGS) $(INC) -o $@ $^ 
	
obj/%.o : src/%.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<


.PHONY: clean 
clean: 
	del /s *.o
	del /s *.exe