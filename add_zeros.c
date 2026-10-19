#include "apc.h"

int add_zeros(node **head,node **tail,int len){
  int i;
  for(i = 0;i < len;i++)
  {
    if(insert_first(head,tail,0) == FAILURE)
    {
      return FAILURE;
    }
  }
  return SUCCESS;
}