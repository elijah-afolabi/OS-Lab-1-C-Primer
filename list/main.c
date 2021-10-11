#include <stdio.h>

#include "list.h"

int main() {
  printf("Tests for linked list implementation\n");
  list_t *mylist = list_alloc();
  list_print(mylist);
  
  list_add_to_front(mylist, 10);
  
  list_add_to_back(mylist, 2);
  
  list_add_at_index(mylist, 70, 1);
  
  list_add_at_index(mylist, 20, 0);
  
  list_add_at_index(mylist, 801, 3); 
  
  list_add_at_index(mylist, 2, 19); 
  
  list_add_to_front(mylist, 99);
  
  list_get_elem_at(mylist, 0);
  
  list_get_elem_at(mylist, 1);
  
  list_get_elem_at(mylist, 3);
  
  list_get_elem_at(mylist, 20);
    
  list_print(mylist);
  
  printf("List Length: %d\n",list_length(mylist));
  
  list_free(mylist);
  
  list_print(mylist);
  
  printf("List Length: %d\n",list_length(mylist));
  
  list_add_to_front(mylist, 5);
  
  list_add_to_front(mylist, 6);
  
  list_add_to_front(mylist, 7);
   
  list_add_to_front(mylist, 8);
  
  list_add_to_front(mylist, 9);
  
  list_add_to_front(mylist, 10);
    
  list_print(mylist);
  
  printf("List Length: %d\n",list_length(mylist));
  
  
  
  return 0;
}
