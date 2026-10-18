#include "apc.h"


int subtraction(node *tail1,node *tail2,node **headR,node **tailR){
  int sub,barrow = 0;
  while(tail1 != NULL && tail2 != NULL){
    if( (tail1->data > tail2->data)  || (tail1->data ==  tail2->data) ){
      sub = tail1->data - tail2->data;
    }else if(tail1->data < tail2->data) {
      if( tail1->prev != NULL){
      tail1->prev->data -= 1;
      tail1->data += 10;
      sub = tail1->data - tail2->data;
      }
    }
    if(insert_first(headR,tailR,sub) == FAILURE){
      return FAILURE;
    }
    sub = 0;
    tail1 = tail1->prev;
    tail2 = tail2->prev;
  }
  if(tail1 == NULL && tail2 != NULL){
    while(tail2 != NULL){
      if(tail2->data < 0){
        if(tail2->prev != NULL)
        {
          tail2->prev->data -=1;
          tail2->data += 10;
        }
      }
      sub = tail2->data;
       if(insert_first(headR,tailR,sub) == FAILURE){
      return FAILURE;
    }
    tail2 = tail2->prev;
    }
    return SUCCESS;
  }else if(tail1 != NULL && tail2 == NULL){
     while(tail1 != NULL){
      if(tail1->data < 0){
        if(tail1->prev != NULL)
        {
          tail1->prev->data -=1;
          tail1->data += 10;
        }
      }
      sub = tail1->data;
       if(insert_first(headR,tailR,sub) == FAILURE){
      return FAILURE;
    }
    sub = 0;
    tail1 = tail1->prev;
    }
    return SUCCESS;
  }

<<<<<<< HEAD
  remove_pre_zeros(headR,tailR);
=======

>>>>>>> 9f6d74998bdfb0f48c6c00d7f220b48741cfeb51


 printf("\n");
  return SUCCESS;
}