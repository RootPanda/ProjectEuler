CC=g++
CFLAGS=-g -ggdb 
DEPS = 
OBJ = main.o


%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o 
	rm main
