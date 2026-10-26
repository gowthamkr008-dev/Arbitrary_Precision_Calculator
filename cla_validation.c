#include "apc.h"

int cla_validation(int argc,char *argv[])
{
  /*proper argument */
  
  if(argc != 4)
  {
    puts("Error : Invalid number of arguments. ");
    printf("Usage : %s <operand1> <operator> <operand2>\n",argv[0]);
    return FAILURE;
  }
  
  /*user given proper operator or not */
  
  if( (strcmp(argv[2],"+") != 0) && (strcmp(argv[2],"-") != 0) && (strcmp(argv[2],"*") != 0) && (strcmp(argv[2],"x") != 0) && (strcmp(argv[2],"X") != 0) && (strcmp(argv[2],"/") != 0) && (strcmp(argv[2],"%") != 0) && (strcmp(argv[2],"^") != 0) )
  {
    printf("Error: Invalid operator '%s'. Supported operators are +, -, *, /\n",argv[2]);
    return FAILURE;
  }
  
  /* check the 1st operand*/
  /* check the sign*/
  int i = 0;
  
  /*any sign berfore the operand avoid the sign to checking the inside the digit checking*/
  if(argv[1][0] == '+' ||argv[1][0] == '-') i++;
  
  /* user given 1st proper operand or not*/
  if(argv[1][0] == '\0' || ( (argv[1][0] == '+' || argv[1][0] == '-') && argv[1][1] == '\0') )
  {
    puts("Error: Operand 1 is invalid (empty or contains only sign).");
    return FAILURE;
  }
  
  while(argv[1][i] != '\0')
  {
    if(!isdigit(argv[1][i]))
    {
      printf("Error: Operand 1 contains invalid character '%c'\n", argv[1][i]);
      return FAILURE;
    }
    i++;
  }
  
  /* check the 2nd operand*/
  /* check the sign*/
  i=0;
  if(argv[3][0] == '+' ||argv[3][0] == '-') i++;


  /* user given 1st proper operand or not*/
  if(argv[3][0] == '\0' || ( (argv[3][0] == '+' || argv[3][0] == '-') && argv[3][1] == '\0'))
  {
    puts("Error: Operand 2 is invalid (empty or contains only sign).");
    return FAILURE;
  }
  while(argv[3][i] != '\0')
  {
    if(!isdigit(argv[3][i]))
    {
      printf("Error: Operand 2 contains invalid character '%c'\n", argv[3][i]);
      return FAILURE;
    }
    i++;
  }
  return SUCCESS;
}