#include "apc.h"
/***********************************************************************************************************************************************************
Title : Addition

Operation : This function do the addition digit by digit fom the last and store the output in the result in headR list 

Input  : Two operands tail

output : SUCCESS   It means addition done succesfully 
         FAILURE   Any allocation failure 

Sample Testcase : 
                Input : 1234 + 976

                Output :    1234
                          +  976
                          ------
                            2210
                          ------


    



***********************************************************************************************************************************************************/

int addition(node *tail1,node *tail2,node **headR,node **tailR)
{
  int carry = 0,sum;
 
  while (tail1 != NULL && tail2 != NULL)                    /* do the addition both list same list */
  {
    sum = tail1->data + tail2->data + carry;                /* add the operand  1 and operand 2 and carry*/
    if(sum > 9)                                             /* the sum has greater than 9 carry has 1 */
    {
      carry = 1;
      sum  = sum % 10;                                     /*take last digit of the sum*/
    }else
    {
      carry = 0;
    }
    
    if(insert_first(headR,tailR,sum) == FAILURE)              /*insert the result to headR*/
    {
      return FAILURE;
    }
    tail1 = tail1->prev;                                     /*move to next node for next step addition */
    tail2 = tail2->prev;
  }
  
  if(tail1 == NULL && tail2 == NULL)                         /*both operand complete the addition any carry there add at result list */
  {
    if(carry)
    {
      if(insert_first(headR,tailR,carry) == FAILURE){
        return FAILURE;
      }
    }
    return SUCCESS;
  }else if(tail1 != NULL)                                     /*1st operand length is greater than the 2nd operand complete addition the 2nd operand join the other numbers to the result*/
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
  }else if(tail2 != NULL)                                  /*2n operand length is greater than the 1st operand complete addition the 1st operand join the other numbers to the result*/
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
      if(insert_first(headR,tailR,carry)==FAILURE){
        return FAILURE;
      }
    }
  return SUCCESS;
}
}


