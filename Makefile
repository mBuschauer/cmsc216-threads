CC = gcc
CFLAGS = -ansi -Wall -g -O0 -Wwrite-strings -Wshadow \
	-pedantic-errors -fstack-protector-all -Wextra

TARGET = threads
SRCS = main.c max.c sum.c
OBJS = main.o max.o sum.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

max.o: max.c
	$(CC) $(CFLAGS) -c max.c

sum.o: sum.c
	$(CC) $(CFLAGS) -c sum.c

clean:
	rm -f $(TARGET) $(OBJS)
