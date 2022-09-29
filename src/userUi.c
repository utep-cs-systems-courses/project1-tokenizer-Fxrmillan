#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"
int main(){

 char *tempString;
 List *head = init_history();
 unsigned int numberInp;
do {
   puts("> press Q to exit h for history and ! for specific history");
   tempString = malloc(sizeof(char)*40);
   fgets(tempString, 50, stdin);
  if(*tempString == 'h' && tempString[1] == '\n' ){
     printf("PRINTING HISTORY\n");
     print_history(head);
   }
   else if(*tempString == '!'){
     printf("PRINTING SELECTED STRING\n");
     numberInp =(tempString[1] - '0');
     printf("%s\n", get_history(head,numberInp));
   }
   else if(*tempString != 'Q'){
   add_history(head,tempString);
   char **tokens = tokenize(tempString);
   print_tokens(tokens);
   free_tokens(tokens);
   }
   } while(*tempString != 'Q');
 free_history(head);
 }
