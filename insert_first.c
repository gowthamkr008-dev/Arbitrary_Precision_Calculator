#include "apc.h"

int insert_first(node ** head,node **tail,int data)
{
  node * new = malloc(sizeof(node ));
  if(new == NULL)
  {
    return FAILURE;
  }
  new->data = data;
  new->prev = NULL;
  new->next = *head;
  
  if( *head == NULL)
  {
    *head = new;
    *tail = new;
    return SUCCESS;
  }
  
  (*head)->prev = new;
  *head= new;
  return SUCCESS;
}
