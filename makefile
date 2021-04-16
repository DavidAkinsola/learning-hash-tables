CC = g++
CFLAGS = -g -w -Wall

book.o: Book.h Book.cpp
	$(CC) $(CFLAGS) -c Book.cpp

hash.o: hash.cpp
	$(CC) $(CFLAGS) -c hash.cpp

test: test.o
	$(CC) $(CFLAGS) -o test test.o

clean:
	rm -f core *.o test
