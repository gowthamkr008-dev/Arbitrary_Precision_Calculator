#include "apc.h"

int list_len(node *head){
  int len = 0;
  
  while(head != NULL)
  {
    head = head->next;
    len++;
  }
  
  return len;
}