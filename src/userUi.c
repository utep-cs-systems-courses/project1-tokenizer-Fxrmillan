#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"
int main(){

 char *tempString;
 List *head = init_history();
 // add_history(head,"DAVE\n");
 // add_history(head,"STEVE\n");
 // char*temp = get_history(head,3);
 // printf("%s",temp);
 // print_history(head);

 
 
do {
   puts(">");
   tempString = malloc(sizeof(char)*40);
   fgets(tempString, 50, stdin);
   add_history(head,tempString);
   char **tokens = tokenize(tempString);
   print_tokens(tokens);
   free_tokens(tokens); 
 } while(*tempString != '!');
 print_history(head);
 free_history(head);

 
 }
