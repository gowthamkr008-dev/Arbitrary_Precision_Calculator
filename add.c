#include "apc.h"

void addition(node *tail1, node *tail2, node **headR, node **tailR)
{
  int sum,carry =0;
  
  while(tail1 != NULL && tail2 != NULL)
  {
    
    sum = (tail1->data) + (tail2->data) + carry;
    printf("%d + %d + %d  = %d\n", tail1->data,  (tail2->data),carry,sum);
    if(sum > 9)
    {
      carry = 1;
      sum = (sum)%10;
      // printf("\n%d\n",sum);
      }
      else
      {
        carry =0;
      }
      if(insert_first(headR,tailR,sum) ==  FAILURE){
        return FAILURE;
      }
      tail1 = tail1->prev;
      tail2 = tail2->prev;
    }
    if(carry)
    {
      if(insert_first(headR,tailR,sum) ==  FAILURE)
      {
        return FAILURE;
      }
    }
  }


/*

Addition

input
  ./a.out   1234 +   543221

     head1->  1 <-> 2 <-> 3 <-> 4 <-> 5 < tail 1 
     head2->  6 <-> 4 <-> 2 <-> 1 <-> 2 < tail 2
     ----------------------------------------------
  reshea->                                 <- restail


  no need of temp ptr for travers   tail != NULL    use this

  sum = t1 +t2 ;
  insert_first(resh,rest,sum)
  t1 = t1->prev;
  t2 = t2->pre;



  ./a.out  1234 + 56789

  do with the cary

  when sum > 9 carry became 1
  if sum not greater than carry became 0

  when the carry availabe after get of the loop if check the carry available insert first the carry

  if(carry){
  insert(carry) //insert carry to 
  }
check the no of digit
if not same which the 

if not same no of digit
1 2 3 4 5 
    1 2 3 
 
    adding the zero
    for less length 0 0 1 2 3 


*/

