#include<stdlib.h>
#include<math.h>
#include<stdio.h>
#define MIN_TABLE_SIZE 100

enum kind_of_entry{legitimate,empty,deleted};
struct hash_entry{
  int element;
  enum kind_of_entry info;
};

typedef unsigned int INDEX;
typedef INDEX position;
typedef struct hash_entry cell;

struct hash_tbl{
  unsigned int table_size;
  unsigned int current_size;
  cell *the_cells;
};
typedef struct hash_tbl * HASH_TABLE;

void free_tbl(HASH_TABLE H)
{
  free(H->the_cells);
  free(H);
}

INDEX hash(int key,unsigned int H_SIZE)
{
  return(key%H_SIZE);
}

int isprime(int num)
{
  int i=2;
  for(;i<=num/2;i++)
    if(num%i==0)
      return 1;
  return 0;
}

int next_prime(int num)
{
  if(isprime(num))
    return num;
  else return(next_prime(num++));
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
  H->the_cells=(cell *) malloc(sizeof(cell)*H->table_size);
  if(H->the_cells==NULL){
    printf("Out of space\n");
    return NULL;    
  }

  for(i=0;i<H->table_size;i++){
    H->the_cells[i].info=empty;
  }
  H->current_size=0;
  return H;
}

int insert_linear(int key,HASH_TABLE H)
{
  position i=0,pos;
  int iscollision=0;
  pos=hash(key,H->table_size);
  while((H->the_cells[pos].element!=key)&&(H->the_cells[pos].info!=empty)){
    iscollision++;
    pos+=(++i);
    if(pos>=H->table_size)
      pos-=H->table_size;
  }
  H->the_cells[pos].info=legitimate;
  H->the_cells[pos].element=key;
  return iscollision;  
}

int insert_quadratic(int key,HASH_TABLE H)
{
  position i,pos;
  i=0;
  int iscollision=0;
  pos=hash(key,H->table_size);
  while((H->the_cells[pos].element!=key)&&(H->the_cells[pos].info!=empty)){
    iscollision++;
    pos+=2*(++i)-1;
    if(pos>=H->table_size)
      pos-=H->table_size;
  }
  H->the_cells[pos].info=legitimate;
  H->the_cells[pos].element=key;
  return iscollision;
}

HASH_TABLE rehash(HASH_TABLE H)
{
  unsigned int i,old_size;
  cell *old_cells=H->the_cells;
  old_size=H->table_size;
  H=initialize_table(2*old_size);
  for(i=0;i<old_size;i++)
    if(old_cells[i].info==legitimate)
      insert_linear(old_cells[i].element,H);
  free(old_cells);
   return H;
}

int insert_rehash(int key,HASH_TABLE H)
{
  int iscollision=insert_linear(key,H);
  H->current_size++;
  if(H->current_size*2>H->table_size)
    H=rehash(H);
  return iscollision;
}


int main()
{
  int size=100;
  HASH_TABLE T1,T2,T3;
  T1=initialize_table(size);
  T2=initialize_table(size);
  T3=initialize_table(size);
  int col1=0,col2=0,col3=0;
  int i;
  for(i=0;i<size*2/3;i++){
    col1+=insert_linear(rand(),T1);    
    col2+=insert_quadratic(rand(),T2);    
    col3+=insert_rehash(rand(),T3);    
  }
  free_tbl(T1);
  free_tbl(T1);
  free_tbl(T1);
  printf("linear:%d\n",col1);
  printf("quadratic:%d\n",col2);
  printf("rehash:%d\n",col1);
}
