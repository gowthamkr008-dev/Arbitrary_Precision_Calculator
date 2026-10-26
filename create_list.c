#include "apc.h"

/*create a list */
int create_list(char *opr,node **head,node **tail)
{

  int len = 0, i = 0;
  /*avoid the sign */
  if(opr[0] == '+' || opr[0] == '-')
       i++;
  
  /*remove the zeros in the list */
  while (opr[i] != '\0' && opr[i] == '0') i++;


  /*create a list insert from the last */
  while (opr[i] != '\0')
  {
    if(insert_last(head,tail,opr[i] - '0') == FAILURE)
    {
      return FAILURE;
    }
    i++;
    len++;
  }

  if(len == 0)
  {
    *head = NULL;
    *tail = NULL;
  }

  /*return the length to get the list length */
  return len;
}