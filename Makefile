# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -I./include
AR = ar
ARFLAGS = rcs

# Library name and paths
LIB_NAME = libmylib.a
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build

# Example and test paths
EXAMPLES_DIR = examples
TESTS_DIR = test

# Test targets
TEST_SOURCES = $(wildcard $(TESTS_DIR)/test_*.c)
TEST_TARGETS = $(patsubst $(TESTS_DIR)/%.c,$(BUILD_DIR)/%,$(TEST_SOURCES))

.PHONY: all clean install uninstall test examples

all: $(LIB_NAME)

# Build static library
$(LIB_NAME): $(SRC_DIR)/*.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $^ -o $(BUILD_DIR)/mylib.o
	$(AR) $(ARFLAGS) $(BUILD_DIR)/$(LIB_NAME) $(BUILD_DIR)/mylib.o

# Build examples
examples: $(LIB_NAME)
	@echo "Building examples..."
	$(CC) $(CFLAGS) $(EXAMPLES_DIR)/example.c -L./$(BUILD_DIR) -lmylib -o $(BUILD_DIR)/example

# Build tests
$(BUILD_DIR)/%: $(TESTS_DIR)/%.c $(LIB_NAME)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $< -L./$(BUILD_DIR) -lmylib -o $@

# Run tests
test: $(TEST_TARGETS)
	@echo "Running tests..."
	@for test in $(TEST_TARGETS); do \
		echo "Executing $$(basename $$test)..."; \
		$$test || exit 1; \
	done
	@echo "All tests passed!"

# Install library system-wide
install:
	@mkdir -p /usr/local/include/mylib /usr/local/lib
	cp $(INC_DIR)/*.h /usr/local/include/mylib
	cp $(BUILD_DIR)/$(LIB_NAME) /usr/local/lib

# Uninstall library
uninstall:
	rm -rf /usr/local/include/mylib
	rm -f /usr/local/lib/$(LIB_NAME)

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR)
