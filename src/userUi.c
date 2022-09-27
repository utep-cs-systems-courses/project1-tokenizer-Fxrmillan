#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"
int main(){

 char *tempString;
 List *head = init_history();
 int numberInp;
 // add_history(head,"DAVE\n");
 // add_history(head,"STEVE\n");
 // char*temp = get_history(head,3);
 // printf("%s",temp);
 // print_history(head);

 
 
do {
   puts(">");
   tempString = malloc(sizeof(char)*40);
   fgets(tempString, 50, stdin);
   if(*tempString != '!'){
   add_history(head,tempString);
   char **tokens = tokenize(tempString);
   print_tokens(tokens);
   free_tokens(tokens);
   }
 } while(*tempString != '!');
 print_history(head);
 // free_history(head);
 do{
   puts("> search history press -1 to exit");
   scanf("%d",&numberInp);
   if(numberInp == -1){
     break;
   }
   char *temp = get_history(head,numberInp);
   printf("%s\n",temp);


 }while(1);
 free_history(head);
 }
