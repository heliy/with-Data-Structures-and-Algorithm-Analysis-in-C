#include"linkedlist.h"

typedef int element_type;

LINK commen(LINK L1,LINK L2)
{
  LINK C;
  position p;
  for(p=L1->next;p!=NULL;p=p->next){
    if(find(p->element,L2)!=NULL)
      insert(p->element,C,C)
  }
  return C;
}
