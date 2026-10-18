<<<<<<< HEAD
#include "apc.h"

int remove_pre_zeros(node **head,node **tail){
  if(*head == NULL){
        return 0;  // fail — empty list
    }

    // Check if any leading zeros exist
    if((*head)->data != 0){
        return 0;  // fail — no leading zeros found
    }

    // Remove leading zeros
    while(*head != NULL && (*head)->data == 0){
        node* temp = *head;
        *head = (*head)->next;
        if(*head != NULL){
            (*head)->prev = NULL;
        }
        free(temp);
    }

    return SUCCESS; 
}
=======
// #include "apc.h"

// int remove_pre_zeros(char *argv,char *opr){
//   int i = 0;
   
//   if(argv[i] == '+' || argv[i] == '-'){
//     i++;
//   }
//   while(argv[i] != '\0'){
//     if(argv[i] == '0'){
//       i++;
//     }else{
//       break;
//     }
//   }
//   int orglen = strlen(argv);
//   int len = (orglen - i)+1;
// //  /
//    int j =0;
//    if(argv[j] == '+' || argv[j] == '-'){
//     opr[j++] = argv[0];
//   }
//    while(argv[i] != '\0'){
//     opr[j++] = argv[i++];
//    }
//    opr[j] = '\0';
//   printf("%s\n",opr);
//   return SUCCESS; 
// }
>>>>>>> 9f6d74998bdfb0f48c6c00d7f220b48741cfeb51
