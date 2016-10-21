#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "song_node.h"

song_node *errors(){
  song_node* error = (song_node *)malloc(sizeof(song_node));
  strcpy(error->name, "Error");
  strcpy(error->artist, "Not Found");
  return error;
}

char *lower(const char str[256]){
  char *dest = (char *)malloc(strlen(str) + 1);
  int i = 0;
  while (str[i]){
    dest[i] =tolower(str[i]);
    i++;
  }
  return dest;
}


song_node *insert_front(song_node *ptr, const char name[256], const char artist[256]){
  //parent node
  song_node *parent = (song_node *)malloc(sizeof(song_node));
  strcpy(parent->name, lower(name));
  strcpy(parent->artist, lower(artist));
  parent->next = ptr;
  return parent;
}

song_node *insert_order(song_node *ptr, const char name[256], const char artist[256]){
  song_node *song = (song_node *)malloc(sizeof(song_node));
  strcpy(song->name, lower(name));
  strcpy(song->artist, lower(artist));
  if ( strcmp(song->artist,ptr->artist)<0 || (strcmp(song->artist,ptr->artist)==0 && (strcmp(song->name,ptr->name)<0)))  return insert_front(ptr,lower(name),lower(artist));
  song_node* curr = ptr;
  while(curr->next){

    if (strcmp(song->artist,curr->next->artist)==0){
      if (strcmp(song->name,curr->next->name)<0) {
          
	song->next = curr->next;
	curr->next = song;
	return ptr;  
      }
    }
    else if ( strcmp(song->artist,curr->next->artist)<0  ){
      
      song->next = curr->next;
      curr->next = song;
      return ptr;
    }
    curr = curr->next;
  }
  curr->next = song; //song goes at end
  return ptr;
}

song_node* song_search(song_node* ptr, const char name[256]){
  song_node* curr = ptr;
  while (curr){
    if(strcmp(curr->name,lower(name)) == 0) 
      return curr;
    curr = curr->next;
  }
  song_node* error = (song_node *)malloc(sizeof(song_node));
  return (errors());
}


song_node* song_search_by_artist(song_node* ptr, const char artist[256]){
  song_node* curr = ptr;
  while (curr){
    if(strcmp(curr->artist,lower(artist)) == 0)
      return curr;
    curr = curr->next;
  }
  return errors();
}

int size(song_node *ptr){
  song_node* curr = ptr;
  int i = 0;
  while(curr->next){  
    i++;
    curr = curr->next;
  } 
  if (strcmp(curr->name,"")!=0) i++;
  return i;
}

song_node *random_song(song_node *ptr){
  int r = rand() % size(ptr);
  while(r){
    ptr = ptr->next;
    r--;
  }
  return ptr;
}

song_node *remove_song(song_node *ptr, const char name[256]){
  song_node* song = song_search(ptr,name);
  song_node* curr = ptr;
  while (curr->next){
    if (strcmp(curr->next->name,lower(name)) == 0){
      curr->next = song->next;
      free(song);
      return ptr;
    }
    curr = curr->next;
  }
  return errors();
}

void print_list(song_node *ptr){
  if(size(ptr) == 0){
    printf("Oops, this list is empty.\n");
  } else {
    printf("-> ");
    while(ptr->next){
      printf("%s - %s\n",ptr->artist,ptr->name);
      printf("-> ");
      ptr = ptr->next;
    }
    printf("%s - %s\n",ptr->artist, ptr->name);
  }
}

void print_song(song_node *ptr){
  printf(" -> ");
  printf("%s - %s\n",ptr->artist,ptr->name);
}

song_node *free_list(song_node *ptr){
  song_node *curr = ptr;
  while (ptr!=NULL) {
    ptr = ptr->next;
    printf("Freeing node: %p\n", curr);
    free(curr);
    curr = ptr;    
  }
  return ptr;
}
