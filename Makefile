# Compiler and flags
CC = gcc
CFLAGS = -ansi -Wall -g -O0 -Wwrite-strings -Wshadow \
	-pedantic-errors -fstack-protector-all -Wextra

# Target executable
TARGET = threads

# Source files
SRCS = main.c max.c sum.c
OBJS = $(SRCS:.c=.o)

# Default target
all: $(TARGET)

# Link the object files to create the final executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean the build directory
clean:
	rm -f $(OBJS) $(TARGET)
