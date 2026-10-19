#include "apc.h"

int add_zeros(node **head,node **tail,int len){
  for(int i = 0;i < len;i++)
  {
    if(insert_first(head,tail,0) == FAILURE)
    {
      return FAILURE;
    }
  }
  return SUCCESS;
}