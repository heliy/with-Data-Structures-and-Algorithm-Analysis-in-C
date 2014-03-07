#include<stdlib.h>
#include<stdio.h>

/* polynomial */
typedef struct poly_node * poly_node_ptr;
struct poly_node{
  int power;
  int eff;
  poly_node_ptr next;
};
typedef struct poly_node * POLYNOMIAL;

void init_polynomial(POLYNOMIAL poly)
{
  poly->next=NULL;
}

poly_node_ptr init_poly_node( int power,int eff)
{
  poly_node_ptr ptr=(poly_node_ptr) malloc(sizeof(struct poly_node));
  if(ptr==NULL){
    printf("Out of space!\n");
    exit(-1);
  }else{
    ptr->power=power;
    ptr->eff=eff;
    ptr->next=NULL;
    return ptr;
  }
}

void insert_fornt_poly(poly_node_ptr node,POLYNOMIAL poly)
{
  poly_node_ptr tmp=poly->next;
  poly->next=node;
  node->next=tmp;
}

void print_poly(POLYNOMIAL poly)
{
  poly_node_ptr tmp=poly->next;
  while(1){
    printf("(%d)x^(%d)",tmp->eff,tmp->power);
    if(tmp->next==NULL){
      printf("\n");
      break;
    }else{
      tmp=tmp->next;
      printf("+");
    }
  }
}

void free_poly(POLYNOMIAL poly)
{
  poly_node_ptr tmp;
  for(tmp=poly->next;tmp!=NULL;tmp=tmp->next){
    free(poly);
    poly=tmp;
  }
}

/* hash_table?
这个直接用数组方便
无视本章好了
 array
 */

int * init_array(int max_power)
{
  int size=max_power+1,i;
  int * array=(int *) malloc(sizeof(int)*size);
  for(i=0;i<size;i++){
    array[i]=0;
  }
  return array;
}

void insert(poly_node_ptr node,int * array)
{
  int power=node->power;
  array[power]+=node->eff;
}

/* 将数组转化为多项式 */
POLYNOMIAL array2poly(int * array,int max_power)
{
  POLYNOMIAL poly;
  init_polynomial(poly);
  int i;
  for(i=0;i<=max_power;i++){
    if(array[i]==0)
      continue;
    poly_node_ptr ptr=init_poly_node(i,array[i]);
    insert_fornt_poly(ptr,poly);
  }
  return poly;
}

/* 多项式乘 返回结果的指针 */
POLYNOMIAL multi_poly(POLYNOMIAL poly1,POLYNOMIAL poly2)
{
  if(poly1->next==NULL||poly2->next==NULL)
    return NULL;

  int max_power=poly1->next->power+poly2->next->power;
  int * array=init_array(max_power);
  poly_node_ptr ptr1,ptr2;

  for(ptr1=poly1->next;ptr1!=NULL;ptr1=ptr1->next)
    for(ptr2=poly2->next;ptr2!=NULL;ptr2=ptr2->next){
       int power=ptr1->power+ptr2->power;
       int eff=ptr1->eff+ptr2->eff;
       array[power]+=eff;
    }

  POLYNOMIAL poly=array2poly(array,max_power);
  free(array);
  return poly;
}

void main(){
  POLYNOMIAL poly1,poly2;
  init_polynomial(poly1);
  init_polynomial(poly2);
  poly_node_ptr node;

  node=init_poly_node(2,1);
  insert_fornt_poly(node,poly1);
  node=init_poly_node(3,2);
  insert_fornt_poly(node,poly1);

  node=init_poly_node(0,4);
  insert_fornt_poly(node,poly2);
  node=init_poly_node(1,2);
  insert_fornt_poly(node,poly2);
  node=init_poly_node(4,3);
  insert_fornt_poly(node,poly2);

  POLYNOMIAL multi=multi_poly(poly1,poly2);
  print_poly(multi);

  free_poly(poly1);
  free_poly(poly2);
  free_poly(multi);
}

