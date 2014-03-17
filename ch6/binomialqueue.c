typedef struct tree_node * tree_ptr;
struct tree_node{
  element_type element;
  tree_ptr left_sib;
  tree_ptr right_sib;
  tree_ptr first_child;
  unsigned int rank;
};
typedef tree_ptr PRIORITY_QUEUE;

tree_ptr merge_tree(tree_ptr T1,tree_ptr T2)
{
  if(T1->element>T2->element)
    return merge_tree(T2,T1);
  if(T1->rank++==0)
    T1->first_child=T2;
  else{
    T2->left_sib=T1->first_child->left_sib;
    T2->left_sib->right_sib=T2;
    T1->first_child->left_sib=T2;
  }
  return T1;
}

PROIRITY_QUEUE merge(PRIORITY_QUEUE H1,PRIORITY_QUEUE H2)
{
  PRIORITY_QUEUE H3;
  tree_ptr T1,T2,T3;
  if(H1==NULL)
    return H2;
  if(H2==NULL)
    return H1;
  if(H1->rank<H2->rank){
    T1=extract(H1);
    H3=merge(H1,H2);
    T1->left_sib=H3->left_sib;
    H3->left_sib->right_sib=NULL;
    T10<right_sib=H3;
    H3->left_sib=T1;
    return T1;
  }
  if(H2->ranf<H1->rank)
    return merge(H2,H1);

  T1=extract(H1);
  T2=extract(H2);
  H3=merge(H1,H2);
  T3=merge_tree(T1,T2);
  return merge(T3,H3);
}
