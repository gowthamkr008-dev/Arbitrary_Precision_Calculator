
#include "apc.h"

int main(int argc, char *argv[])
{
    node *head1 = NULL, *tail1 = NULL, *head2 = NULL, *tail2 = NULL, *headR = NULL, *tailR = NULL;


		if(cla_validation(argc, argv) ==FAILURE){
			return 1;
		}

		create_list(argv[1],&head1,&tail1);
		 print_list(head1);
		printf("\n");
		create_list(argv[3],&head2,&tail2);
			 print_list(head2);
		printf("\n");
    // Validation


    // Create 2 lists of operands

    // Remove pre zeros

    char oper = argv[2][0];

    switch(oper)
    {
	case '+':
	    addition(tail1, tail2, &headR, &tailR);
	    break;

	case '-':
	    break;

	case 'x':
	case 'X':
	    break;

	case '/':
	    break;

	default:
	    printf("Invalid operator\n");
    }
}

