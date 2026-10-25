#include "apc.h"
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
  
  if(argv[2][0] == '-' || argv[2][0] == '+')
  {
    if(((d_oper1 == '+' && d_oper2 == '-') || (d_oper1 == '-' && d_oper2 == '+') || (d_oper1 == '-' && d_oper2 == ' ') || (d_oper1 == ' ' && d_oper2 == '-') ) && (argv[2][0] == '+') )
    {
      not_same_sign =1;
    }
    
    if(  ((d_oper1 == '+' && d_oper2 == '-') || (d_oper1 == '-' && d_oper2 == '+')  || (d_oper1 == '-' && d_oper2 == ' ') || (d_oper1 == ' ' && d_oper2 == '-') )&& (argv[2][0] == '-') )
    {
      not_same_sign = 2;
    }
    
    if( ((d_oper1 == '+' && d_oper2 == '+') || (d_oper1 == '-' && d_oper2 == '-') ||(d_oper1 == ' ' && d_oper2 == ' ') ||(d_oper1 == '+' && d_oper2 == ' ') || (d_oper1 == ' ' && d_oper2 == '+') )  || not_same_sign == 2)
    {
 

      if(argv[2][0] == '+' || not_same_sign == 2)
      {
        operation = '+';
      }
      
      // puts("condition check");
      if((head1 == NULL && head2 != NULL) && (argv[2][0] == '+' ) )
      {
        // printf("List 1 empty");
        if(d_oper2 == '-'){
          putchar(d_oper2);
        }
        print_list(head2);
        printf("\n");
        delete_list(&head2,&tail2);
        return SUCCESS;
      }else if( (head2 == NULL && head1 != NULL) && (argv[2][0] == '+'))
      {
        // printf("List 2 empty");
        if(d_oper1 == '-'){
          putchar(d_oper1);
        }
         print_list(head1); 
        delete_list(&head1,&tail1); 
        printf("\n" );
        return SUCCESS;
      }else if(head1 ==  NULL && head2 == NULL && (argv[2][0] == '+' ||  operation == '+') )
      {
        printf("0\n");
        return SUCCESS;
      }
      
      if(len1 > len2)
      {
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
    
    if((d_oper1 == '+' && d_oper2 == '+') || (d_oper1 == '-' && d_oper2 == '-') || (d_oper1 == ' ' && d_oper2 == ' ') || not_same_sign == 1)
    {
      if(argv[2][0] == '-' || not_same_sign == 1)
      {
        operation = '-';
      }
      
      if(head1 == NULL && head2 != NULL)
      {
        //  if((d_oper2 != '-') && argv[2][0] == '-')
        if((d_oper2 == '-') && argv[2][0] != '-')
        {
          printf("-");
        }
        print_list(head2);
        delete_list(&head2,&tail2);
        return SUCCESS;
      }else if(head1 != NULL && head2 == NULL)
      {
        printf("%s\n",argv[1]);
        delete_list(&head1,&tail1);
        return SUCCESS;
      }else if (head1 == NULL && head2 == NULL)
      {
        printf("0\n");
        return SUCCESS;
      }
      
      if(len1 > len2 )
      {
        swap = 0;
      }else if(len1 < len2)
      {
        swap = 1;
      }else if(len1 == len2)
      {
        node *h1 = head1;
        node *h2 = head2;
        swap = 0;
        
        while(h1 != NULL && h2 != NULL)
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
  
  
  
  if(argv[2][0] == 'x' ||argv[2][0] == 'X'||argv[2][0] == '*'  )
  {
    operation = '*';
  }
  
  if(argv[2][0] == '/'  )
  {
    operation = '/';
  }
  
  
  if( (head1 == NULL || head2== NULL) && operation == '*')
  {
    printf("0\n");
    delete_list(&headR,&tailR);
    delete_list(&head2,&tail2);
    delete_list(&head1,&tail1);
         
   
    return SUCCESS;
  }
  
  if((head1 == NULL && head2 != NULL) && operation == '/')
  {
    printf("0\n");
    delete_list(&head2,&tail2);
    return SUCCESS;
  }
  
  if((head1 != NULL && head2 == NULL) && operation == '/')
  {
    printf("Error: Division by zero is undefined.\n");
    delete_list(&head2,&tail2);
    return SUCCESS;
  }
  
  
  
  
  switch (operation)
  {
    
    case '+':
    
    {
      
      if(addition(tail1,tail2,&headR,&tailR) == FAILURE){
        delete_list(&headR,&tailR);
            delete_list(&head2,&tail2);
            delete_list(&head1,&tail1);
          return FAILURE;
      }
          
          
      if((d_oper1 == '-' && d_oper2 == '-') || (d_oper1 == '-' && d_oper2 == '+') || (d_oper1 == '-' && d_oper2 == ' ') )
        printf("-");

      print_list(headR);
     }
      break;
      
      case '-':
      {
        
        if(swap == 0)
        {
          if(subtraction(tail1,tail2,&headR,&tailR)== FAILURE){
            delete_list(&headR,&tailR);
            delete_list(&head2,&tail2);
            delete_list(&head1,&tail1);
              return FAILURE;
          }
              
          if( ((d_oper1 == '-' && d_oper2 == '+') || (d_oper1 == '-' && d_oper2 == '-') || (d_oper1 == '-' && d_oper2 == ' ') ) && headR != NULL)
              printf("-");
          
          if(headR == NULL)
          {
            printf("0\n");
            delete_list(&headR,&tailR);
            delete_list(&head2,&tail2);
            delete_list(&head1,&tail1);
            return SUCCESS;
          }
          print_list(headR);
          delete_list(&headR,&tailR);
          delete_list(&head2,&tail2);
          delete_list(&head1,&tail1);
          
          return SUCCESS;
        } 
        if(swap)
        {
          if(subtraction(tail2,tail1,&headR,&tailR) == FAILURE){
            delete_list(&headR,&tailR);
            delete_list(&head2,&tail2);
            delete_list(&head1,&tail1);   
            return FAILURE;
          }
          
          if( (neg_num == 0) && ( ( (d_oper1 == '-' && d_oper2 == '+') || (d_oper1 == '-' && d_oper2 == '-') || (d_oper1 == '-' && d_oper2 == ' ') || (d_oper1 == '+' && d_oper2 == '+') || (d_oper1 == ' ' && d_oper2 == ' ') || (d_oper1 == ' ' && d_oper2 == '-')) && headR != NULL) )
                  printf("-");

          print_list(headR);
          delete_list(&headR,&tailR);
          delete_list(&head2,&tail2);
          delete_list(&head1,&tail1);
          
          return SUCCESS;
        }
      }
        break;
        
        case '*':
        case 'X':
        case 'x':
        {
          if(multiplication(tail1,tail2,&headR,&tailR)== FAILURE){
            delete_list(&headR,&tailR);
            delete_list(&head2,&tail2);
            delete_list(&head1,&tail1);
            return FAILURE;
          }
          if( (d_oper1 == '-' && d_oper2 == ' ') ||(d_oper1 == ' ' && d_oper2 == '-') || (d_oper1 == '-' && d_oper2 == '+')||(d_oper1 == '+' && d_oper2 == '-')    ){
            printf("-");
          }
            print_list(headR);
            delete_list(&headR,&tailR);
            delete_list(&head2,&tail2);
            delete_list(&head1,&tail1);
          return SUCCESS;
        }
        break;
        
        case '/':
        {
          if(division(head1,tail1,head2,tail2,&headR,&tailR) == FAILURE){
            delete_list(&headR,&tailR);
            delete_list(&head2,&tail2);
            delete_list(&head1,&tail1);
            return FAILURE;
          }
          print_list(headR);
        }
        break;
      }
      return 0;
    }



