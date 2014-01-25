typedef unsigned int node_tpr;
struct node
{
  element_type element;
  node_ptr next;
};
typedef node_ptr LIST;
typedef node_ptr postion;
struct node CURSOR_SPACE[SPACE_SIZE];

postion cursor_alloc(void)
{
  postion p;
  p=CURSOR_SPACE[0].next;
  CURSOR_SPACE[0].next=CURSOR[p].next;
  return p;
}

void cursor_free(position p)
{
  CURSOR_SPACE[p]=CURSOR_SPACE[0].next;
  CURSOR_SPACE[0].next=p;
}

int is_empty(LIST L)
{
  return(CURSOR_SPACE[L].next==0)
}

int is_last(position p,LIST L)
{
  return(CURSOR_SPACE[p].next==0)
}

position find(element_type x,LIST L)
{
  postion p;
  p=CURSOR_SPACE[L].next;
  while(p&&CURSOR_SPACE[p].element!=x)
    p=CURSOR_SPACE[p].next;
  return p;
} 

void delete(element_type x,LIST L)
{
  positon p,tmp_cell;
  p=find_previous(x,L);
  if(!is_last(p,L)){
    tmp_cell=CURSOR_SPACE[p].next;
    CURSOR_SPACE[p].next=CURSOR_SPACE[tmp_cell].next;
    cursor_free(tmp_cell);
  }
}

void insert(element_type x,LIST L,position p)
{
  position tmp;
  tmp=cursor_alloc();
  if(tmp==0)
    fatal_error("OUT OF SPACE!!");
  else{
    CURSOR_SPACE[tmp].element=x;
    CURSOR_SPACE[tmp].next=CURSOR_SPACE[p].next;
    CURSOR_SPACE[p].next=tmp;
  }
}
