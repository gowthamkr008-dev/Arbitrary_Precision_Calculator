#include "apc.h"

int remove_pre_zeros(node **head,node **tail)
{
  
    if (*head == NULL)
    {
        return FAILURE;
    }
    
    while ((*head)->data == 0 && (*head)->next != NULL)
    {
        node *temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
    }

    return SUCCESS;
}