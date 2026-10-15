#include "apc.h"

int remove_pre_zeros(node **head){
  if( (*head) == NULL){
    return FAILURE;
  }
  while((*head) != NULL ){
    if( (*head)->data == 0){
      node *temp = (*head);
      *head = (*head)->next;
      free(temp);
    }else{
        printf("\n");
      return SUCCESS;
    }
    (*head) = (*head)->next;
  }

}
