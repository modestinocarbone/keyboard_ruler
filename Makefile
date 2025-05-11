# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -O2
LDFLAGS = -lm

# File names
SRC = key_rul.c
BIN = key_rul

# Install path (can be overridden with: make install PREFIX=/your/path)
PREFIX ?= $(HOME)/.local
BINDIR = $(PREFIX)/bin

# Default rule
all: $(BIN)

# Build binary
$(BIN): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(BIN) $(LDFLAGS)

# Run the binary
run: $(BIN)
	./$(BIN)

# Install to system or user-local path
install: $(BIN)
	mkdir -p $(BINDIR)
	cp $(BIN) $(BINDIR)
	@echo "Installed to $(BINDIR)"
	@echo "Make sure $(BINDIR) is in your PATH"

# Remove build artifacts
clean:
	rm -f $(BIN)
