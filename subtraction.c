/***********************************************************************************************************************************************************
Title     : Subtraction

operation : Do the subtraction digit by igit from the last and store to the result in headR node 

Input     : Two operand tail

Output    : SUCCCESS the subtraction done properly
          : FAILURE return failure when memory allocation failure

<<<<<<< HEAD
=======

Sample Testcase : 
                Input : 1234 - 976

                Output :    1234
                          -  976
                          -------
                             258
                          -------
>>>>>>> 464f81a (8:22 27-10-26)
***********************************************************************************************************************************************************/

#include "apc.h"

int subtraction(node *tail1,node *tail2,node **headR,node **tailR)
{
  int sub = 0;
  
  while(tail1 != NULL && tail2 != NULL)                                            /*subtraction do until the both are in same length */
  {
    
    if( (tail1->data > tail2->data)  || (tail1->data ==  tail2->data) )            /*operand 1 is greater than operand 2*/
    {
      sub = tail1->data - tail2->data;                                             /*subtract the operand 1 and operand 2*/
    }else if(tail1->data < tail2->data)                                            /*operand 1 is less than operand 2 take a barrow from the last */
    {
      if( tail1->prev != NULL)
      {
        tail1->prev->data -= 1;                                                   /* take a barrow from the previous node*/
        tail1->data += 10;
        sub = tail1->data - tail2->data;
      }
    }

    if(insert_first(headR,tailR,sub) == FAILURE)                                     /*inser a data to the result node*/
    {
      return FAILURE;
    }
    sub = 0;
    tail1 = tail1->prev;
    tail2 = tail2->prev;
  }


  if(tail1 == NULL && tail2 != NULL)                                                /* both operand length is not a same */
  {
    
    while(tail2 != NULL)                                                             /* inser other data to the result */
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
        tail1->prev->data -= 1;
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
  remove_pre_zeros(headR,tailR);                                     /* after subtracting remove pre zeros */
  return SUCCESS;
}