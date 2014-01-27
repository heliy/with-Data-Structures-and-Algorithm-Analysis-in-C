#include"linkedlist.h"

typedef struct node *node_ptr;
struct node
{
  unsigned int power;
  int eff;
  node_ptr next;
};
typedef struct node *POLYNOMIAL;
typedef struct node *CELL;

void init_polynomial(POLYNOMIAL poly)
{
  poly->next=NULL;
}

void insert_cell(CELL C,POLYNOIMAL poly) /*保持power降序*/
{
  CELL pre,loc;
  for(pre=poly->next;pre->next!=NULL&&pre->next->power>=C->power;pre=pre->next)
    ;
  loc=pre->next;
  if(loc==NULL){                  /*加入最低位*/
    pre->next=C;
    C->next=NULL;
  }else if(loc->power==C->power){  /*合并*/
    loc->eff=loc->eff+C->eff;
  }else{                          /*新的中间节点*/
    pre->next=C;
    C->next=loc;
  }
}

void add_polynomial(POLYNOMIAL poly1,POLYNOMIAL poly2,POLYNOMIAL poly_sum)
{
  init_polynomial(poly_sum);
  CELL c;
  for(c=poly1->next;c!=NULL;c=c->next){
    insert_cell(c,poly_sum);
  }
  for(c=poly2->next;c!=NULL;c=c->next){
    insert_cell(c,poly_sum);
  }
}

//O(mnlog(mn))
void mult_polynomial(POLYNOMIAL poly1,POLYNOMIAL poly2,POLYNOMIAL poly_pod)
{
  init_polynomial(poly_pod);
  CELL c1,c2;
  for(c1=poly1->next;c1!=NULL;c1=c1->next)
    for(c2=poly2->next;c2!=NULL;c2=c2->next){
      CELL C;
      C->power=c1->power+c2->power;
      C->eff=c1->eff+c2->eff;
      insert_cell(C,poly_pod);
    }
}

//O(Pnnlog(nn))
void pow_polynomial(int P,POLYNOMIAL poly,POLYNOMIAL poly_pow)
{
  init_polynomial(poly_pow);
  CELL c1,c2;
  int i;
  for(i=0;i<P;i++)
    for(c1=poly->next;c1!=NULL;c1=c1->next)
      for(c2=poly->next;c2!=NULL;c2=c2->next){
        CELL C;
        C->power=c1->power+c2->power;
        C->eff=c1->eff+c2->eff;
        insert_cell(C,poly_pod);
    }
}
