#include "apc.h"

int insert_last(node **head, node **tail, int data){
  node *new = malloc(sizeof(node));
  if(new == NULL){
    puts("Allocation failure");
    return FAILURE;
  }
  new->data = data;
  new->next = NULL;
  new->prev = *tail;
  if(*head == NULL){
    *head = new;
    *tail = new;
    return SUCCESS;
  }
  (*tail)->next = new;
  *tail  = new;
  return SUCCESS;
}