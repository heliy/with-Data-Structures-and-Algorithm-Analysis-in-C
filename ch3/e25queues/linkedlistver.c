#include<stdlib.h>

typedef node * node_ptr;
struct node{
  int ele;
  node_ptr next;
};

typedef node_ptr QUEUE;

QUEUE create_queue()
{
  QUEUE Q;
  Q=(QUEUE) malloc(sizeof(struct node));
  if(Q==NULL){
    printf("CAN NOT create queue:NO space\n");
    exit(-1);
  }
  Q->next=NULL;
}

int is_empty(QUEUE Q)
{
  return(Q->next==NULL);
}

void make_null(QUEUE Q)
{
  node_ptr p,t;
  for(p=Q->next;p->next==NULL;p=t){
    t=p->next;
    free(p);
  }
  Q->next=NULL;
}

void enqueue(int x,QUEUE Q)
{
  node_ptr p;
  for(p=Q->next;p->next!=NULL;p=p->next)
    ;
  p->next=(node *)create_queue();
  p->next->ele=x;
}

int dequeue(QUEUE Q)
{
  node_ptr p=Q->next;
  Q->next=p->next;
  int i=p->ele;
  free(p);
  return i;
}
