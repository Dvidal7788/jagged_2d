CC = gcc
BIN = bin

CFILES = main.c

all:
	$(CC) -o $(BIN) $(CFILES)

run:
	./$(BIN)

clean:
	rm -f $(BIN)
	rm -f *.o