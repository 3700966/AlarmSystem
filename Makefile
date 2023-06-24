CXX ?= g++
CXXFLAGS = -g -Wall

# path #
SRC_PATH = src
INCLUDE_PATH = include
BUILD_PATH = obj
BIN_PATH = bin

# sources #
SRC := $(wildcard src/*.cpp)
OBJ := $(subst src, obj, $(SRC:.cpp=.o))
INC := -I $(INCLUDE_PATH)



all : $(BIN_PATH)/alarmSystem $(BIN_PATH)/tests


$(BIN_PATH)/alarmSystem: obj/Alarm.o obj/AlarmLevel.o obj/main.o 
	$(CXX) $(CXXFLAGS) $(INC) -o $@ $^

$(BIN_PATH)/tests: obj/Alarm.o obj/AlarmLevelTest.o obj/AlarmLevel.o obj/tests.o 
	$(CXX) $(CXXFLAGS) $(INC) -o $@ $^
	
obj/%.o : src/%.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<


.PHONY: clean 
clean: 
	del /s *.o
	del /s *.exe