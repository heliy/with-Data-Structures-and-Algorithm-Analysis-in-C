#include"linkedlist.h"
#include<stdio.h>

typedef int element_type;

void print_lots(LIST L,LIST P)
{
  position loc,ptr;
  int i;
  for(i=0,loc=L->next,ptr=P->next;loc!=NULL&&ptr!=NULL;loc=loc->next,i++){
    if(i==ptr->element){
      ptr=ptr->next;
      printf("%d\n",loc->element);
    }
  }
}
