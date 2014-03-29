#include<stdlib.h>
#include<stdio.h>

typedef struct node *node_ptr;
typedef int element_type;

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

position find_prev(element_type x,LIST L)
{
  position pre;
  for(pre=L;pre->next!=NULL&&pre->next->element!=x;pre=pre->next)
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
    printf("No space!\n");
    exit(-1);
  }else{
    tmp->element=x;
    tmp->next=p->next;
    p->next=tmp;
  }
}

void make_null(LIST L)
{
  position p,tmp;
  for(p=L->next;p!=NULL;p=tmp){
    tmp=p->next;
    free(p);
  }
  L->next=NULL;
}

void delete_list(LIST L)
{
  make_null(L);
  free(L);
}

LIST init_list()
{
  LIST L=(LIST) malloc(sizeof(struct node));
  L->next=NULL;
  return L;
}

/* exercise 3.1 */
void print_element(position p)
{
  if(p==NULL)
    printf("NULL");
  else
    printf("%d",p->element);
}

void print_list(LIST L)
{
  position p;
  for(p=L->next;p!=NULL;p=p->next){
    print_element(p);
    printf("->");
  }
  printf("NULL\n");
}

/* 测试： */
/* void main() */
/* { */
/*   LIST L=init_list(); */
/*   element_type i; */
/*   for(i=0;i<10;i++) */
/*     insert(i,L,L); */
/*   print_list(L); */
/*   make_null(L); */
/*   free(L); */
/* } */

/* 3.2 */
position find_kth(LIST L,int k)
{
  int i;
  position p;
  for(i=1,p=L->next;i<k&&p!=NULL;i++,p=p->next)
    ;
  return p;
}

/* O(mn) */
void print_lots(LIST L,LIST P)
{
  position p,loc;
  for(p=P->next;p!=NULL;p=p->next){
    loc=find_kth(L,p->element);
    if(loc==NULL)
      break;
    else
      print_element(loc);
  }
}

/* 测试: */
/* int main() */
/* { */
/*   LIST L=init_list(),P=init_list(); */
/*   element_type i; */
/*   for(i=20;i>0;i--) */
/*     insert(i,L,L); */
/*   for(i=25;i>0;i-=5) */
/*     insert(i,P,P); */
/*   print_lots(L,P); */
/*   delete_list(L); */
/*   delete_list(P); */
/*   return 0; */
/* } */

/* 3.3 */
void swap_next(LIST L,element_type e)
{
  position prev=find_prev(e,L);
  position p=prev->next;
  position next=p->next;
  position next_next=next->next;

  prev->next=next;
  next->next=p;
  p->next=next_next;
}

/* 测试： */
/* void main() */
/* { */
/*   LIST L=init_list(); */
/*   element_type i; */
/*   for(i=4;i>0;i--) */
/*     insert(i,L,L); */
/*   for(i=1;i<4;i++){ */
/*     print_list(L); */
/*     swap_next(L,1); */
/*     print_list(L);  */
/*     printf("\n"); */
/*   } */
/*   delete_list(L); */
/* } */

/* 3.4 & 3.5 */
LIST join_lists(LIST L1,LIST L2)
{
  LIST L=init_list();
  if(is_empty(L1)||is_empty(L2)){
    return L;
  }

  position p;
  for(p=L1->next;!is_last(p,L1);p=p->next){
    if(find(p->element,L2)!=NULL)
      insert(p->element,L,L);
  }
  return L;
}

void copy_to(LIST,LIST);

LIST union_lists(LIST L1,LIST L2)
{
  LIST L=init_list();
  if(is_empty(L1)){
    copy_to(L2,L);
    return L;
  }
  if(is_empty(L2)){
    copy_to(L1,L);
    return L;
  }

  position p;
  copy_to(L1,L);
  for(p=L2->next;!is_last(p,L2);p=p->next){
    if(find(p->element,L)==NULL)
      insert(p->element,L,L);
  }
  return L;
}

void copy_to(LIST F,LIST T)
{
  position p;
  if(is_empty(F))
    return;
  for(p=F->next;!is_last(p,F);p=p->next){
    insert(p->element,T,T);
  }
}

/* 测试： */
/* int main() */
/* { */
/*   LIST L1=init_list(); */
/*   LIST L2=init_list(); */
/*   element_type i; */
/*   for(i=1;i<20;i+=2) */
/*     insert(i,L1,L1); */
/*   for(i=1;i<20;i+=3) */
/*     insert(i,L2,L2); */

/*   print_list(L1); */
/*   print_list(L2); */
/*   LIST L3=join_lists(L1,L2); */
/*   LIST L4=union_lists(L1,L2); */
/*   print_list(L3); */
/*   print_list(L4); */
/*   delete_list(L1); */
/*   delete_list(L2); */
/*   delete_list(L3); */
/*   delete_list(L4); */
/*   return 0; */
/* } */
