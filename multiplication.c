#include "apc.h"
static int add_zeros_last(node **head,node **tail,int len){
  // printf("Add zeros\n");
 
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
  node *t_h_r1 = NULL,*t_t_r1 = NULL; /* t_h_r1 = temp head result 1 ,t_t_r1 = temp tail result1*/
  node *t_h_r2 = NULL,*t_t_r2 = NULL;
  node   * final_res_head = NULL,*final_res_tail = NULL;
  
  int mul,carry = 0,digit;
  
  node * temp = tail1; 

  int count = 1;
  int len = 0;
  
  while(tail2 != NULL)
  {
     carry = 0;
    while(temp != NULL)
    {
      mul = (temp->data * tail2->data) + carry;
      
      if(mul > 9 )
      {
        digit =  mul % 10;
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
      temp = temp->prev;
    }
     if(carry)
    {
      if(insert_first(&t_h_r1,&t_t_r1,carry)== FAILURE)
      {
           goto error;
      }
    }

    if(addition(t_t_r1,t_t_r2,&final_res_head,&final_res_tail)== FAILURE){
      goto error;
    }
    delete_list(&t_h_r2,&t_t_r2);
    delete_list(&t_h_r1,&t_t_r1);

    t_h_r2 = final_res_head;
    t_t_r2 = final_res_tail;

    if(tail2->prev != NULL){
    if(add_zeros_last(&t_h_r1,&t_t_r1,count++)== FAILURE){
        goto error;
    }
  }
  
  final_res_head = NULL;
  final_res_tail = NULL;
    
    temp = tail1;
    tail2 = tail2->prev;
  }

  *headR = t_h_r2;
  *tailR = t_t_r2;
  t_h_r2 = NULL;
  t_t_r2 = NULL;

return SUCCESS;



error:
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

    


