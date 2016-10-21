#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "playlist.h"

void add_song(char n[], char a[]) {
  char letter = a[0]-97;
  table[letter] = insert_front(table[letter], n, a);
}

song_node *search(char n[]) {
  int i = 0;
  song_node *tmp = 0;
  while(!tmp && i < 26){
    tmp = song_search(table[i], n);
    i++;
  }
  return tmp;
}

song_node *search_by_artist(char a[]) {
  song_node *tmp = table[a[0]-97];
  tmp = song_search_by_artist(tmp, a);
  return tmp;
}

void print_by_artist(song_node *ptr, char a[]) {
  song_node *tmp = song_search_by_artist(ptr,a);
  while(tmp && strncmp(a, tmp->artist, 1) == 0) {
    if(strcmp(tmp->artist, a) == 0)
      printf("* %s - %s\n", tmp->artist, tmp->name);
    tmp = tmp->next;
  }
}

void print_entries(char letter){
  song_node *tmp = table[letter-97];
  print_list(tmp);
}

void print_album() {
  int i = 0;
  while(i < 26){
    print_list(table[i]);
    i++;
  }
}

void shuffle(int i) {
  srand(time(NULL));
  while (i) {
    int r = rand() % 26;
    while (!(table[r])){
      r = rand() % 26;
    }
    print_song(random_song(table[r]));
    i--;
  }
}

void delete_song(char n[], char a[]) {
  table[a[0]-97] = remove_song(table[a[0]-97], n);
  print_album();
}

void delete_playlist() {
  int i = 0;
  while(i < 26){
    table[i] = free_list(table[i]);
    i++;
  }
}

