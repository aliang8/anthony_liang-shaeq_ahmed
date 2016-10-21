GCC = gcc -g

all: song_node.o playlist.o main.o
	$(GCC) playlist.o song_node.o main.o -o albumtest

song_node.o: song_node.c song_node.h
	$(GCC) -c song_node.c

playlist.o: playlist.c playlist.h
	$(GCC) -c playlist.c

tunez.o: song_node.h playlist.h
	$(GCC) -c main.c

run: all
	./albumtest

clean:
	rm *~
	rm *.o
