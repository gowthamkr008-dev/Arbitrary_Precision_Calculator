#include "apc.h"

int delete_list(node **head,node **tail){
  if( *head == NULL){
    return SUCCESS;
  }
  while(*head != NULL)
  {
    node *temp = *head;
    (*head) = (*head)->next;
    free(temp);
  }

  *head = NULL;
  *tail = NULL;
  return SUCCESS;
}