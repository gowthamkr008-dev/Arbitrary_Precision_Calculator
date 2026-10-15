#include"apc.h"

int create_list(char *oper,node **head,node **tail)
{
  int i=0;
  
  if(oper[i] == '+' || oper[i] == '-')
  {
    i++;
  }
  
  while(oper[i] != '\0')
  {
    if(insert_last(head,tail,oper[i]-'0') == FAILURE)
    {
      return FAILURE;
    }
    i++;
  }
  return SUCCESS;
}