#include<stdio.h>
#include <stdlib.h> 
int space_char(char c){
  return c == ' ' ? 1:0;
}

int non_space_char(char c){
  return c != ' ' && c != '\0' ? 1:0;
}

char *word_start(char *str){
  if(non_space_char(*str))
    return str;
  else
    return 0;
      
}
 char *word_terminator(char *word){
   char* tempStr = word;
   while (*word  != '\0'){
    word+=1;
  }
  return word;
}

int count_words(char *str){
  int counter =1;
  while(*str != '\0' ){
    counter += space_char(*str);
    str +=1;
  }
  return counter;
}

char *copy_str(char *inStr, short len){
  char *ptr = malloc((len+1) * sizeof(char));
  for(int count =0; count < len;count++){
    ptr[count] = inStr[count];
   }
  ptr[len+1] = '\0';
  
   return ptr;
}

char **tokenize(char* str){
  int totalWords =1;
  totalWords =count_words(str);
  char **tokenAr = malloc(( totalWords+1) * sizeof(char*));
  int count =0;
  char* tempStr = str;
  for(count =0; count < totalWords;++count){
    int len = 0;
    while(non_space_char(*tempStr)){
      len +=1;
      tempStr +=1;
    }
    tempStr +=1;
    if(*str == '\0')
      break;
    tokenAr[count]  = copy_str(str,len);
    str = tempStr;
  }
  tokenAr[count] = "0";
  return tokenAr;

}

void print_tokens(char **tokens){
   while(**tokens !='0' )
    {
     printf("%s\n",*tokens);
     tokens += 1;
    }
  // printf("%s",*tokens);
}

void free_tokens(char **tokens){
  while(**tokens != '0')
    {
      free(*tokens);
      tokens += 1;
    }
  free(*tokens);

}



