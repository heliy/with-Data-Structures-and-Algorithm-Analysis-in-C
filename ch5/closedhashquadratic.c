enum kind_of_entry{legitimate,empty,deleted}; //<-三种？？
struct hash_entry{
  element_type element;
  enum kind_of_entry info;
};

typedef unsigned int INDEX;
typedef INDEX position;
typedef struct hash_entry cell;

struct hash_tbl{
  unsigned int table_size;
  cell *the_cells;
};
typedef struct hash_tbl * HASH_TABLE;

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
  return H;

}

position find(element_type key,HASH_TABLE H)
{
  position i,current_pos;
  i=0;
  current_pos=hash(key,H->table_size);
  while((H->the_cells[current_pos].element!=key)&&(H->the_cells[current_pos].info!=empty)){
    current_pos+=2*(++i)-1;
    if(current_pos>=H->table_size)
      current_pos-=H->table_size;
  }
  return current_pos;
}

void insert(element_type key,HASH_TABLE H)
{
  position i,pos;
  i=0;
  pos=hash(key,H->table_size);
  while((H->the_cells[pos].element!=key)&&(H->the_cells[pos].info!=empty)){
    pos+=2*(++i)-1;
    if(pos>=H->table_size)
      pos-=H->table_size;
  }
  H->the_cells[pos].info=legitimate;
  H->the_cells[pos].element=key;
}

