#ifndef SONG_NODE_H
#define SONG_NODE_H

typedef struct song_node {
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;

song_node *insert_front(song_node *ptr, char name[], char artist[]);
song_node *insert_order(song_node *ptr, char name[], char artist[]);
song_node *song_search(song_node *ptr, char name[]);
song_node *song_search_by_artist(song_node *ptr, char artist[]);
int size(song_node *list); 
song_node *random_song(song_node *ptr);
song_node *remove_song(song_node *ptr, char name[]);
void print_song(song_node *ptr);
void print_list(song_node *ptr);
song_node *free_list(song_node *ptr);

#endif
