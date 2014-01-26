#include"linkedlist.h"
#include<stdio.h>

typedef int element_type;

void printlinkedlist(LIST L)
{
  position p;
  for(p=L->next;p!=NULL;p=p->next)
    printf("%d\n",p->element);
}
