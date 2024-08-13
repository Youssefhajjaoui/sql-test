# Compiler to use
CC = gcc

# Compiler flags
CFLAGS = -Wall -g

# Libraries to link against
LIBS = -lsqlite3

# Output executable name
TARGET = TESTSQLITE

# Source files
SRCS = main.c database.c

# Object files
OBJS = $(SRCS:.c=.o)

# Default target
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

# Rule to build object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

# Run the project
run: $(TARGET)
	./$(TARGET)
