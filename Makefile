CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

SRC_DIR = src
OUTPUT_DIR = output

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OUTPUT_DIR)/%.o,$(SRCS))
TARGET = $(OUTPUT_DIR)/main

all: $(TARGET)

$(OUTPUT_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $^ -o $@ -lncurses

clean:
	rm -rf $(OUTPUT_DIR)

.PHONY: all clean
