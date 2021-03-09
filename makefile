CC = /usr/bin/gcc

delln: filelib.o main.o
	$(CC) filelib.o main.o -o delln

filelib.o: Tokens/filelib.c
	$(CC) -c Tokens/filelib.c -o filelib.o

main.o: main.c
	$(CC) -c main.c -o main.o

clean:
	rm *.o

install:
	sudo install delln /usr/bin
	rm delln

# Run as root
uninstall:
	rm /usr/bin/delln