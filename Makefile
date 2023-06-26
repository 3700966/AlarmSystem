CXX ?= g++
CXXFLAGS = -g -Wall

# path #
SRC_PATH = src
INCLUDE_PATH = include
BUILD_PATH = obj
BIN_PATH = bin

# sources #
SRC := $(wildcard $(SRC_PATH)/*.cpp)
OBJ := $(subst $(SRC_PATH), $(BUILD_PATH), $(SRC:.cpp=.o))
INC := -I $(INCLUDE_PATH)



all : $(BIN_PATH)/alarmSystem $(BIN_PATH)/tests


$(BIN_PATH)/alarmSystem: $(BUILD_PATH)/Alarm.o $(BUILD_PATH)/AlarmLevel.o $(BUILD_PATH)/main.o 
	$(CXX) $(CXXFLAGS) $(INC) -o $@ $^

$(BIN_PATH)/tests: $(BUILD_PATH)/Alarm.o $(BUILD_PATH)/AlarmLevelTest.o $(BUILD_PATH)/AlarmLevel.o $(BUILD_PATH)/tests.o 
	$(CXX) $(CXXFLAGS) $(INC) -o $@ $^
	
$(BUILD_PATH)/%.o : $(SRC_PATH)/%.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<


.PHONY: clean 
clean: 
	del /s *.o
	del /s *.exe