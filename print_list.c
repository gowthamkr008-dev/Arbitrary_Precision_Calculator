#include "apc.h"

void print_list(node *head){
  if(head == NULL){
    return;
  }
  while(head){
    printf("%d",(head)->data);
    head = (head)->next;
  }
  return;
}