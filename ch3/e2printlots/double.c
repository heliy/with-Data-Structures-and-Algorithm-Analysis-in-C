#include"doublelinkedlist.h"

typedef int element_type;

void swap(DLIST L,position p1,position p2)
{
  position tmpprev,tmpnext;
  p1->prev=p2;
  tmpnext=p2->next;
  tmpprev=p2->prev;
  p2->next=p1->next;
  p2->prev=p1->prev;
  p2->next=p1->next;
  p2->next->prev=p2;

  tmpprev->next=p1;
  p1->prev=tmpprev;
  p1->next=tmpnext;
  tmp->next->prev=p1;
}
