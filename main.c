/**********************************************************************************************************************************************************
Name :         K.R.Gowtham

Project Title :  Arbitrary Precision Calculator

Description:       The Arbitrary Precision Calculator (APC) performs arithmetic operations on very large numbers.
                Most calculators are limited by the size of built-in data types, so they cannot handle numbers beyond a 
                fixed range. APC removes this limit by storing each number as a doubly linked list of digits, which lets
                it work with numbers of any length. It supports addition, subtraction, multiplication, and division, and
                it handles positive and negative numbers.

Input :       ./a.out <operand1> <operator> <operand2>

Operation :   Addition(+)
              Subtraction(-)
              Multiplication(x)
              Division(/)

    
Output :      SUCCESS
              FAILURE


Return Value: SUCCESS the operation completely done
              FAILURE any memory allocation failure 



***********************************************************************************************************************************************************/


<<<<<<< HEAD
#include "apc.h"


   
=======
#include "apc.h" 
>>>>>>> 464f81a (8:22 27-10-26)
static int add_zeros(node **head,node **tail,int len){
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



int main(int argc,char *argv[])
{
  
  /*verify user valid operator and operand*/
  if(cla_validation(argc,argv) == FAILURE)
  {
    return FAILURE;
  }
  
  /*Decleare a linked list */
  node *head1 = NULL,*tail1 = NULL,*head2 = NULL,*tail2 = NULL,*headR = NULL,*tailR = NULL;
  

  int len1;
  /* create a list for operand 1 at the same time return a length */
  if( (len1 = create_list(argv[1],&head1,&tail1)) == FAILURE)
  {
    return FAILURE;
  }
  

  char d_oper1  = ' ';
  if(argv[1][0] == '+' || argv[1][0] == '-')
  {
    d_oper1 = argv[1][0];
  }
  
 
  int len2;
  /* create a list for operand 2 at the same time return a length */
  if( (len2 = create_list(argv[3],&head2,&tail2)) == FAILURE)
  {
    delete_list(&head1,&tail1);     
    return FAILURE;
  }

  char d_oper2 = ' ';
  if(argv[3][0] == '+' || argv[3][0] == '-')
  {
    d_oper2 = argv[3][0];
  }
  

  char operation;
  short not_same_sign = 0,swap = 0,neg_num = 0;
  
  /* get inside the if do the operation addition or subtraction */
  if(argv[2][0] == '-' || argv[2][0] == '+')
  {
    /* the input operand is a different sign  and operation is addition  but do the subtraction */
    if(((d_oper1 == '+' && d_oper2 == '-') || (d_oper1 == '-' && d_oper2 == '+') || (d_oper1 == '-' && d_oper2 == ' ') || (d_oper1 == ' ' && d_oper2 == '-') ) && (argv[2][0] == '+') )
    {
      not_same_sign = 1;
    }
    /* the input operand is a different sign  and operation is subtraction  but do the addition */
    if( ((d_oper1 == '+' && d_oper2 == '-') || (d_oper1 == '-' && d_oper2 == '+')  || (d_oper1 == '-' && d_oper2 == ' ') || (d_oper1 == ' ' && d_oper2 == '-') )&& (argv[2][0] == '-') )
    {
      not_same_sign = 2;
    }
    
    /* do the addition operation */
    if( ((d_oper1 == '+' && d_oper2 == '+') || (d_oper1 == '-' && d_oper2 == '-') ||(d_oper1 == ' ' && d_oper2 == ' ') ||(d_oper1 == '+' && d_oper2 == ' ') || (d_oper1 == ' ' && d_oper2 == '+') )  || not_same_sign == 2)
    {
      if((head1 == NULL && head2 != NULL) && (argv[2][0] == '+' ) )         /*1st operand is empty or contains zero only print the second list*/
      {
        if(d_oper2 == '-')
        {
          putchar(d_oper2);
        }
        print_list(head2);                                                   /*print list      */
        delete_list(&head2,&tail2);                                          /*delete the list */
        return SUCCESS;
      }else if( (head2 == NULL && head1 != NULL) && (argv[2][0] == '+'))     /*2nd operand is empty or contains zero only print the first list*/
      {
        if(d_oper1 == '-'){
          putchar(d_oper1);
        }
         print_list(head1);                                                  /*print the list*/ 
        delete_list(&head1,&tail1);                                          /*delete the list*/
        return SUCCESS;
      }else if( (head1 ==  NULL && head2 == NULL) && (argv[2][0] == '+' ||  operation == '+') )/* both operand contain zero print the zero */
      {
        printf("0\n");
        return SUCCESS;
      }
      
      /* compare the 2 operand the length */
      if(len1 > len2)
      {
        if(head1 != NULL)
        {
          len2 = len1 - len2;
          if(add_zeros(&head2,&tail2,len2) == FAILURE)                            /*add the zeros to first to 2nd operand */
          {
            return FAILURE;
          }
        }
      }else if(len1 < len2)
      {
        if(head2 != NULL)
        {
          len1 = len2 - len1;
          if(add_zeros(&head1,&tail1,len1) == FAILURE)                            /* add the zeros to first to 1st operand */
          {
            return FAILURE;
          }
        }
      }
    }
    
    /*do the subtraction */
    if((d_oper1 == '+' && d_oper2 == '+') || (d_oper1 == '-' && d_oper2 == '-') || (d_oper1 == ' ' && d_oper2 == ' ') || not_same_sign == 1)
    {
      
      if(head1 == NULL && head2 != NULL)                                /* 1st operand is empty or contains zero only print the second list*/
      {
        if((d_oper2 == '-') && argv[2][0] != '-')
        {
          printf("-");
        }
        print_list(head2);                                              /* print the list   */
        delete_list(&head2,&tail2);                                     /* delete the list */
        return SUCCESS;
      }else if(head1 != NULL && head2 == NULL)                           /* 2nd operand is empty or contains zero only print the first list*/
      {
        printf("%s\n",argv[1]);                                          /*print the list  */
        delete_list(&head1,&tail1);                                      /*delete the list */
        return SUCCESS;
      }else if (head1 == NULL && head2 == NULL)                          /* both operand contain zero print one zero */                        
      {
        printf("0\n");
        return SUCCESS;
      }
      


      if(len1 > len2 )                                                  /*operand 1 is greater than operand 2 do the normal subtraction */
      {
        swap = 0;
      }else if(len1 < len2)                                              /*operand 2 is greater than operand 1 do the swaping subtraction */
      {
        swap = 1;
      }else if(len1 == len2)                                            /*both operand are same length  check the every data if operand 1 is grater than operand 2 do normal subtraction  operand 2 is greater than operand 1 swaping subtraction*/
      {
        node *h1 = head1;
        node *h2 = head2;
        swap = 0;
        
        while(h1 != NULL && h2 != NULL)                                  /*check the every data */
        {
          if((h1->data > h2->data))
          {
            swap = 0;
            break;
          }else if ((h1->data < h2->data))
          {
            swap = 1;
            break;
          }
          h1 =  h1->next;
          h2 = h2->next;
        }
      }
    }

    if(swap == 1 && (d_oper1 == '-' && d_oper2 == '+') || (d_oper1 == '-' && d_oper2 == ' ') || (d_oper1 == '-' && d_oper2 == '-') )
    {
      neg_num = 1;
    }
  
  }
  
  
  
  /* assign a which operation can do */

  /* addition */
  if(argv[2][0] == '+' || not_same_sign == 2)
  {
    operation = '+';
  }
  
  /* subtraction */
  if(argv[2][0] == '-' || not_same_sign == 1)
  {
    operation = '-';
  }
  
  /*multiplication */
  if(argv[2][0] == 'x' || argv[2][0] == 'X' ||  argv[2][0] == '*'  )
  {
    operation = '*';
  }
  
  /*division */
  if(argv[2][0] == '/'  )
  {
    operation = '/';
  }
  
  
  /* any one operand contain zero  during multiplication output has zero */
  if( (head1 == NULL || head2== NULL) && operation == '*')
  {
    printf("0\n");
    delete_list(&head2,&tail2);
    delete_list(&head1,&tail1);
    return SUCCESS;
  }
  
  /* 1st operand contain zero output also zero */
  if((head1 == NULL && head2 != NULL) && operation == '/')
  {
    printf("0\n");
    delete_list(&head2,&tail2);
    return SUCCESS;
  }
  
  /*2nd operand contain only zero cannot divided by 0*/
  if((head1 != NULL && head2 == NULL) && operation == '/')
  {
    printf("Error: Division by zero is undefined.\n");
    delete_list(&head2,&tail2);
    return SUCCESS;
  }
  
  
  
  /*which operation will do can choose */
  switch (operation)
  {
    
    /* addition operation */
    case '+':
    {
      if(addition(tail1,tail2,&headR,&tailR) == FAILURE){
            delete_list(&headR,&tailR);                                    /* delete lists */
            delete_list(&head2,&tail2);
            delete_list(&head1,&tail1);
          return FAILURE;
      }
          
          
      /*any one operand contain subtraction output also zero */
      if((d_oper1 == '-' && d_oper2 == '-') || (d_oper1 == '-' && d_oper2 == '+') || (d_oper1 == '-' && d_oper2 == ' ') )
        printf("-");

      print_list(headR);                                                    /* print the output */
      delete_list(&headR,&tailR);                                           /* delete the list */
      delete_list(&head2,&tail2);
      delete_list(&head1,&tail1);
     }
      break;
      
      /*subtraction operation */
      case '-':
      {
        if(swap == 0)
        {
          if(subtraction(tail1,tail2,&headR,&tailR)== FAILURE){                  /* do the subtraction without swaping the operand */
            delete_list(&headR,&tailR);                                          /* delete the list */
            delete_list(&head2,&tail2);
            delete_list(&head1,&tail1);
              return FAILURE;
          }
              
          if( ((d_oper1 == '-' && d_oper2 == '+') || (d_oper1 == '-' && d_oper2 == '-') || (d_oper1 == '-' && d_oper2 == ' ') ) && headR != NULL)
              printf("-");
          
          if(headR == NULL)
          {
            printf("0\n");
            delete_list(&head2,&tail2);                                             /*delete the list */
            delete_list(&head1,&tail1);
            return SUCCESS;
          }

          print_list(headR);                                                       /* print the list */
          delete_list(&headR,&tailR);                                              /* delete the list */
          delete_list(&head2,&tail2);
          delete_list(&head1,&tail1);
          
          return SUCCESS;
        } 

        if(swap)                                                                     /*do the subtraction with swaping the operand  */
        {
          if(subtraction(tail2,tail1,&headR,&tailR) == FAILURE){
            delete_list(&headR,&tailR);                                              /*delete the list */
            delete_list(&head2,&tail2);
            delete_list(&head1,&tail1);   
            return FAILURE;
          }
          
          if( (neg_num == 0) && ( ( (d_oper1 == '-' && d_oper2 == '+') || (d_oper1 == '-' && d_oper2 == '-') || (d_oper1 == '-' && d_oper2 == ' ') || (d_oper1 == '+' && d_oper2 == '+') || (d_oper1 == ' ' && d_oper2 == ' ') || (d_oper1 == ' ' && d_oper2 == '-')) && headR != NULL) )
            printf("-");

          print_list(headR);                                                          /*print the list */
          delete_list(&headR,&tailR);                                                 /*delete the list */
          delete_list(&head2,&tail2);
          delete_list(&head1,&tail1);
          
          return SUCCESS;
        }
      }
        break;
      
      /* multiplication operation */
      case '*':
      case 'X':
      case 'x':
        {
          if(multiplication(tail1,tail2,&headR,&tailR)== FAILURE){
            delete_list(&headR,&tailR);                                               /* delete the list */
            delete_list(&head2,&tail2);
            delete_list(&head1,&tail1);
            return FAILURE;
          }
          
          if( (d_oper1 == '-' && d_oper2 == ' ') ||(d_oper1 == ' ' && d_oper2 == '-') || (d_oper1 == '-' && d_oper2 == '+')||(d_oper1 == '+' && d_oper2 == '-')    ){
            printf("-");
          }
            print_list(headR);                                                           /* print the output */
            delete_list(&headR,&tailR);                                                  /* delete the list */
            delete_list(&head2,&tail2);
            delete_list(&head1,&tail1);
          return SUCCESS;
        }
        break;
        
      
      /*division operation */
      case '/':
        {
          if(division(head1,tail1,head2,tail2,&headR,&tailR) == FAILURE){
            delete_list(&headR,&tailR);                                              /* delete the list */
            delete_list(&head2,&tail2);
            delete_list(&head1,&tail1);
            return FAILURE;
          }
          if( ((d_oper1 == '-'&& d_oper2 == ' ') || (d_oper1 == ' '&& d_oper2 == '-') || (d_oper1 == '-'&& d_oper2 == '+')||(d_oper1 == '-'&& d_oper2 == '+'))){
           if((headR->data != 0) )
            printf("-");
          }
          print_list(headR);
          delete_list(&headR,&tailR);                                              /* delete the list */
          delete_list(&head2,&tail2);
          delete_list(&head1,&tail1);
        }
        break;
      }
      return 0;
    }



 
