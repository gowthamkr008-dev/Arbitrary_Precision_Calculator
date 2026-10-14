#include"apc.h"

int create_list(char *oper,node **head,node **tail){
  int i=0;
  while(oper[i] != '\0'){
    if(insert_last(head,tail,oper[i]-'0') == FAILURE){
      return FAILURE;
    }
    i++;
  }
 
}