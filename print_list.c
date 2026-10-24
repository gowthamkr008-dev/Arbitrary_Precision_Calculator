#include "apc.h"
#include "apc.h"

void print_list(node * head)
{
  if(head == NULL){
    printf("List empty\n");
    return ;
  }
  
  while (head != NULL)
  {
    printf("%d",(head)->data);
    head = head->next;
  }
  printf("\n");
}