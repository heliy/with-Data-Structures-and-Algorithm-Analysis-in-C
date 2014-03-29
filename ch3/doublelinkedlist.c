#include<stdlib.h>
#include<stdio.h>

typedef struct node * node_ptr;
typedef int element_type;

struct node
{
  element_type element;
  node_ptr prev;
  node_ptr next;
};

typedef node_ptr DLIST;
typedef node_ptr position;

DLIST init_list(void)
{
  DLIST list=(DLIST) malloc(sizeof(struct node));
  list->prev=NULL;
  list->next=NULL;
  return list;
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
  p->prev->next=p->next;
  if(p->next!=NULL)
    p->next->prev=p->prev;
  free(p);
}

void insert(element_type x,DLIST L,position p)
{
  position tmp=(position) malloc(sizeof(struct node));
  if(tmp==NULL)
    printf("No space\n");
  else{
    position next=p->next;
    tmp->element=x;
    tmp->prev=p;
    tmp->next=next;
    p->next=tmp;
    if(next!=NULL)
      next->prev=tmp;
  }
}

void delete_list(DLIST L)
{
  position p,tmp;
  for(p=L->next;p!=NULL;){
    tmp=p->next;
    free(p);
    p=tmp; 
  }
  free(L);
}

void print_element(position p)
{
  if(p==NULL)
    printf("NULL");
  else
    printf("%d",p->element);
}

void print_dlist(DLIST L)
{
  position p;
  for(p=L->next;p!=NULL;p=p->next){
    print_element(p);
    printf("->");
  }
  printf("NULL\n");
}

/* 3.3 */
void swap_next(DLIST L,element_type e)
{
  position p=find(e,L);
  position prev=p->prev,next=p->next;
  position next_next=next->next;

  prev->next=next;
  next->prev=prev;
  next->next=p;
  p->prev=next;
  p->next=next_next;
  if(next_next!=NULL)
    next_next->prev=p;
}

/* 测试： */
/* void main() */
/* { */
/*   DLIST L=init_list(); */
/*   element_type i; */
/*   for(i=4;i>0;i--){ */
/*     insert(i,L,L); */
/*   } */
/*   for(i=1;i<4;i++){ */
/*     print_dlist(L); */
/*     swap_next(L,1); */
/*     print_dlist(L); */
/*     printf("\n"); */
/*   } */
/*   delete_list(L); */
/* } */

