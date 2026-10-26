/***********************************************************************************************************************************************************
Title     : Division

Operation : Division in APC works like long division on paper. The dividend is read one digit at a time and each digit is added to a running number. 
            While that running number is greater than or equal to the divisor, the divisor is subtracted from it and a counter goes up. When the running 
            number becomes smaller than the divisor, the counter is stored as the next digit of the quotient, and the loop moves on to the next dividend 
            digit. Any leading zeros are then removed from the quotient. The sign of the result is positive when both numbers have the same sign and negative 
            when they differ, and division by zero is rejected.

Input     :  2 operand tail head and tail pointer and result pointers 


Output    :   SUCCESS  All operation done properly prigram run succesfully 
              FAILURE  any memory allocation failure program stop there itself 


Sample Testcase :

                 Input : 12345 / 5

                 output :    246        output 246
                            ------
                        5 | 1234
                          | 10        5 x 2 = 10
                          | --
                          |  23       bring down 3
                          |  20       5 x 4 = 20
                          |  --
                          |   34      bring down 4
                          |   30      5 x 6 = 30
                              --
                               4     

***********************************************************************************************************************************************************/

#include "apc.h"


static uint list_length(node *head){                            /* find list length use in this file only */
  uint i =0;
  while(head != NULL){
    i++;
    head = head->next;
  }
  return i;
}


static int compare_list(node *head1,node *head2)                    /* compare the 2 give nodes */
{
    while (head1 != NULL && head1->data == 0 && head1->next != NULL) /* avoiding the starting zeros from starting of the list 1 */
    {
        head1 = head1->next;
    }
    while (head2 != NULL && head2->data == 0 && head2->next != NULL) /* avoiding the starting zeros from starting of the list 2*/
    { 
        head2 = head2->next;
    }


    uint len1 = list_length(head1);                                 /* find the list length */
    uint len2 = list_length(head2);

    if (len1 < len2) return -1;                                    /* list 1 length is greater than list 2 return -1 */
    if (len1 > len2) return 1;                                     /* list 2 lingth is greater than list 1 return 1*/

    while (head1 != NULL && head2 != NULL)                         /* both list are in equla length */
    {
        if (head1->data > head2->data) return 1;                   /* check the each data by data *//*node 1 data  is grater than node 2 data  return 1*/
        if (head1->data < head2->data) return -1;                 /*node 2 data  is grater than node 1 data  return -1*/
        head1 = head1->next;
        head2 = head2->next;
    }
    return 0;                                                     /* both data equal return 0 */ 
}


int division(node *dividend_head,node * dividend_tail,node * divisor_head,node *divisor_tail,node **headR,node **tailR)
{
  node * qutient_head = NULL;
  node * qutient_tail = NULL;

  node * input_head = NULL;
  node * input_tail = NULL;

  node * remainder_head = NULL;
  node * remainder_tail = NULL;
  
  int count;
  while (dividend_head != NULL)                                      /*loop will operand 1 head reach us to null */
  {
    count = 0;
    
    if(insert_last(&input_head,&input_tail,dividend_head->data)== FAILURE)    /* insert a data to last for next operation*/
    {
      if(qutient_head != NULL)                                          /* any failure cases delete all the list program stor the line */
      {
        delete_list(&qutient_head,&qutient_tail);
      }
      if(remainder_head != NULL){
        delete_list(&remainder_head,&remainder_tail);
      }
      if(input_head != NULL){
        delete_list(&input_head,&input_tail);
      }
      return FAILURE;
    }
    
    
    while( compare_list(input_head,divisor_head)  >= 0 )                             /* before getting inside the loop call compare function the given input node and operand 2 is subtractable or not compare return 1 loop get inside otherwise loop not go to next step get out of the loop */
    {
      if(subtraction(input_tail, divisor_tail,&remainder_head,&remainder_tail) == FAILURE) /* subtract the input head node and divisor node  */
      {
        if(qutient_head != NULL)
        {
          delete_list(&qutient_head,&qutient_tail);
        }
        if(remainder_head != NULL)
        {
          delete_list(&remainder_head,&remainder_tail);
        }
        if(input_head != NULL)
        {
          delete_list(&input_head,&input_tail);
        }
        return FAILURE;
      }
      
      delete_list(&input_head,&input_tail);                                                  /*delete the list no use for the input head */
      
      input_head = remainder_head;                                                           /* remainder head and tail address points to input head and tail*/
      input_tail = remainder_tail;
      remainder_head= NULL;                                                                  /* remainder head and tail assign the the NULL for next subtraction*/
      remainder_tail = NULL;
      
      count++;                                                                               /* count number of time loop will runned*/
    }
    
    if(insert_last(&qutient_head,&qutient_tail,count) == FAILURE)                           /* count has inserted at the last for result */
    {
      if(qutient_head != NULL)
      {
        delete_list(&qutient_head,&qutient_tail);
      }
      
      if(remainder_head != NULL)
      {
        delete_list(&remainder_head,&remainder_tail);
      }
      
      if(input_head != NULL)
      {
        delete_list(&input_head,&input_tail);
      }
      return FAILURE;
    }
    dividend_head = dividend_head->next;
  }
  if(remove_pre_zeros(&qutient_head,&qutient_tail)== FAILURE)                               /* any pre zeros in quitient */
  {
    if(qutient_head != NULL)
    {
      delete_list(&qutient_head,&qutient_tail);
    }
    
    if(remainder_head != NULL)
    {
      delete_list(&remainder_head,&remainder_tail);
    }
    
    if(input_head != NULL)
    {
      delete_list(&input_head,&input_tail);
    }
    
    return FAILURE;
  }
  
  *headR = qutient_head;                                /* quitient asign to the result heads*/
  *tailR = qutient_tail;
  return SUCCESS;
}
  