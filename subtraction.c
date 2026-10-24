#include "apc.h"
// static void print_lists(node * head)
// {
//   if(head == NULL){
//     printf("List empty\n");
//     return ;
//   }
  
//   while (head != NULL)
//   {
//     printf("%d",(head)->data);
//     head = head->prev;
//   }
//   printf("\n");
// }

int subtraction(node *tail1,node *tail2,node **headR,node **tailR)
{
  // print_lists(tail1);
  // print_lists(tail2);
  

  int sub,barrow = 0;
  
  while(tail1 != NULL && tail2 != NULL)
  {
    
    if( (tail1->data > tail2->data)  || (tail1->data ==  tail2->data) )
    {
      sub = tail1->data - tail2->data;
    }else if(tail1->data < tail2->data)
    {
      if( tail1->prev != NULL)
      {
        tail1->prev->data -= 1;
        tail1->data += 10;
        sub = tail1->data - tail2->data;
      }
    }
    if(insert_first(headR,tailR,sub) == FAILURE)
    {
      return FAILURE;
    }
    
    sub = 0;
    tail1 = tail1->prev;
    tail2 = tail2->prev;
  }
  
  if(tail1 == NULL && tail2 != NULL)
  {
    
    while(tail2 != NULL)
    {
      if(tail2->data < 0)
      {
        if(tail2->prev != NULL)
        {
          tail2->prev->data -=1;
          tail2->data += 10;
        }
      }
      
      sub = tail2->data;
      
      if(insert_first(headR,tailR,sub) == FAILURE)
      {
      return FAILURE;
    }
    tail2 = tail2->prev;
  }
}else if(tail1 != NULL && tail2 == NULL)
{
  while(tail1 != NULL)
  {
    if(tail1->data < 0)
    {
      if(tail1->prev != NULL)
      {
        tail1->prev->data -=1;
        tail1->data += 10;
      }
    }
    sub = tail1->data;
    
    if(insert_first(headR,tailR,sub) == FAILURE)
    {
      return FAILURE;
    }
    
    sub = 0;
    tail1 = tail1->prev;
  }
}
  remove_pre_zeros(headR,tailR);
  // printf("\n");
  return SUCCESS;
}