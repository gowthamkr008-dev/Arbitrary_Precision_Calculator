#include "apc.h"

/* remove the zero form the node */
int remove_pre_zeros(node **head,node **tail)
{
  
    if (*head == NULL)
    {
        return FAILURE;
    }
    
    while ((*head)->data == 0 && (*head)->next != NULL) /* loop will run until any digit apperan other than zeor or NULL*/
    {
        node *temp = *head;                             /*take backup */
        *head = (*head)->next;                          /*node moves to next node*/
        (*head)->prev = NULL;                           
        free(temp);                                     /*delete the backup node */
    }
    
    return SUCCESS;
}