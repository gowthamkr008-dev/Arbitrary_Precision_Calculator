#include "apc.h"
static int compare_list(node *head1,node *head2){
  uint len1 = list_length(head1);
  uint len2 = list_length(head2);
  node * h1 = head1;
  node *h2 = head2;
 
  if(len1 < len2 ){
    return -1;
  }else if(len1 > len2){
    return 1;
  }else{
    while(head1 != NULL && head2 != NULL){
      if(head1->data > head2->data){
        return 1;
      }else if(head1->data < head2->data){
        return -1;
      }
      head1 = head1->next;
      head2 = head2->next; 
    }
    return 0;
  }
  

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
     goto error;
    }
    // printf("inserted data : ");
    // print_list(input_head);
    int comp = compare_list(input_head,divisor_head);
  
    while( compare_list(input_head,divisor_head) >= 0){
      if(subtraction( input_tail,divisor_tail,&remainder_head,&remainder_tail)== FAILURE){
        goto error;
      }
      // print_list(remainder_head);
      delete_list(&input_head,&input_tail);
      input_head = remainder_head;
      input_tail = remainder_tail;

      remainder_head= NULL;
      remainder_tail = NULL;


      count++;
    }
    // printf("after data \n");
    // print_list(input_head);
    // printf("\n");

    if(insert_last(&qutient_head,&qutient_tail,count)== FAILURE){
      goto error;
    }
    dividend_head = dividend_head->next;
  }
  
if(remove_pre_zeros(&qutient_head,&qutient_tail)== FAILURE){
  goto error;
}
  *headR = qutient_head;
  *tailR = qutient_tail;
  return SUCCESS;


error:
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
  
/*

    // if(len1 > len2){
    //   if(subtraction(div_head,divisor_head,&diff_h,&diff_t)== FAILURE){
    //     return FAILURE;
    //   }
    // }else if(len1 < len2){
    //   if(subtraction(divisor_head,div_head,&diff_h,&diff_t)== FAILURE){
    //     return FAILURE;
    //   }
    // }else{
    //   node *h1 = div_head;
    //   node *h2 = divisor_head;
    //   int done =0;
    //   while(h1 != NULL && h2 != NULL){
    //     if(h1->data > h2->data){
    //       done =1;
    //        if(subtraction(div_head,divisor_head,&diff_h,&diff_t)== FAILURE){
    //         return FAILURE;
    //       }
    //       break;
    //     }else if(h1->data < h2->data){
    //       done =1;
    //       if(subtraction(divisor_head,div_head,&diff_h,&diff_t)== FAILURE){
    //         return FAILURE;
    //       }
    //       break;
    //     }

    //     h1 = h1->next;
    //     h2 = h2->next;
    //   }
    //   if(done == 0){
    //       if(subtraction(div_head,divisor_head,&diff_h,&diff_t)== FAILURE){
    //     return FAILURE;
    //   }
    //   }
    // }




*/




/*

#include "apc.h"

int division(node *dividend_head,node * divident_tail,node * divisor_head,node *divisor_tail,node **headR,node **tailR){

  if(compare_list(dividend_head,divisor_head)== -1){
    if(add_zeros(headR,tailR,1)== FAILURE){
      return FAILURE;
    }
    return SUCCESS;
  }

  node * count_h = NULL;
  node * count_t = NULL;

  node * increment_h = NULL;
  node * increment_t = NULL;
  
  node * diff_h = NULL;
  node * diff_t = NULL;

  /* increment insert a data 1

  if(insert_first(&increment_h,&increment_t,1)== FAILURE){
    return FAILURE;
  }

  /* count set to 0 
  if(insert_first(&count_h,&count_t,0)== FAILURE){
    return FAILURE;
  }


  node * div_head = dividend_head;
  node * div_tail = divident_tail;

  int i=0;
  while(1){

    // print_list(div_head);
    // print_list(divisor_head);
    
    if(subtraction(div_tail,divisor_tail,&diff_h,&diff_t)== FAILURE){
        return FAILURE;
      }
    /*increment by 1 the count
    if(addition(increment_t,count_t,headR,tailR)== FAILURE){
      return FAILURE;
    }

    delete_list(&count_h,&count_t);

    count_h = *headR;
    count_t = *tailR;

    // print_list(diff_h);
    if(compare_list(diff_h,divisor_head) == -1){
      printf("answer : ");
      print_list(*headR);
      delete_list(&increment_h,&increment_t);
      delete_list(&diff_h,&diff_t);
      return SUCCESS;
    }
    // printf(" ");
    *headR = NULL;
    *tailR = NULL;
    delete_list(&div_head,&div_tail);

    div_head = diff_h;
    div_tail = diff_t;


    diff_h = NULL;
    diff_t = NULL;
    // i++;



  }

  
}



*/