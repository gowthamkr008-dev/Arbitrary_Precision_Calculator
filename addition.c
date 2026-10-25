#include "apc.h"
/***********************************************************************************************************************************************************
Title : Addition

Operation : This function do the addition digit by digit fom the last and store the output in the result in headR list 

Input  : Two operands tail

output : SUCCESS   It means addition done succesfully 
         FAILURE   Any allocation failure 




***********************************************************************************************************************************************************/

int addition(node *tail1,node *tail2,node **headR,node **tailR)
{
  int carry = 0,sum;
 
  while (tail1 != NULL && tail2 != NULL)
  {
    sum = tail1->data + tail2->data + carry; 
    if(sum > 9)
    {
      carry = 1;
      sum  = sum % 10;
    }else
    {
      carry = 0;
    }
    
    if(insert_first(headR,tailR,sum) == FAILURE)
    {
      return FAILURE;
    }
    tail1 = tail1->prev;
    tail2 = tail2->prev;
  }
  
  if(tail1 == NULL && tail2 == NULL)
  {
    if(carry)
    {
      if(insert_first(headR,tailR,carry) == FAILURE){
        return FAILURE;
      }
    }
    return SUCCESS;
  }else if(tail1 != NULL)
  {
    while (tail1 != NULL)
    {
      sum = tail1->data + carry;
      if(sum > 9)
      {
        carry = 1;
        sum  = sum % 10;
      }else
      {
        carry = 0;
      }
      
      if(insert_first(headR,tailR,sum) == FAILURE)
      {
        return FAILURE;
      }
      tail1 = tail1->prev;
    }

    if(carry)
    {
      insert_first(headR,tailR,carry);
    }
    return SUCCESS;
  }else if(tail2 != NULL)
  { 
    while (tail2 != NULL)
    {
      sum = tail2->data + carry;
      if(sum > 9)
      {
        carry = 1;
        sum  = sum % 10;
      }else
      {
      carry = 0;
    }
    
    if(insert_first(headR,tailR,sum) == FAILURE)
    {
      return FAILURE;
    }
    tail2 = tail2->prev;
  }
  if(carry)
    {
      insert_first(headR,tailR,carry);
    }
  return SUCCESS;
}
}


