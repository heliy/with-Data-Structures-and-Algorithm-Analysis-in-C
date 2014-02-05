#include"linkedlist.h"

void reverse(LIST L)
{
  position prev,next;
  for(prev=NULL,next=L->next;next!=NULL;prev=next,next=next->next){
    next->next=prev;
  }
  L->next=prev;
}

