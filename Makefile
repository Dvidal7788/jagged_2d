PROGRAM  = jagged_2d
CC = gcc
BIN = bin

SRC = src
OBJ = obj

CFILES = $(wildcard $(SRC)/*.c)
OBJS = $(patsubst $(SRC)/%.c,$(OBJ)/%.o,$(CFILES))

all:$(BIN)

$(OBJ)/%.o:$(SRC)/%.c
	$(CC) -c $< -o $@

$(BIN):$(OBJS)
	$(CC) -o $@ $^

run:
	./$(BIN)

clean:
	rm -f $(BIN)
	rm -f *.o $(OBJ)/*.o