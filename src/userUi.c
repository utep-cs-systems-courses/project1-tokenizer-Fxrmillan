#include <stdio.h>
#include "history.h"
#include "tokenizer.h"
int main(){

  puts("test Monkey");
 int test = space_char('c');
 char temp;
 while (temp != '\n'){
   scanf("%c",&temp);
   test = non_space_char(temp);
   printf("%d\n",test);
 }
 puts("done");

 char tempString[] = "temp string\0";
 char *ptr = word_start(tempString);
 
 while (*ptr != '\0'){
   printf("%c\n",*ptr);
   ptr += 1;
 }
 
 }
