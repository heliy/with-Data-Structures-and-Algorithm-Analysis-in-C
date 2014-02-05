#include<stdio.h>

struct Lnode * Lnode_ptr;
struct Gnode * Gnode_ptr;

struct Lnode{
  Gnode_ptr node;
  Lnode_ptr Lnext;
};
typedef Lnode_ptr LIST;

struct Gnode{
  int no;
  LIST Gnext;
};
typedef Gnode_ptr GRAPH;

Gnode_ptr findG(GRAPH G,int node_no)
{
  if(G==NULL||G->no=node_no)
    return G;
  else{
    Lnode_ptr p;
    for(p=GRAPH->Gnext->Lnext;p!=NULL;p=p->Lnext){
      find(p->node,node_no);
    }
  }
}

Lnode_ptr new_lnode()
{
  Lnode_ptr L=(Lnode_ptr) malloc(sizeof(struct Lnode));
  L->node=NULL;
  L->Lnext=NULL;
  return L;
}

Gnode_ptr new_gnode(int no)
{
  Gnode_ptr G=(Gnode_ptr) malloc(sizeof(struct Gnode));
  G->no=no;
  G->Gnext->next=new_lnode();
  return G;
}

Lnode_ptr findL(LIST L,int no)
{
  Lnode_ptr p;
  for(p=L->next;p!=NULL;p=p->Lnext){
    if(p->node->no==no)
      return p;
  }
  return NULL;
}

void mkch(Gnode_ptr father,Gnode_ptr child)
{
  Lnode_ptr p=findL(father->Gnext,child->no);
  if(p==NULL){
    for(p=father->Gnext;p->next!=NULL;p=p->next)
      ;
    p->next=new_londe();
    p->next->node=childe;
  }
}

void insert(GRAPH G,int node_no,int next_no)
{
  Gnode_ptr father=findG(G,node_no);
  if(father==NULL){
    father=new_gnode(node_no);
  }
  Gnode_ptr child=findG(G,next_no);
  if(child==NULL){
    child=new_gnode(next_no);
  }
  mkch(father,child);
}

void freeL(LIST);
void freeG(GRAPH G)
{
  if (G==NULL)
    return;
  freeL(G->next);
  free(G);
}

void freeL(LIST L)
{
  Lnode_ptr p,prev;
  for(p=L->Lnext;p!=NULL;p=next){
    freeG(p->node);
    next=p->Lnext;
    free(p);
  }
}
