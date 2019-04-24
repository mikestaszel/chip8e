CC=cc
CFLAGS=-I.
CFLAGS=-Wall -I/usr/local/include
LDFLAGS=-lm -lSDL2 -lSDL2_ttf -L/usr/local/lib

all:
	$(CC) -o chipee emulator.c chipee.c $(CFLAGS) $(LDFLAGS)

test:
	$(CC) -o chipee_tests chipee_tests.c chipee.c $(CFLAGS) $(LDFLAGS)
	./chipee_tests

clean:
	rm -f chipee chipee_tests
