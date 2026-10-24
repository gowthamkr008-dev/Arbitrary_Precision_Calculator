#include "apc.h"

uint list_length(node *head){
  uint i =0;
  while(head != NULL){
    i++;
    head = head->next;
  }
  return i;
}