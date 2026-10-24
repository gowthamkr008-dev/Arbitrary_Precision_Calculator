#include "apc.h"

int division(node *dividend_head,node *dividend_tail,node *divisor_head ,node *divisor_tail,node **headR,node **tailR)
{
 
  // node * dividend_head = head1; 
  // node * dividend_tail = tail1;

  // node *divisor_head = head2;
  // node * divisor_tail = tail2;
  int res;
  if((res = compare_list(dividend_head,divisor_head)) == -1){
    // printf("%d ",res);
    add_zeros(headR,tailR,1);
    return SUCCESS;
  }
  /*
   12345    = dividend
   -------
   5678     = divisor
   */


  node * diffh = NULL,*difft = NULL;
  node * increment_h = NULL;
  node * increment_t = NULL;
  node * count_h = NULL;
  node * count_t = NULL;


  if(insert_first(&increment_h,&increment_t,1)== FAILURE)
  {
    puts("allocation failure");
    return FAILURE;
  }
   
   if(insert_first(&count_h,&count_t,0) == FAILURE)
  {
    puts("allocation failure");
    return FAILURE;
  }

  

  // print_list(increment_h);
  node * div_head  = dividend_head;
  node * div_tail  = dividend_tail;
  
  // int i = 0;
    // printf("Divisor head\n");
    // print_list(divisor_head);


    while(1){
      uint len1 = list_length(dividend_head);
      uint len2 =list_length(div_head);

      if(len1 > len2 )
    {
      // swap = 0;
       if(subtraction(divisor_tail,div_tail,&diffh,&difft)== FAILURE){
        return FAILURE;
      }
    }else if(len1 < len2)
    {
      // swap = 1;
       if(subtraction(div_tail,divisor_tail,&diffh,&difft)== FAILURE){
        return FAILURE;
      }
    }else if(len1 == len2)
    {
      node *h1 = divisor_head;
      node *h2 = div_tail;
      // swap = 0;
      //  if(subtraction(divisor_tail,div_tail,&diffh,&difft)== FAILURE){
      //   return FAILURE;
      // }
      
      while(h1 != NULL && h2 != NULL)
      {
        if((h1->data > h2->data))
        {
          if(subtraction(divisor_tail,div_tail,&diffh,&difft)== FAILURE){
        return FAILURE;
      }
          break;
        }else if ((h1->data < h2->data))
        {
          // swap = 1;
          if(subtraction(div_tail,divisor_tail,&diffh,&difft)== FAILURE){
        return FAILURE;
      }
          break;
        }
        h1 =  h1->next;
        h2 = h2->next;
      }
    }
      if(addition(increment_t,count_t,headR,tailR) == FAILURE){
        return FAILURE;
      }
      delete_list(&count_h,&count_t);
      count_h = *headR;
      count_t = *tailR;

      *headR = NULL;
      *tailR= NULL; 
      printf("Count : ");
      print_list(count_h);

      if(compare_list(diffh,divisor_head) == -1){
        *headR = count_h;
        *tailR = count_t;
        return SUCCESS;
      }else{
        div_head = diffh;
        div_tail = difft;
        diffh = NULL;
        difft = NULL;
      }
    }


}


/*
      div_head = sumh;
      div_tail = sumt;
      print_list(div_head);
      sumh = NULL;
      sumt = NULL;
     
     
      if(compare_list(dividend_head,div_head)==-1){
        print_list(*count_head);
        return SUCCESS;
      }

      i++;



*/



/*



*/