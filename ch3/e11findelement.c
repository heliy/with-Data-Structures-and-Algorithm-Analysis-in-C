#include<stdio.h>
#include"linkedlist.h"

typedef int element_type;

//iterative??
position find_recu(element e,LIST L)
{
  if(L==NULL)
    return;
  if(L->element=e){
    return L;
  }
  find_recu(L->next);
}

position find_nonrecu(element e,LIST L)
{
  position p;
  for(p=L;p!=NULL;p=p->next){
    if(p->element==e)
      return p;
  }
  return NULL;
} 
