#include"linkedlist.h"

typedef int element_type;

void swap(LINK L,position p1,position p2)
{
  position prev1,prev2,tmp;
  for(prev1=L;p1!=prev1->next;prev1=prev1->next);
  for(prev2=L;p2!=prev2->next;prev2=prev2->next);
  prev1->next=p2;
  tmp=p2->next;
  p2->next=p1->next;
  prev2->next=p1;
  p1->next=tmp;
}
