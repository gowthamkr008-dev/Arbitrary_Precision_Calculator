#include "apc.h"

int remove_pre_zeros(node **head){
  if( (*head) == NULL){
    return FAILURE;
  }
  node *temp = *head;
  while (*head != NULL && (*head)->data == 0) {
        node *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
  printf("\n");
  return SUCCESS;

}



  // if(*head == *tail){
  //   dlist *temp = *head;
  //   *head = NULL;
  //   *tail = NULL;
  //   free(temp);
  //   return 1;
  // }
  // dlist *temp = *head;
  // *head = (*head)->next;
  // // (*head)->prev = NULL;
  // free(temp);
