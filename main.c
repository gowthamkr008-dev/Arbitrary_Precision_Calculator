#include "apc.h"

int main(int argc,char *argv[])
{
  /*verify user valid operator and operand*/
  if(cla_validation(argc,argv) == FAILURE){
    return FAILURE;
  }

  node *head1 = NULL,*tail1 = NULL,*head2 = NULL,*tail2 = NULL,*headR = NULL,*tailR = NULL;
  

  /* the same time creating list remove the pre zeros */
  int len1 =5;
  if( (len1 = create_list(argv[1],&head1,&tail1)) == FAILURE){
    return FAILURE;
  }

  /*save the 1stoperand sign*/
  char d_oper1  = ' ';
  if(argv[1][0] == '+' || argv[1][0] == '-'){
    d_oper1 = argv[1][0];
    len1 -= 1;
  }


  /* create a list at thime remove the zeros */
  int len2;
  if( (len2 = create_list(argv[3],&head2,&tail2)) == FAILURE){
    return FAILURE;
  }

  /*save the 2nd operand sign*/
  char d_oper2 = ' ';
  if(argv[3][0] == '+' || argv[3][0] == '-'){
    d_oper2 = argv[3][0];
    len2 -= 1;
  }

  printf("%c %c\n",d_oper1,d_oper2);
  char operation;
  if((d_oper1 == '+' && d_oper2 == '+') || (d_oper1 == '-' && d_oper2 == '-') ||(d_oper1 == ' ' && d_oper2 == ' ') ||(d_oper1 == '+' && d_oper2 == ' ')||(d_oper1 == ' ' && d_oper2 == '+') ){
  /* doing for addition*/
  if(argv[2][0] == '+')
  {
    operation = '+';
    if(head1 == NULL && head2 != NULL)
    {
      d_oper2 == '-' ? putchar(d_oper2)  : 0 ;
      print_list(head2);
      printf("\n");
      return SUCCESS;
    }else if(head2 == NULL && head1 != NULL)
    {
      d_oper1 == '-' ? putchar(d_oper1) :0 ;
      print_list(head1);  
      printf("\n");
      return SUCCESS;
    }else if(head1 ==  NULL && head2 == NULL)
    {
      printf("0\n");
      return SUCCESS;
    }
    

    if(len1 > len2)
    {
      /* add zeros in node 2*/
      if(head1 != NULL)
      {
        //do add 0
        len2 = len1 - len2;
        if(add_zeros(&head2,&tail2,len2) == FAILURE)
        {
          return FAILURE;
        }
      }
    }else if(len1 < len2)
    {
      /* add zeros in node 1*/
      if(head2 != NULL)
      {
        len1 = len2 - len1;
        if(add_zeros(&head1,&tail1,len1) == FAILURE)
        {
          return FAILURE;
        }
      }
    }
  }
}
 
 
  switch (operation)
  {

    case '+':
    {
      if(addition(tail1,tail2,&headR,&tailR) == FAILURE)
      {
        return FAILURE;
      }
      printf("\n");
      if((d_oper1 == '-' && d_oper2 == '-')){
        printf("-");
      }
      print_list(headR);
      printf("\n");
    }
      break;


      case '-':
      {

      }
      break;


      case '*':
      case 'X':
      case 'x':
      {

      }
      break;

      case '/':
      {

      }
      break;
  
  }
  return 0;
}


























/*
 char *opr1 ;
  if(remove_pre_zeros(argv[1],opr1)== FAILURE){
    return -1;
  }
  
  char *opr2;
  if(remove_pre_zeros(argv[3],opr2)== FAILURE){
    return -1;
  }
  
  /* create lits
  if(opr1[0] == '-'||opr1[0] == '+'){
   char operation = opr1[0];
   opr1++;
  }


  if(opr1[0] =='\0' && argv[2][0] == '+'){
    printf("%s",opr2);
  }
  








    // if(create_list(opr1,&head1,&tail1) == FAILURE){
  //   printf("Invalid");
  // }



  printf("Eof");
  return 0;
}


if(opr2[0] == '\0' && argv[2] == '/'){
    printf("Error: Division by zero is undefined.\n");
    return FAILURE;
  }


*/