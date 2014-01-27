#include"linkedlist.h"

typedef int element_type;

LINK lunion(LINK L1,LINK L2)
{
  position p;
  LINK U;
  for(p=L1->next;p!=NULL;p=p->next)
    if(find(p->element,U)==NULL)
      insert(p->element,U,U);
  for(p=L2->next;p!=NULL;p=p->next)
    if(find(p->element,U)==NULL)
      insert(p->element,U,U);
  return U;
}
