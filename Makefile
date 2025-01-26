CC = gcc
CFLAGS = -Wall -Wextra -I./include
AR = ar
ARFLAGS = rcs

LIB_NAME = libcipher.a
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build
TESTS_DIR = tests

.PHONY: all clean test

all: $(LIB_NAME)

$(LIB_NAME): $(SRC_DIR)/Cipher.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $(BUILD_DIR)/Cipher.o
	$(AR) $(ARFLAGS) $(BUILD_DIR)/$(LIB_NAME) $(BUILD_DIR)/Cipher.o

test: $(LIB_NAME)
	$(CC) $(CFLAGS) $(TESTS_DIR)/test_ciphers.c -L./$(BUILD_DIR) -lcipher -o $(BUILD_DIR)/test
	@./$(BUILD_DIR)/test

clean:
	rm -rf $(BUILD_DIR)
