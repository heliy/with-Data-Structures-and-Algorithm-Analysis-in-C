#include<stdio.h>
#include<stdlib.h>

typedef struct node * node_ptr;
struct node{
  int no;
  node_ptr next;
};
typedef struct node * CELL;
typedef struct node * CLIST;

void jose(int m,int n)
{
  int i,rank;
  CLIST init;
  CLIST list=(CLIST) malloc(sizeof(struct node));
  list->no=0;
  init=list;
  for(i=0;i<n;){
    CELL c=(CELL) malloc(sizeof(struct node));
    c->no=++i;
    list->next=c;
    list=c;
  }
  list->next=init;
  list=init;

  for(rank=n;rank>1;rank--){
    for(i=0;i<m+1;i++){
        list=list->next;
      while(list->no==0){
        list=list->next;
      }
    }
    printf("--dead:%d\n",list->no);
    list->no=0;
  }

  for(list=init->next;list!=init;list=list->next){
    if(list->no!=0){
      printf("manslaughter:%d\n",list->no);
      break;
    }
  }

  for(list=init,i=0;i<=n;i++){
    init=list->next;
    free(list);
    list=init;
  }
}

int main(){
  jose(0,10);
}

