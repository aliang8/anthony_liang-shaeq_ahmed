int main(){
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
}
