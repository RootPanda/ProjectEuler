CC=g++
CFLAGS=-g -ggdb -I.
LDFLAGS=-g
DEPS = TreeNode.h
OBJ = main.o TreeNode.o

%.o: %.c $(DEPS)
	%(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	g++ -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o 
	rm main
