CC=g++
CFLAGS=-g -ggdb -I.
LDFLAGS=-g
DEPS = 
OBJ = main.o

%.o: %.c $(DEPS)
	%(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	g++ -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o 
	rm main
