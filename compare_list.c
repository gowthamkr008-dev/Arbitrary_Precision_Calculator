#include"apc.h"



int compare_list(node *head1,node *head2){

  uint len1 =list_length(head1);
  uint len2 = list_length(head2);
  node * h1 = head1;
  node *h2 = head2;
  // printf("len1 %d\nlen2 %d",len1,len2);

  if(len1 < len2 ){
    return -1;
  }else if(len1 > len2){
    return 1;
  }else{
    while(head1 != NULL && head2 != NULL){
      if(head1->data > head2->data){
        return 1;
      }else if(head1->data < head2->data){
        return -1;
      }
      head1 = head1->next;
      head2 = head2->next; 
    }
    return 0;
  }
  

}