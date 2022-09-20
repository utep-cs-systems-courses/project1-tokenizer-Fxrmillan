#include <stdio.h>
#include "history.h"
#include "tokenizer.h"
int main(){

 puts("test Monkey");
 char tempString[55]; 
 do{
   puts(">");
   fgets(tempString, 50, stdin);
   char **tokens = tokenize(tempString);
   print_tokens(tokens);
   free_tokens(tokens); 
   }while(*tempString != '!');
 }
