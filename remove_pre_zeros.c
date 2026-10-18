#include "apc.h"

int remove_pre_zeros(node **head,node **tail){
    // puts("enter");

  if(*head == NULL){

        return 0;  // fail — empty list
    }

    // Check if any leading zeros exist
    if((*head)->data != 0){
         return 0;  // fail — no leading zeros found
    }

    // Remove leading zeros
    while(*head != NULL && (*head)->data == 0){
        node* temp = *head;
        *head = (*head)->next;
        if(*head != NULL){
            (*head)->prev = NULL;
        }
        free(temp);
    }

    return SUCCESS; 
}