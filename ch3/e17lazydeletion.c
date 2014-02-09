#include"linkedlist.h"

struct node{
  int is_delete;
  element_type element;
  node_ptr next;
};

void lazy_delete(element_type x,LIST L)
{
  position p=find(x,L);
  p->is_delete=1;
}

void traverse(LIST L)
{
  positon p;
  for(p=L->next;p!=NULL;p=p->next){
    if(p->is_delete==1)
      delete(x,L);
  }
}
