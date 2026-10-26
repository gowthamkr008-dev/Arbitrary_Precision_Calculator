/***********************************************************************************************************************************************************
Title     : Multiplication

Operation : Do the multiplication both start from tail position,each time 2 operand every digit multiplied and store in temporary node the addition betweent
            the temporary nodes the result stored in the 2nd temporary node then after 2nd node moves to the next node add a zero from the before geting the 
            multiplication data then again do that time 1st temporary node add 2 zero every time incremented by 1 to add zero for proper multiplication output
            the final output stores to the headR node

Input     : 2 operand tail and result node 

Output    : SUCCESS the program run properly to get the output
            FAILURE Any memory allocation failure the program get stop

Sample test case :
                  Input operand 1 :  1234
                  Input operand 2 :   5678
                  operation       :   x

                  Output          : 7006652

                  step 1   1234 x  8  =    9872
                  step 2   1234 x  7  =   86380
                  step 3   1234 x  6  =  740400
                  step 4   1234 x  5  = 6170000
                          ------------------------
                  program output      = 7006652
                          ------------------------

***********************************************************************************************************************************************************/



#include "apc.h"
static int add_zeros_last(node **head,node **tail,int len){
  int i;
  for(i = 0;i < len;i++)
  {
    if(insert_last(head,tail,0) == FAILURE)
    {
      return FAILURE;
    }
  }
  return SUCCESS;
}



int multiplication(node *tail1,node *tail2,node **headR,node **tailR)
{

  node *t_h_r1 = NULL,*t_t_r1 = NULL;                    /* t_h_r1 = temp head result 1 ,t_t_r1 = temp tail result 1 */
  node *t_h_r2 = NULL,*t_t_r2 = NULL;                    /* t_h_r2 = temp head result 2 ,t_t_r2 = temp tail result 2*/
  node   * final_res_head = NULL,*final_res_tail = NULL;
  
  int mul,carry = 0,digit;  
  
  node * temp = tail1;                                   /* take a temporary node for each time traversel */

  int count = 1;
  
  while(tail2 != NULL)                                  /* loop will run the 2 operand tail get the NULL position*/
  {
     carry = 0;
    while(temp != NULL)                                 /* loop will run 1 operand get the null position */
    {
      mul = (temp->data * tail2->data) + carry;         /* multiply the operand 1 and operand 2 then add the carry */
      
      if(mul > 9 )                                     /* the multipied result is greater than 9 */
      {
        digit =  mul % 10;                              /* take a last digit of multiplication and store to the temp result 1 node */
        carry = mul / 10;
       if(insert_first(&t_h_r1,&t_t_r1,digit)== FAILURE){
          goto error;
        }
      }else{
        carry = 0;
        if(insert_first(&t_h_r1,&t_t_r1,mul)== FAILURE){
           goto error;
        }
      }
      temp = temp->prev;                                 /*temp pointer moves to the next node of the operand 1 */
    }
     if(carry)                                           /* after done multiplication of the one time any carry there that store to the temp result 1 node */                                           
     {
      if(insert_first(&t_h_r1,&t_t_r1,carry)== FAILURE)
      {
           goto error;
      }
    }

    if(addition(t_t_r1,t_t_r2,&final_res_head,&final_res_tail)== FAILURE){  /* adding the temp result 1 and temp result 2 and store in final result pointer */
      goto error;
    }
    delete_list(&t_h_r2,&t_t_r2);                                          /* delete the temporary pointer  */
    delete_list(&t_h_r1,&t_t_r1);

    t_h_r2 = final_res_head;                                                /* final result node points to 2 temp resul */
    t_t_r2 = final_res_tail;

    if(tail2->prev != NULL){
    if(add_zeros_last(&t_h_r1,&t_t_r1,count++)== FAILURE){                   /* adding the zero to the last for addition for proper multiplication */
        goto error;
    }
  }
  
  final_res_head = NULL;
  final_res_tail = NULL;
    
    temp = tail1;
    tail2 = tail2->prev;
  }

  *headR = t_h_r2;                                                         /* assign a temporary result 2 to the headR pointer*/
  *tailR = t_t_r2;
  t_h_r2 = NULL;                                                                
  t_t_r2 = NULL;

return SUCCESS;



error:                                                                     /* any failure appear in the program efore going to the main delete the all created node then return  */
    if(t_h_r1 != NULL){
      delete_list(&t_h_r1,&t_t_r1);
    }
    if(t_h_r2 != NULL){
      delete_list (&t_h_r2,&t_t_r2);
    }

    if(final_res_head != NULL){
      delete_list(&final_res_head,&final_res_tail);
    }



}

    


