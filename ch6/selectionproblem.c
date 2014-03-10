#include"binaryheap.h"

void copy_element_ptr(element_type*,element_type*,int);

element_type algorithm6a(element_type *data,int n,int k)
{
  PRIORITY_QUEUE H=create_pq((unsigned int)n);
  copy_element_ptr(H->elements+1,data,n);
  build_heap(H);
  int i;
  element_type kth;
  for(i=0;i<k;i++)
    kth=delete_min(H);
  free_pq(H);
  return kth;
}

void copy_element_ptr(element_type*to,element_type*from,int size)
{
  int i;
  for(i=0;i<size;i++)
    (*to++)=(*from++);
  (*to)='\0';
}

element_type algorithm6b(element_type*data,int n,int k)
{
  PRIROTY_QUEUE H=create_pq((unsigned int)k);
  copy_element_ptr(H->elements+1,data,k);
  build_heap(H);
  int i;
  element_type kth;
  for(i=k;i<n;i++){
    kth=H->elements[1];
    if(n[i]>kth){
      increase_key(1,n[i]-kth,H);
    }
  }
  return kth;
}
