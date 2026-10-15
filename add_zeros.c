#include "apc.c"

int add_zeros(node **head,node **tail,int len)
{
  for(int i = 0;i < len; i++)    
  {
    if(insert_first(head,tail,0)== FAILURE)
    {
      printf("Insertion Failure\n");
      return FAILURE;
    }
  }
  print_list(*head);
  printf("\n");
}