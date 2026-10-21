#include "apc.h"

int add_zeros_last(node **head,node **tail,int len){
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