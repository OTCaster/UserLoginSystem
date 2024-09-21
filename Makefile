CC = gcc
CFLAGS = -Wall -Iinclude
SRC = src/main.c src/user.c src/auth.c src/utils.c
OBJ = $(SRC:.c=.o)
EXEC = build/user_login_system

all: $(EXEC)

$(EXEC): $(OBJ)
	mkdir -p build
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o
	rm -f $(EXEC)
