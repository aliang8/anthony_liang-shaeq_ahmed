#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "song_node.h"

song_node *insert_front(song_node *ptr, char n[], char a[] ) {
  song_node *parent = (song_node *)malloc(sizeof(song_node));
  parent->next = ptr;
  strcpy(parent->name, n);
  strcpy(parent->artist, a);
  return parent;
}

song_node *insert_order(song_node *ptr, char n[], char a[] ) {
  song_node *tmp = ptr;
  if (!tmp) return insert_front(tmp, n, a);
  if(strcmp(a, tmp->artist) < 0) return insert_front(tmp, n, a);
  if(strcmp(a, tmp->artist) == 0 && strcmp(n, tmp->name) < 0 )
    return insert_front(tmp, n, a);
  else
    tmp->next = insert_order(tmp->next, n, a);
  return ptr;
}

void print_list(song_node *ptr) {
  song_node *tmp = ptr;
  while(tmp) {
    printf("\n* %s - %s", tmp->artist, tmp->name);
    tmp = tmp->next;
  }
  printf("\n");
}

song_node *song_search(song_node *ptr, char n[]) {
  song_node *tmp = ptr;
  if(!tmp)
    printf("\nError Not Found\n");
  else if(strcmp(n, tmp->name) == 0)
    return tmp;
  else
    return song_search(tmp->next, n);
  return 0;
}

song_node *song_search_by_artist(song_node* ptr, char a[]){
  song_node *tmp = ptr;
  while (tmp){
    if(strcmp(tmp->artist,a) == 0)
      return tmp;
    tmp = tmp->next;
  }
  return 0;
}

int size(song_node *ptr) {
  int i = 0; 
  while(ptr) {
    ptr = ptr->next;
    i++;
  }
  return i;
}

song_node *random_song(song_node *ptr){
  song_node *tmp = ptr;
  int r = rand() % size(tmp);
  while(r){
    tmp = tmp->next;
    r--;
  }
  return ptr;
}

song_node *remove_song(song_node *ptr, char n[]){
  song_node* song = song_search(ptr,n);
  song_node* tmp = ptr;
  while (tmp->next){
    if (strcmp(tmp->next->name,n) == 0){
      tmp->next = song->next;
      free(song);
      return ptr;
    }
    tmp = tmp->next;
  }
  return 0;
}

song_node *free_list(song_node *ptr){
  song_node *tmp = ptr;
  while (ptr!=NULL) {
    ptr = ptr->next;
    printf("Freeing node: %p\n", tmp);
    free(tmp);
    tmp = ptr;    
  }
  return ptr;
}
