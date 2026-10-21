#include "apc.h"

int multiplication(node *tail1,node *tail2,node **headR,node **tailR){
  
  node *t_h_r1 = NULL,*t_t_r1 = NULL; /* t_h_r1 = temp head result 1 ,t_t_r1 = temp tail result1*/
   node *t_h_r2 = NULL,*t_t_r2 = NULL;
   node   * final_res_head = NULL,*final_res_tail = NULL;
 
   int mul,carry = 0,digit;
  node * temp = tail1; // after every digit of tail2 completion tail 2 comes back to tail opsition

  int count = 1;
  int len = 0;
  /*loop for tail 2 for each digit multiplication*/
  while(tail2 != NULL){
    while(temp != NULL){
      carry = 0;
      mul = (temp->data * tail2->data) + carry;
      
      if(mul > 9 ){
        digit =  mul % 10;
        carry = mul / 10;
      // printf("%d x %d + %d = %d\n",temp->data,tail2->data,carry,digit);

        if(insert_first(&t_h_r1,&t_t_r1,digit)== FAILURE){
          return FAILURE;
        }
      }else{
        carry = 0;
         if(insert_first(&t_h_r1,&t_t_r1,mul)== FAILURE){
          return FAILURE;
        }
      }
      temp = temp->prev;
    }

    if(carry){
      if(insert_first(&t_h_r1,&t_t_r1,carry)== FAILURE){
          return FAILURE;
      }
    }

    // printf("Adding : \n");
    // print_list(t_h_r1);
    // print_list(t_h_r2);
    if(addition(t_t_r1,t_t_r2,&final_res_head,&final_res_tail)== FAILURE){
      return FAILURE;
    }
    // print_list(final_res_head);
    
    delete_list(&t_h_r2,&t_t_r2);
    delete_list(&t_h_r1,&t_t_r1);

    t_h_r2 = final_res_head;
    t_t_r2 = final_res_tail;
    if(tail2->prev != NULL){
    if(add_zeros_last(&t_h_r1,&t_t_r1,count++)== FAILURE){
      return FAILURE;
    }
  }
//  print_list(t_h_r2);

    final_res_head = NULL;
    final_res_tail = NULL;
    
    temp = tail1;
    tail2 = tail2->prev;
  }
// print_list(t_h_r2);

return SUCCESS;
}

    



    /*
    
    print_list(t_h_r1);
    print_list(t_h_r2);
    if(addition(t_t_r1,t_t_r2,&final_res_head,&final_res_tail) == FAILURE){
      return FAILURE;
    }
    // print_list(final_res_head);
    delete_list(&t_h_r1,&t_t_r1);
    t_h_r2 = final_res_head;
    t_t_r2 = final_res_tail;
    final_res_head = NULL;
    final_res_tail = NULL;
    print_list(t_h_r2);
    if(tail2->prev!= NULL){
      if(add_zeros_last(&t_h_r2,&t_t_r2 , count++)== FAILURE){
      return FAILURE;
    }
  }
    printf("After add zeros : ");
     print_list(t_h_r2);
    printf("\n");
    temp = tail1;
    tail2 = tail2->prev;
  }
  printf("Final result : ");
  print_list(t_h_r2);
}
    
    
    */