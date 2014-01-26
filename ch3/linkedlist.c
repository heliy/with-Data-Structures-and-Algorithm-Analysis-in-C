#include"linkedlist.h"

typedef struct node *node_ptr;

struct node
{
  element_type element;
  node_ptr next;
};

typedef node_ptr LIST;
typedef node_ptr position;

int is_empty(LIST L)
{
  return(L->next==NULL);
}

int is_last(position p,LIST L)
{
  /* postion last; */
  /* for(last=L->next;last->next!=NULL;last=last->next) */
  /*   ; */
  /* return(last==p); */
  return(p->next==NULL);
}

position find(element_type x,LIST L)
{
  position loc;
  for(loc=L->next;loc!=NULL&&loc->element!=x;loc=loc->next)
    ;
  return loc;
}

void find_prev(element_type x,LIST L)
{
  position pre;
  for(pre=L->next;pre->next!=NULL&&pre->next->element!=x;pre=pre->next)
    ;
  return pre;
}

void delete(element_type x,LIST L)
{
  position pre=find_prev(x,L);
  position tmp;
  if(pre->next!=NULL){
    tmp=pre->next;
    pre->next=tmp->next;
    free(tmp);
  }
}

void insert(element_type x,LIST L,position p)
{
  position tmp=(position) malloc(sizeof(struct node));
  if(tmp==NULL){
    printf("No space!\n")
      exit(-1);
  }else{
    tmp->element=x;
    tmp->next=p->next;
    p->next=tmp;
  }
}

void delete_list(LIST L)
{
  position p,tmp;
  for(p=L->next;p!=NULL;tmp=p->next){
    free(p);
    p=tmp; 
  }
  L->next=NULL;
}



