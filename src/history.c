#include "history.h"
#include <stdio.h>
#include <stdlib.h>
List* init_history(){
   List *headPtr = malloc(sizeof(List));
  headPtr ->root = NULL;
  return headPtr;
}

void add_history(List *list, char *str){
  Item *listPtr = list->root;
  if(listPtr == NULL){
    Item *headData = malloc(sizeof(Item));
    headData ->id = 0;
    headData ->str = str;
    headData ->next = NULL;
    list->root = headData;
  }
  else{
  while( listPtr->next != NULL){
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
  Item *listPtr = list->root;
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




