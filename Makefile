CC = gcc
CFLAGS = -Wall -Wextra -O2
DEPS = fib.h
OBJ = fib.o test_fib.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	./test

clean:
	rm -f *.o test
