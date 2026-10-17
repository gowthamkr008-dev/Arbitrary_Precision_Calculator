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