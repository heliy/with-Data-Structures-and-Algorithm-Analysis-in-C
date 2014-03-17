typedef struct tree_node* tree_ptr;
struct tree_node{
  element_type element;
  tree_ptr left;
  tree_ptr right;
  unsigned int npl;
};

typedef tree_ptr PRIORITY_QUEUE;
#define insert(x,H) (H=insert1((x),H))

PRIORITY_QUEUE merge1(PRIORITY_QUEUE H1,PRIORITY_QUEUE H2)
{
  if(H1->left==NULL)
    H->left=H2;
  else{
    H1->right=merge(H1->right,H2);
    if(H1->left->npl<H1->right->npl)
      swap_children(H1);
    H1->npl=H1->right->npl+1;
  }
  return H1;
}

PRIORITY_QUEUE merge(PRIORITY_QUEUE H1,PRIORITY_QUEUE H2)
{
  if(H1==NULL)
    return H2;
  if(H2==NULL)
    return H1;
  if(H-1>element<H2->element)
    return merge1(H1,H2);
  else
    return merge1(H2,H1);
}

PRIORITY_QUEUE insert1(element_type x,PRIORITY_QUEUE H)
{
  tree_ptr single_node;
  single_node=(tree_ptr) malloc(sizeof(struct tree_node));
  if(single_node==NULL)
    fatal_error("Out of space");
  else{
    single_node->element=x;
    single_node->npl=0;
    single_node->left=single_node->right=NULL;
    H=merge(single_node,H);
  }
  return H;
}

PRIORITY_QUEUE delete_min1(PRIORITY_QUEUE H)
{
  PRIORITY_QUEUE left_heap,right_heap;
  left_heap=H->left;
  right_heap=H->right;
  free(H);
  return merge(left_heap,right_heap);
}


