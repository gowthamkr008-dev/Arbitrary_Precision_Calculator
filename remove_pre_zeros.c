#include "apc.h"

int remove_pre_zeros(node **head,node **tail)
{
  if(*head == NULL)
  {
        return FAILURE;  
    }
    
    if((*head)->data != 0){
         return FAILURE;
    }


    while(*head != NULL && (*head)->data == 0)
    {
        node* temp = *head;
        *head = (*head)->next;
        if(*head != NULL)
        {
            (*head)->prev = NULL;
        }
        free(temp);
    }
    return SUCCESS; 
}