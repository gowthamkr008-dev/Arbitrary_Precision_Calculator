
#include "apc.h"

int main(int argc, char *argv[])
{
	node *head1 = NULL, *tail1 = NULL, *head2 = NULL, *tail2 = NULL, *headR = NULL, *tailR = NULL;
	
	if(cla_validation(argc, argv) ==FAILURE)                                                         //check the input user gave proper or not
	{
			return 1;
		}

		if(create_list(argv[1],&head1,&tail1) == FAILURE){                                              //create a list 1 and store
			return FAILURE;
		}                                                         
		printf("Operand 1 :  ");
		print_list(head1);                                                                              //print list properly creater or not
		printf("\n");

		if(create_list(argv[3],&head2,&tail2) == FAILURE){                                              //create a list 2 and store
			return FAILURE;
		}
		printf("Operand 2 :  ");
		print_list(head2);                                                                                //print list properly creater or not
		printf("\n");
    // Validation


    // Create 2 lists of operands

    // Remove pre zeros
		if(remove_pre_zeros(&head1) == FAILURE){                                                            //in list 1 any pre zero is unwanted use this to remove
			return FAILURE;
		}
		print_list(head1);

		if(remove_pre_zeros(&head2) == FAILURE){                                                           //in list 2 any pre zero is unwanted use this to remove
			return FAILURE;
		}
		print_list(head2);   
		printf("\n\n");


		int len1,len2;                                                                                      
		len1 = list_len(head1);                                                                            //find number of digit in fitst operand
		len2 = list_len(head2);                                                                           //find number of digit in Second operand

		if(len1 == len2){                                                                                //the both length are equal do the next operations
			printf("len1 == len2 \n");
		}else if(len1 > len2){                                                                          //the operand 1 length is less then the operand 2 add the zero for 2nd operands
			len1 = (len1 -len2);
			add_zeros(&head2,&tail2,len1);
			printf("After Add zeros : ");
			print_list(head2); 
		}else{                                                                                         //the operand 1 length is greater then the operand 2 add the zero for 1st operands
			len2 = len2-len1;
			add_zeros(&head1,&tail1,len1);
			printf("After Add zeros : ");
			print_list(head2);
		}
		
		char oper = argv[2][0];
		
		switch(oper)
		{
			case '+':
					addition(tail1, tail2, &headR, &tailR);
					print_list(headR);
					printf("\n");
	    break;
			
			case '-':
	    break;
			
			case '*':
			case 'x':
			case 'X':
	    break;
			
			
			case '/':
	    break;
		
		}
		
		printf("Result : ");
		print_list(headR);

return SUCCESS;

	}

