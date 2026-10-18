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
  }

  // printf("%c %c\n",d_oper1,d_oper2);
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
  short swap = 0; 
  // printf("length1 %d\nlength2 %d",len1,len2);
  if((d_oper1 == '+' && d_oper2 == '+') ||(d_oper1 == '-' && d_oper2 == '-')||(d_oper1 == ' ' && d_oper2 == ' ')){
  if(argv[2][0] == '-'){
    operation = '-';
    if(head1 == NULL && head2 != NULL){
      if(d_oper2 != '-'){
       printf("-");
      }
      printf("%s\n",argv[3]);
      return SUCCESS;
    }else if(head1 != NULL && head2 == NULL){ 
      printf("%s\n",argv[1]);
      return SUCCESS;
    }else if (head1 == NULL && head2 == NULL){
      printf("0");
      return SUCCESS;
    }

    if(len1 > len2 ){
      swap = 0;
    }else if(len1 < len2){
      swap = 1;
    }if(len1 == len2){
      node *h1 = head1;
      node *h2 = head2;
      swap = 0;
      while(h1 != NULL && h2 != NULL){
        if(h1->data > h2->data){
          swap = 0;
          break;
        }else if (h1->data < h2->data){
          swap =1;
          break;
        }
        h1 =  h1->next;
        h2 = h2->next;
      }
    }

  }
}

  // print_list(head1);
  // print_list(head2);
 
 
  switch (operation)
  {

    case '+':
    {
      if(addition(tail1,tail2,&headR,&tailR) == FAILURE)
      {
        return FAILURE;
      }

      if((d_oper1 == '-' && d_oper2 == '-')){
        printf("-");
      }
      print_list(headR);
      printf("\n");
    }
      break;

            
      case '-':
      {
        if(swap == 0){
         /*normal subtraction*/
<<<<<<< HEAD
        //  puts("Do without swap");
        if(subtraction(tail1,tail2,&headR,&tailR)== FAILURE){
          return FAILURE;
        }
        if( ((d_oper1=='-' && d_oper2 == '+') ||(d_oper1=='-' && d_oper2 == '-') ) && headR != NULL){
          printf("-");
        }
      
        if(headR == NULL){
          printf("0\n");
          return SUCCESS;
        }

=======
         puts("Do without swap");
        if(subtraction(tail1,tail2,&headR,&tailR)== FAILURE){
          return FAILURE;
        }
        if((d_oper1=='-' && d_oper2 == '+') ||(d_oper1=='-' && d_oper2 == '-') ){
          printf("-");
        }
>>>>>>> 9f6d74998bdfb0f48c6c00d7f220b48741cfeb51
          print_list(headR);
        }
        /* len1 < len 2 */
        if(swap)
        {
          if(subtraction(tail2,tail1,&headR,&tailR)== FAILURE)
          {
            return FAILURE;
          }
<<<<<<< HEAD
          if(headR != NULL)
=======
>>>>>>> 9f6d74998bdfb0f48c6c00d7f220b48741cfeb51
          printf("-");
          print_list(headR);
        }
        printf("\n");
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