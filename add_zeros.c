#include "apc.h"

int add_zeros(node **head,node **tail,int len){
  // printf("add zeros first\n");
  //  print_list(*head);
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