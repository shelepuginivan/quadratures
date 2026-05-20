CC = gcc
CFLAGS = -Wall -Wextra -std=gnu11 -fno-fast-math -I./src
LDFLAGS = -lm

SRC_DIR = src
BUILD_DIR = build

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))
TARGET = build/quadratures

.PHONY: all clean generate

all: generate $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

generate:
	uv run generate.py

clean:
	rm -rf $(BUILD_DIR)/*.o $(TARGET)
