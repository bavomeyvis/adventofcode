CC=gcc
CFLAGS=-Wall -g
PROGRAM=d4

all: $(PROGRAM)
$(PROGRAM): $(PROGRAM).o
$(PROGRAM).o: $(PROGRAM).c

clean:
	-rm -f $(PROGRAM) $(PROGRAM).o
run: $(PROGRAM)
	./$(PROGRAM)
