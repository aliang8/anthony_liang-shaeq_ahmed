#ifndef PLAY_LIST_H
#define PLAY_LIST_H
#include "song_node.h"

song_node *table[26];

void add_song(char name[], char artist[]); 
song_node * find_song(char name[]); 
song_node * find_artist(char artist[]); 
void print_artist(song_node *ptr, char artist[] ); 
void print_entries(char letter);
void print_album(); 
void shuffle();
void delete_song(char name[], char artist[]); 
void delete_library(); 

#endif
