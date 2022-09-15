#include<stdio.h>
int space_char(char c){
  return c == ' ' ? 1:0;
}

int non_space_char(char c){
  return c != ' ' && c != '\0' ? 1:0;
}

char *word_start(char *str){
  
  char *tempStr = str;
   while(non_space_char(*str)){
    str += 1;
  }
   
  if(space_char(*str)){
      return str+=1;
  }
  else if(*str == '\0')
  {
      return tempStr;
  }
    return 0;
}

