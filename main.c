#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "song_node.h"
#include "playlist.h"

int main(){ 
  //new table of linked list  
  song_node *table[26];
  printf("Starting a new album...\n");
  int i;
  for(i=0;i<26;i++){
    table[i]=(song_node *)malloc(sizeof(song_node));
  }
  printf("Adding some tracks...:\n");;
  addsong("Like a Rolling Stone","Bob Dylan");
  addsong("Satisfaction","Rolling Stones");
  addsong("Imagine","John Lennon");
  addsong("What's Going On","Marvin Gaye");
  addsong("Respect","Aretha Franklin");
  addsong("Good Vibrations","Beach Boys");
  addsong("Johnny B. Goode","Chuck Berry");
  addsong("Hey Jude","Beatles");
  addsong("All Star","Smash Mouth");
  addsong("Smells Like Teen Spirit","Nirvana");
  addsong("What'd I Say", "Ray Charles");
  addsong("My Generation","Who");
  addsong("A Change Is Gonna Come","Same Cooke");
  addsong("Yesterday","Beatles");
  addsong("London Calling","The Clash");
  addsong("I Want To Hold Your Hand","Beatles");
  addsong("Purple Haze","Jimmy Hendrix");
  addsong("Hound Dog","Elvis Presley");
  addsong("In My Life","Beatles");
  addsong("Here Come Dat Boi","A e s t h e t i c");
  addsong("People Got Ready","Depression");
  addsong("God Only Knows","Beach Boys");
  addsong("Bo Diddley","Bo Diddley");
  addsong("California Girls","Beach Boys");
  addsong("Superstition","Stevie Wonder");
  print_album();
  printf("-------------------------------\n");
  
    
    
  printf("%i\n", album_size());
  //song search function
  printf("Searching for a song...:\n");
  print_song(search("California Girls","Beach Boys"));
  printf("-------------------------------\n");
  
  //search by artist function
  printf("Searching for artist...:\n");
  print_song(search_for_artist("Beatles"));
  printf("-------------------------------\n");
  
  //print entries under certain letter
  char letter = 'b';
  printf("Printing all entries under %c...:\n",letter);
  print_entries(letter);
  printf("-------------------------------\n");
  
  //print all songs by artist
  const char artist[256] = "Beatles";
  printf("Printing all songs by %s...:\n",artist);
  print_by_artist(artist);
  printf("-------------------------------\n");
  
  //shuffle function
  printf("Testing shuffle...:\n");
  shuffle(10);
  printf("-------------------------------\n");
  
  //testing delete song function
  printf("Testing delete song...: In My Life\n\n");
  delete_song("In My Life");
  printf("Album with song delted:\n");
  print_album();
  printf("-------------------------------\n");
  
  //testing free nodes function
  printf("Freeing nodes...:\n");
  //delete_playlist();
  //print_album();
  printf("-------------------------------\n");
  
  //Song_node structure
  //////////////////////////////////////////////////////////////  
  srand(time(NULL));
  //new linked list
  song_node * song_list = (song_node *)malloc(sizeof(song_node));
  //initialize album
  strcpy(song_list->name, "coderpad");
  strcpy(song_list->artist, "zcoderman");
  
  //testing insert_order function
  song_list = insert_order(song_list, "youngmoney","Shaeq");
  song_list = insert_order(song_list, "blues", "anthony");
  song_list = insert_order(song_list, "chill", "shadman");
  song_list = insert_order(song_list, "cat", "mouse");
  printf("Original Album:\n");
  print_list(song_list);
  printf("-------------------------------\n");
  
  //testing size function
  printf("Size of Album:\n");
  printf("%i\n",size(song_list));
  printf("-------------------------------\n");
  //testing random song function
  printf("Pointer to a random song:\n");
  print_song(random_song(song_list));
  printf("-------------------------------\n");
  printf("Another pointer to a random song:\n");
  print_song(random_song(song_list));
  printf("-------------------------------\n");
    
  //testing song search function
  printf("Searching for a song...:\n");
  print_song(song_search(song_list,"youngmoney"));
  printf("-------------------------------\n");
  printf("Searching for another...:\n");
  print_song(song_search(song_list,"chill"));
  printf("-------------------------------\n");
  
  //testing song search by artist function
  printf("Searching for first song by artist...:\n");
  print_song(song_search_by_artist(song_list,"anthony"));
  printf("-------------------------------\n");
  printf("Searching for another song by artist...:\n");
  print_song(song_search_by_artist(song_list,"shaeq"));
  printf("-------------------------------\n");
  
  //testing remove song function
  printf("Removing a song...:\n");
  print_list(remove_song(song_list,"shadman"));
  printf("-------------------------------\n");
  printf("Removing another song...:\n");
  print_list(remove_song(song_list,"chill"));
  printf("-------------------------------\n");
  
  //testing free list function
  printf("Freeing album...:\n");
  song_list = free_list(song_list);
  printf("%s",song_list);

  return 0;
}
