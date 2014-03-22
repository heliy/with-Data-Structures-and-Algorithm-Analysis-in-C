typedef int element_type;
typedef unsigned int position;

struct heap_struct{
  unsigned int size;
  unsigned int max_heap_size;
  element_type *elements;
};
typedef struct heap_struct *PRIORITY_QUEUE;

PRIORITY_QUEUE find_less_recu(PRIORITY_QUEUE,unsigned int,element_type,PRIORITY_QUEUE);

/* 结果放入新建的堆中 */
PRIORITY_QUEUE find_less_val(PRIORITY_QUEUE H,element_type val)
{
  PRIORITY_QUEUE R=create_pq((unsigned int) val);
  R=find_less_recu(H,0,val,R);
  return R;
}

PRIORITY_QUEUE find_less_recu(PRIORITY_QUEUE H,unsigned int i,element_type val,PRIORITY_QUEUE R)
{
  if(H==NULL||R==NULL)
    return NULL;
  if(i>=H->size)
    return R;
  if(H->elements[i]<val){
    R->elements[size++]=H->elements[i];
    R=find_less_recu(H,i*2,val,R);
    R=find_less_recu(H,i*2+1,val,R);
  }
  return R;
}

