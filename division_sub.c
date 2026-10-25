#include "apc.h"
static int compare_list(node *head1,node *head2)
{
  /* avoiding the starting zeros from starting of the list*/
    while (head1 != NULL && head1->data == 0 && head1->next != NULL)
    {
        head1 = head1->next;
    }
    while (head2 != NULL && head2->data == 0 && head2->next != NULL){
        head2 = head2->next;
    }


    uint len1 = list_length(head1);
    uint len2 = list_length(head2);

    if (len1 < len2) return -1;
    if (len1 > len2) return 1;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data > head2->data) return 1;
        if (head1->data < head2->data) return -1;
        head1 = head1->next;
        head2 = head2->next;
    }
    return 0;  
}


int division(node *dividend_head,node * dividend_tail,node * divisor_head,node *divisor_tail,node **headR,node **tailR){
  node * qutient_head = NULL;
  node * qutient_tail = NULL;

  node * input_head = NULL;
  node * input_tail = NULL;

  node * remainder_head = NULL;
  node * remainder_tail = NULL;

  // puts("Start division");
  int count;
  while (dividend_head != NULL){
    count = 0;

    if(insert_last(&input_head,&input_tail,dividend_head->data)== FAILURE){
      if(qutient_head != NULL){
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
    while( compare_list(input_head,divisor_head)  >= 0 ){
      if(subtraction(input_tail, divisor_tail,&remainder_head,&remainder_tail)== FAILURE){
       if(qutient_head != NULL){
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
      delete_list(&input_head,&input_tail);
     

      input_head = remainder_head;
      input_tail = remainder_tail;
      remainder_head= NULL;
      remainder_tail = NULL;
      
      count++;
       }
   
    if(insert_last(&qutient_head,&qutient_tail,count) == FAILURE){
      if(qutient_head != NULL){
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
    dividend_head = dividend_head->next;
  }
  
if(remove_pre_zeros(&qutient_head,&qutient_tail)== FAILURE){
 if(qutient_head != NULL){
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
  *headR = qutient_head;
  *tailR = qutient_tail;
  return SUCCESS;



}
  