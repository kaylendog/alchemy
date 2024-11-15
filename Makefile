CXX := g++
CXXFLAGS := -std=c++17 -Iinclude -Wall -Wextra -Werror -O3

SRC_DIR := src
INC_DIR := include
BUILD_DIR := build

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))
EXEC := $(BUILD_DIR)/alchemy

ALCHEMY_SRC := src/alchemy.cpp
ALCHEMY_OBJ := $(BUILD_DIR)/alchemy.o

all: $(EXEC)

$(EXEC): $(OBJS) $(ALCHEMY_OBJ) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(ALCHEMY_OBJ): $(ALCHEMY_SRC) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR) $(BUILD_DIR)

# Phony targets
.PHONY: all clean
