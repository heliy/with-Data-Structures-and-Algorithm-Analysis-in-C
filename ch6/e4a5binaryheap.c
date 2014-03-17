typedef int element_type;
typedef unsigned int position;

struct heap_struct{
  unsigned int size;
  unsigned int max_heap_size;
  element_type *elements;
};
typedef struct heap_struct *PRIORITY_QUEUE;

PRIORITY_QUEUE create_pq(unsigned int max_elements)
{
  PRIORITY_QUEUE H;
  if(max_elements<MIN_PQ_SIZE)
    error("Priority queue size is too small");
  H=(PRORITY_QUEUE) malloc(sizeof(struct heap_struct));
  if(H==NULL)
    fatal_error("Out of space");
  H->elements=(element_type *)malloc(sizeof(element_type)*(max_elements+1));
  if(H->elements==NULL)
    fatal_error("Out of space");
  H->max_heap_size=max_elements;
  H->size=0;
  H->elements[0]=MIN_DATA;
  return H;
}

void insert(element_type x,PRIORITY_QUEUE H)
{
  position i;
  if(is_full(H))
    error("Priority queue is full");
  else{
    i=++H->size;
    while(H->elements[i/2]>x){
      H->elements[i]=H->elements[i/2];
      i/=2;
    }
    H->elements[i]=x;
  }
}

element_type delete_min(PRIORYTY_QUEUE H)
{
  position i,child;
  element_type min_element,last_element;
  if(is_empty(H)){
    error("Priority queue is empty");
    return H->elements[0];
  }

  min_element=H->elements[1];
  last_element=H->elements[H->size--];
  for(i=1;i*2<=H->size;i=child){
    child=i*2;  //<-完全树，起始节点下标为1
    if((child!=H->size)&&(H->elements[child+1]<H->elements[child]))
      child++;
    if(last_element>H->elements[child])
      H->elements[i]=H->elements[child];
    else
      break;
  }
  H->elements[i]=last_element;
  return min_element;
}

position get_father(position);
void swap_elements(position,position,PRIORITY_QUEUE);

void decrease_key(position pos,element_type delta,PRIORITY_QUEUE H)
{
  if(pos>H->size)
    return;

  position prev;
  *H->elements[pos]+=delta;
  for(prev=get_father(pos);prev>=1&&((*H->elements[prev])>(*H->elements[pos]));pos=prev,prev=get_father(prev)){
    swap_elements(prev,pos,H);
  }

  if(((*H->elements[prev])=(*H->elements[pos]))&&((*H->elements[prev])>(*H->elements[pos+1]))){
    swap_elements(prev,pos+1,H);
  }
}

void swap_elements(position prev,position pos,PRIORITY_QUEUE H)
{
  element_type tmp;
  tmp=H->elements[prev];
  H->elements[prev]=H->elements[pos];
  H->elements[pos]=tmp;
}

position get_father(position child)
{
  if(child%2)
    return(child/2);
  else
    return((child-1)/2);
}

void increase_key(position pos,element_type delta,PRIORITY_QUEUE H)
{
  if(pos>H->size)
    return;

  position child;
  *H->elements[pos]-=delta;
  for(chid=pos*2;child<H->size&&((*H->elements[child])<(*H->elements[pos]));pos=child,child=child*2){
    swap_elements(pos,child,H);
    if((*H->elements[pos])>(*H->elements[child+1]))
      swap_elements(pos,child+1,H);
  }

  if(((*H->elements[pos])=(*H->elements[child]))&&((*H->elements[pos])>(*H->elements[child+1]))){
    swap_elements(pos,child+1,H);
  }
}

element_type delete(position pos,PRIORITY_QUEUE H)
{
  if(pos>H->size)
    return NULL;

  element_type sai=H->elements[pos];
  decrease_key(pos,sai-MIN_DATA,H);
  delete_min(H);
  return sai;
}

void build_heap(PRIORITY_QUEUE H)
{
  position i;
  for(i=H->size/2;i>0;i--){
    increase_key(i,0,H);
  }
}

/* 6.4 */
void precolate_down(position i,PRIORITY_QUEUE H)
{
  increase_key(i,0,H);
}

void precolat_up(position i,PRIORITY_QUEUE H)
{
  decrease_key(i,0,H);
}

/* 6.5 */
element_type find_min(PRIORITY_QUEUE H)
{
  if(is_empty(H))
    return NULL;
  else
    return H->elements[0];
}


