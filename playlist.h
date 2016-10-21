#ifndef PLAYLIST_H
#define PLAYLIST_H
#include "song_node.h"

void addsong(const char name[256], const char artist[256]);
song_node *search(const char name[256], const char artist[256]);
song_node *search_for_artist(const char artist[256]);
void print_entries(char letter);
void print_by_artist(const char artist[256]);
void print_album();
int album_size();
void shuffle(int i);
void delete_song(const char name[256]);
void delete_playlist();
#endif
