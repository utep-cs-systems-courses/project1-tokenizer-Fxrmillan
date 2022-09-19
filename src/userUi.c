#include <stdio.h>
#include "history.h"
#include "tokenizer.h"
int main(){

 puts("test Monkey");
 char tempString[25]; 
 do{
   scanf("%s",tempString);
   char **tokens = tokenize(tempString);
   print_tokens(tokens);
   free_tokens(tokens); 
 }while(*tempString != '!');
 }
