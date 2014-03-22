#include<math.h>

typedef int element_type;
typedef unsigned int position;

struct heap_struct{
  unsigned int size;
  unsigned int max_heap_size;
  element_type *elements;
};
typedef struct heap_struct *PRIORITY_QUEUE;

/* a
   root最小，depth=1的两节点中的较大值为最大值 
 */

/* b insert */
void precolate_up(position ,PRIORITY_QUEUE);

void insert(element_type x,PRIORITY_QUEUE H)
{
  if(is_full(H))
    return NULL;

  H->elements[++size]=x;
  precolate_up(size,H);
}

int is_even_depth(position i);
void swap_elements(position,position,PRIORITY_QUEUE);

void precolate_up(position i,PRIORITY_QUEUE H)
{
  position parent=i/2,grand=i/4;
  if(parent==grand)
    return;

  if(is_even_depth(i)){
    if(H->elements[parent]<H->elements[i])
      swap_elements(i,parent,H);
    if(H->elements[grand]>H-<elements[i])
      swap_elements(i,grand,H);
  }else{
    if(H->elements[parent]>H->elements[i])
      swap_elements(i,parent,H);
    if(H->elements[grand]<H-<elements[i])
      swap_elements(i,grand,H);
  }

  precolate_up(parent,H);
  precolate_up(grand,H);
}

int is_even_depth(position i)
{
  int depth=log(i);
  return(i%2==0);
}

void swap_elements(position a,position b,PRIORITY_QUEUE H)
{
  element_type tmp;
  tmp=H->elements[a];
  H->elements[a]=H->elements[b];
  H->elements[b]=tmp;
}

/* c delete_min  delete_max*/

void get_successor(position ,PRIORITY_QUEUE);

element_type delete_min(PRIORITY_QUEUE H)
{
  if(is_empty(H))
    return NULL

  element_type min=H->elements[1];
  get_successor(1,H);
  H->size--;

  return min;
}

element_type delelte_max(PRIORITY_QUEUE H)
{
  element_type max;
  if(is_empty(H))
    return NULL;
  if(H->size<3){
    max=H->elements[size];
    H->elemets[size--]='\0';
    return max;
  }

  if(H->elements[2]>H->elements[3]){
    max=H->elements[2];
    get_successor(2,H);
  }else{
    max=H->elements[3];
    get_successor(3,H);
  }
  H->size--;
  return max;
}

int can_no_deep(position,PRIORITY_QUEUE);

void get_successor(position i,PRIORITY_QUEUE H)
{
  position tmp,grandchild;
  if(can_no_deep(i,H)){
    for(tmp=i+1;tmp<=H->size;tmp++){
      H->elements[tmp-1]=H->elements[tmp];
    }
    H->elements[--tmp]='\0';
    return;
  }

  grandchild=i*4;
  if(is_even_deepth(i)){
    if(H->elements[grandchild]<H->elements[grandchild+1]){
      swap_elements(grandchild,i,H);
      get_successor(grandchild,H);
    }else{
      swap_elements(grandchild+1,i,H);
      get_successor(grandchild+1,H);      
    }
  }else{
    if(H->elements[grandchild]>H->elements[grandchild+1]){
      swap_elements(grandchild,i,H);
      get_successor(grandchild,H);
    }else{
      swap_elements(grandchild+1,i,H);
      get_successor(grandchild+1,H);      
    }
  }
}

int can_no_deep(position i,PRIORITY_QUEUE H)
{
  return (i>H/4);
}

/* d build_up */

void build_up(PRIORITY_QUEUE H)
{
  position i;
  for(i=H->size/2;i>0;i--)
    precolate_up(i,H);
}


