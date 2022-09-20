#include<stdio.h>
#include <stdlib.h> 
int space_char(char c){
  return c == ' ' || c == '\t' ? 1:0;
}

int non_space_char(char c){
  return c != ' ' && c != '\0' ? 1:0;
}

char *word_start(char *str){
  while(space_char(*str)){
      str+=1;
    }
   if(*str == '\0'){
     printf( "str is NULL ");
      return 0;
   }
    else
      return str;
      
}
 char *word_terminator(char *word){
   while (non_space_char(*word)){
    word+=1;
  }
  return word;
}

int count_words(char *str){
  int counter =0;
  while(*str != '\0' ){
    str = word_start(str);
    str = word_terminator(str);
    counter++;
  }
  return counter;
}

char *copy_str(char *inStr, short len){
  char *ptr = malloc((len+1) * sizeof(char));
  for(int count =0; count < len ;count++){
    ptr[count] = inStr[count];
     }
  ptr[len] = '\0';
  return ptr;
}

char **tokenize(char* str){
  int totalWords =0;
  totalWords =count_words(str);
  printf("%s%d\n","words: ", totalWords);
  char **tokenAr = malloc((totalWords+1) * sizeof(char*));
  for(int count = 0; count < totalWords;count++){
  char* start = word_start(str);
  char* end = word_terminator(start);
  unsigned int len =  end - start;
  tokenAr[count] = copy_str(start,len);
  str = end;
  }
  tokenAr[totalWords] = "0";
  return tokenAr;
  
}

void print_tokens(char **tokens){
   while(**tokens !='0' )
    {
     printf("%s\n",*tokens);
     tokens += 1;
    }
  printf("%s\n",*tokens);
}

void free_tokens(char **tokens){
  int count = 0;
   while(*tokens[count] != '0')
    {
      free(tokens[count]);
      count++;
    }
   free(tokens);
  }
