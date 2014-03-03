#include<stdlib.h>

typedef struct list_node *node_ptr;
struct list_node{
  element_type element;
  node_ptr next;
};
typedef node_ptr LIST;
typedef node_ptr position;

struct hash_tbl{
  unsigned int table_size;
  LIST * the_lists;
};
typedef struct hash_tbl * HASH_TABLE;

unsigned int next_prime(unsigned int val)
{
  
}

typedef unsigned int INDEX;

INDEX hash(char *key,unsigned int H_SIZE)
{
  unsigned int hash_val=0;
  while(*key!='\0')
    hash_val=(hash_val<<5)+*key++;
  return(hash_val%H_SIZE);
}


HASH_TABLE initialize_table(unsigned int table_size)
{
  HASH_TABLE H;
  int i;
  if(table_size<MIN_TABLE_SIZE){
    printf("Table size too small\n");
    return NULL;
  }

  H=(HASH_TABLE) malloc(sizeof(struct hash_tbl));
  if(H==NULL){
    printf("Out of space\n");
    return NULL;    
  }

  H->table_size=next_prime(table_size);
  H->the_lists=(position *) malloc(sizeof(LIST)*H->table_size);
  if(H->the_lists==NULL){
    printf("Out of space\n");
    return NULL;    
  }

  for(i=0;i<H->table_size;i++){
    H->the_lists[i]=(LIST) malloc(sizeof(struct list_node));
    if(H->list[i]==NULL){
      printf("Out of space\n");
      return NULL;    
    }else
      H->the_lists[i]->next=NULL;
  }
  return H;
}

position find(element_type key,HASH_TABLE H)
{
  position p;
  LIST L;
  L=H->the_lists[hash(key,H->table_size)];
  p=L->next;
  while((p!=NULL)&&(p->element!=key))
    p=p->next;
  return p;
}

void insert_re(element_type key,HASH_TABLE H)
{
  position pos,new_cell;
  LIST L;
  L=H->the_lists[hash(key,H->table_size)];
  pos=L->next;
  while((pos!=NULL)&&(pos->element!=key))
    pos=pos->next;
  if(pos==NULL){
    new_cell=(position) malloc(sizeof(struct list_node));
    if(new_cell==NULL){
      printf("Out of space\n");
      return;
    }else{
      new_cell->next=L->next;
      new_cell->element=key;
      L->next=new_cell;
    }
  }
}

void deletion(element_type key,HASH_TABLE H)
{
  positon pos,prev;
  prev=H->the_lists[hash(key,H->table_size)];
  pos=prev->next;
  while((pos!=NULL)&&(pos->element!=key)){
    prev=pos;
    pos=pos->next;
  }
  if(pos==NULL){
    printf("Can not find\n");
  }else{
    prev->next=pos->next;
    free(pos);
  }
}

