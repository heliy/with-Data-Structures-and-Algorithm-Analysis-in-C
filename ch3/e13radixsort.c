#include<stdio.h>
#include<stdlib.h>

typedef int element_type;
#include"linkedlist.h"

void print(int *);
void concern(int *,int);

void radixsort(int *a,int p)
{
  int k=0;
  do{
    concern(a,k);
    k++;
  }while(k<p);
  print(a);
}

void print(int *a)
{
  int i;
  for(i=0;a[i]!='\0';i++){
    printf("%d\n",a[i]);
  }
}

int decbit(int number,int loc);
void copy2array(LIST *,int *);

void concern(int *a,int k)
{
  LIST LS[10],L;
  int i;
  for(i=0;i<10;i++){
    L=*LS[i];
    L->next=NULL;
  }
  for(i=0;a[i]!='\0';i++){
    int l=decbit(a[i],k);
    insert(a[i],*LS[l],NULL);
  }
  copy2array(LS,a);
  for(i=0;i<10;i++)
    delete_list(*LS[i]);
}

int decbit(int number,int loc)
{
  int i;
  for(i=0;i<loc;i++)
    number=number/10;
  return number%10;
}

void copy2array(LIST *LS,int *a)
{
  LIST L;
  int i;
  for(i=0;i<10;i++){
    position p;
    L=*LS[i];
    for(p=L->next;p!=NULL;p=p->next){
      *a=p->element;
      a++;
    }
  }
}

int main(){
  int a[10]={64,8,216,512,27,729,0,1,343,125};
  radixsort(a,3);
}
