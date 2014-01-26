#include"doublelinkedlist.h"

typedef struct node * node_ptr;

struct node
{
  element_type element;
  node_ptr prev;
  node_ptr next;
};

typedef node_ptr DLIST;
typedef node_ptr position;

DLIST create(void)
{
  DLIST list=(DLIST) malloc(sizeof(struct node));
  DLIST->prev=NULL;
  DLIST->next=NULL;
  return DLIST;
}

int is_empty(DLIST L)
{
  return(L->next==NULL);
}

int is_last(position p)
{
  return(p->next==NULL);
}

position find(element_type x,DLIST L)
{
  position loc;
  for(loc=L->next;loc!=NULL&&loc->element!=x;loc=loc->next)
    ;
  return loc;
}

void delete(element_type x,DLIST L)
{
  position p=find(x,L);
  p->prev->next=p->next->next;
  p->next->prev=p->prev;
  free(p);
}

void insert(element_type x,LIST L,position p)
{
  position tmp=(positon) malloc(sizeof(struct node));
  if(tmp==NULL)
    fatal_error("No space\n");
  else{
    tmp->element=x;
    tmp->prev=p;
    tmp->next=p->next;
    p->next=tmp;
    tmp->next->prev=tmp;
  }
}

void delete_list(DLIST L)
{
  position p,tmp;
  for(p=L->next;p!=NULL;tmp=p->next){
    free(p);
    p=tmp; 
  }
  free(L);
}

 
