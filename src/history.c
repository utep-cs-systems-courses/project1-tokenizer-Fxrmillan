#include "history.h"
#include <stdio.h>
#include <stdlib.h>
List* init_history(){
  Item *HeadData = malloc(sizeof(Item));
  List *headPtr = malloc(sizeof(List));
  char *headStr = malloc(sizeof(char));
  HeadData->id = 0;
  HeadData->str= headStr;
  HeadData->next = NULL;
  headPtr ->root = HeadData;
  printf("%s",headPtr->root->str);
  return headPtr;
}

void add_history(List *list, char *str){
  Item *listPtr = list->root;
  while(listPtr->next != NULL){
    listPtr = listPtr->next;
  }
  Item *tempData = malloc(sizeof(Item));
  tempData ->id = listPtr->id + 1;
  // printf("%d",tempData -> id);
  tempData->str = str;
  // printf("%s",tempData->str);
  tempData->next = NULL;
  listPtr->next = tempData;
  // printf("%s",listPtr->next->str);
}

char *get_history(List *list, int id){
  Item *listPtr = list->root;
  while(listPtr != NULL){
    if(listPtr->id == id){
      return listPtr ->str;
    }
    listPtr = listPtr->next;
  }

}

void print_history(List *list){
  Item *listPtr = list->root->next;
  while(listPtr!= NULL){
    printf("%s",listPtr->str);
    listPtr = listPtr ->next;
  }
}

void free_history(List *list){
  Item *listPtr = list->root;
  Item *temp;
  while(listPtr != NULL){
    temp = listPtr;
    free(temp->str);
    listPtr = listPtr->next;
    free(temp);
  }
  free(list);

}




