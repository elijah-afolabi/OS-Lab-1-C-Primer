// list/list.c
// 
// Implementation for linked list.
//
// Elijah Afolabi

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "list.h"

list_t *list_alloc() { 
  list_t *l = (list_t *)malloc(sizeof(list_t));
  l->length = 0;
  return l;
}

void list_free(list_t *l) {
  node_t *currentNode = l->head;
  // Free all nodes.
  while(currentNode != NULL){
    node_t *node = currentNode;
    currentNode = currentNode->next;
    free(node);
  }
  // Free the list itself.
  free(l);
}

void list_print(list_t *l) {
  node_t *currentNode = l->head;
  
  printf("[");
  // Print all the nodes within the list.
  while(currentNode != NULL){
    // Don't use a comman for the last element in the list.
    if(currentNode->next != NULL){
      printf("%d,", currentNode->value);
    }else{
      printf("%d", currentNode->value);
    }
    currentNode = currentNode->next;
  }
  printf("]\n");
}

int list_length(list_t *l) {
  return l->length;
}

void list_add_to_back(list_t *l, elem value) {
  node_t *tail = l->head;
  
  // List is empty, just add it to the front.
  if(tail == NULL){
    list_add_to_front(l, value);
    return;
  }
  
  // Get to the end of the list.
  while(tail->next != NULL){
    tail = tail->next;
  }
  // Create a new node and make it the tail.
  node_t *newTail = (node_t *)malloc(sizeof(node_t));
  newTail->value = value;
  tail->next = newTail;
  l->length++;
}

void list_add_to_front(list_t *l, elem value) {
  node_t *headBackup = l->head;
  // Create a new head.
  l->head = (node_t *)malloc(sizeof(node_t));
  l->head->value = value;
  l->head->next = headBackup;
  l->length++;
}

void list_add_at_index(list_t *l, elem value, int index) {
  // Index out of range, add to back/front.
  if(index >= l->length){
    list_add_to_back(l, value);
    return;
  } else if(index <= 0){
    list_add_to_front(l, value);
    return;
  }
  
  // Get to the node at the index we want the new node at.
  int currentIndex = 0;
  node_t *currentNode = l->head;
  while(currentIndex != index){
    currentIndex++;
    currentNode = currentNode->next;
  }
  
  // Transfer the current node's data to a new node.
  node_t *newNode = (node_t *)malloc(sizeof(node_t));
  newNode->value = currentNode->value;
  newNode->next = currentNode->next;
  
  // Change the current node's data to the wanted data at this position.
  currentNode->value = value;
  currentNode->next = newNode;
  
  l->length++;
}

elem list_remove_from_back(list_t *l) {
  if(l == NULL || l->head == NULL){
    return INT_MAX;
  }
  // List only has 1 element, just remove the head.
  if(l->head->next == NULL){
    return list_remove_from_front(l);
  }
  // Get the second to last node.
  node_t *sLastNode = l->head;
  while(sLastNode->next->next != NULL){
    sLastNode = sLastNode->next;
  }
  // Remove the last node.
  elem tempLastNode = sLastNode->next->value;
  free(sLastNode->next);
  sLastNode->next = NULL;
  l->length--;
  return tempLastNode;
}

elem list_remove_from_front(list_t *l) {
  if(l == NULL || l->head == NULL){
    return INT_MAX;
  }
  node_t *tempNode = l->head;
  int tempValue = tempNode->value;
  l->head = l->head->next;
  free(tempNode);
  l->length--;
  return tempValue;
}

elem list_remove_at_index(list_t *l, int index) { 
  if(l == NULL || l->head == NULL
    || index < 0 || index >= l->length){
    return INT_MAX;
  }
  // Remove from the front.
  if(index == 0){
    return list_remove_from_front(l);
  }
  // Remove from the back.
  if(index == l->length-1){
    return list_remove_from_back(l);
  }
  // Get the node before the given index.
  int currentIndex = 0;
  node_t *currentNode = l->head;
  while(currentNode != NULL){
    if(currentIndex == index-1){
      break;
    }
    currentIndex++;
    currentNode = currentNode->next;
  }
  // Remove the index node, which is the next one.
  node_t *tempNode = currentNode->next;
  int tempValue = tempNode->value;
  currentNode->next = currentNode->next->next;
  free(tempNode);
  l->length--;
  return tempValue;
}

bool list_is_in(list_t *l, elem value) {
  if(list_get_index_of(l, value) != -1){
    return true;
  }
  return false;
}

elem list_get_elem_at(list_t *l, int index) {
  if(l == NULL || l->head == NULL
    || index < 0 || index >= l->length){
    return INT_MAX;
  }
  // Get the node at the given index.
  int currentIndex = 0;
  node_t *currentNode = l->head;
  while(currentNode != NULL){
    if(currentIndex == index){
      break;
    }
    currentIndex++;
    currentNode = currentNode->next;
  }
  // Found the element at the given index.
  if(currentIndex == index && currentNode != NULL){
    return currentNode->value;
  }
  return INT_MAX;
}

int list_get_index_of(list_t *l, elem value) {
  if(l == NULL || l->head == NULL){
    return -1;
  }
  // Try and find a node with the given value.
  int foundIndex = -1;
  int currentIndex = 0;
  node_t *currentNode = l->head;
  while(currentNode != NULL){
    if(currentNode->value == value){
      foundIndex = currentIndex;
      break;
    }
    currentIndex++;
    currentNode = currentNode->next;
  }
  return foundIndex;
}