CXX := g++
CXXFLAGS := -std=c++17 -Iinclude -I/opt/homebrew/include -I/Users/skyezer/Library/Application\ Support/VulkanSDK/1.3.296.0/macOS/include -Wall -Wextra -Werror -pedantic -O3
LDFLAGS := -L/opt/homebrew/lib -L/Users/skyezer/Library/Application\ Support/VulkanSDK/1.3.296.0/macOS/lib -lvulkan -lglfw

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
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^

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
