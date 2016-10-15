all: song_node.o playlist.o
	gcc song_node.o playlist.o -o album
run: all
	./album
song_node.o: song_node.c song_node.h
	gcc -c song_node.c
playlist.o: playlist.c playlist.h
	gcc -c playlist.c
clean:
	rm *~
	rm *.o
 