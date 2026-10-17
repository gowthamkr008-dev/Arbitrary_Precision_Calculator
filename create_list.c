#include "apc.h"

int create_list(char *opr,node **head,node **tail)
{
  int len = 0,i =0;
  if(opr[0] == '+' || opr[0] == '-')
  {
    len++;
    i++;
  }
  
  while (opr[i] != '\0' && opr[i] == '0') i++;


  while (opr[i] != '\0')
  {
    if(insert_last(head,tail,opr[i]-'0')== FAILURE)
    {
      return FAILURE;
    }
    i++;
    len++;
  }
  
  // printf("list created : ");
  // print_list(*head);
  // printf("\n");
  return len;
}