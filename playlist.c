#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include "playlist.h"
#include "song_node.h"

song_node *table[26];
void addsong(const char name[256], const char artist[256]){
  char letter = tolower(artist[0]);
  song_node *curr = table[letter-97];
  if (size(curr) == 0){ // to avoid having dummy node at head
    strcpy(curr->name,lower(name));
    strcpy(curr->artist,lower(artist));
  } else {
    table[letter-97] = insert_order(curr,name,artist);
  }
}

song_node *search(const char name[256], const char artist[256]){
  char letter = tolower(artist[0]);
  song_node *curr = table[letter-97];
  song_search(curr,name);   
}

song_node *search_for_artist(const char artist[256]){
  char letter = tolower(artist[0]);
  song_search_by_artist(table[letter-97],artist);
}

void print_entries(char letter){
  song_node *curr = table[letter-97];
  print_list(curr);
}

void print_by_artist(const char artist[256]){
  char letter = tolower(artist[0]);
  song_node *curr = song_search_by_artist(table[letter-97],artist);
  while(curr){
    if(strcmp(curr->artist,lower(artist)) == 0)
      print_song(curr);
    curr = curr->next;
  }
}

void print_album(){
  int i;
  for(i = 0; i < 26; i++){
    if(size(table[i]) == 0){
    } else {
      print_entries(i+'a');
    }
  }
}

int album_size(){
  int i;
  int ans = 0;
  for (i=0;i<26;i++){
    ans += size(table[i]);
  }
  return ans;
}

void shuffle(int i) {
  srand(time(NULL));
  while (i) {
    int r = rand() % 26;
    while (!size(table[r])){
      r = rand() % 26;
    }
    print_song(random_song(table[r]));
    i--;
  }
}

void delete_song(const char name[256]){
  int i = 0;
  for (i ; i < 26; i++){
    remove_song(table[i],name);
  }
}

void delete_playlist(){
  int i = 0;
  for(;i<26;i++){
    table[i] = free_list(table[i]);
  }
}