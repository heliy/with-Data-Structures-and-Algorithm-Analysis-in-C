typedef int element_type;
typedef struct tree_node *tree_ptr;
struct tree_node{
  element_type element;
  tree_ptr left;
  tree_ptr right;
};
typedef tree_ptr SEARCH_TREE;

/* 4.41 */
int is_similar(SEARCH_TREE T1,SEARCH_TREE T2)
{
  if(T1==NULL&&T2==NULL)
    return 1;
  else if(T1!=NULL||T2!==NULL)
    return 0;
  if(T1->element!=T2->element)
    return 1;
  return(is_similar(T1->left,T2->left)&&is_similar(T1->right,T2->right));
}


/* 4.42 */

int is_isomorphic(SEARCH_TREE T1,SEARCH_TREE T2)
{
  if(T1==NULL&&T2==NULL)
    return 1;
  else if(T1==NULL||T2==NULL)
    return 0;
  else if(T1->element!=T2->element)
    return 0;
  else{
    return ((is_isomorphic(T1->left,T2->left)&&is_isomorphic(T1->right,T2->right))||(is_isomorphic(T1->right,T2->left)&&is_isomorphic(T1->left,T2->right)));
  }
}

/* 4.43 */
//不会哈。。。
