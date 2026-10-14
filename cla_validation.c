#include "apc.h"

int cla_validation(int argc, char *argv[]){
  if(argc != 4){
    printf("Error: Invalid number of arguments.\n");
    usage_message();
    return FAILURE;
  }
  if(strcmp(argv[2], "+" ) == 0 || strcmp(argv[2], "-") == 0 ||strcmp(argv[2],"x" )== 0 ||strcmp(argv[2],"X" )== 0 ||strcmp(argv[2],"/" ) == 0 || strcmp(argv[2],"%" ) == 0 ){
  }else{
    printf("Error : Invalid operator '%s'. Supported operators are +, -, *, /,%% \n",argv[2]);
    return FAILURE;
  }

  int i=0;
  if((argv[1][0] == '+' || argv[1][0] == '-') ){
    i++;
  }
  if(argv[1][i] == '\0'){
    puts("Error: Operand 1 is invalid (empty or contains only sign).");
    return FAILURE;
  }
  while (argv[1][i] != '\0')
  {
    if (!isdigit((unsigned char)argv[1][i])) {
    printf("Error: Operand 1 contains invalid character '%c'\n", argv[1][i]);
    return FAILURE;
  }
    i++;
  }
  i=0;

   if((argv[3][0] == '+' || argv[3][0] == '-') ){
    i++;
  }
  if(argv[3][i] == '\0'){
    puts("Error: Operand 2 is invalid (empty or contains only sign).");
    return FAILURE;
  }

  while (argv[3][i] != '\0')
  {
    if( !(isdigit(argv[3][i]) )){
      printf("Error: Operand 2 contains invalid character '%c'\n",argv[3][i]);
      return FAILURE;
    }
    i++;
  }
  

  // printf("%s\n",argv[1]);



  return SUCCESS;
}

/*
❌

*/
