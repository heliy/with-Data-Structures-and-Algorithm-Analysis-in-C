#include<stdlib.h>

typedef unsigned int tree_ptr;
struct tree{
  element_type element;
  int isuse;
  tree_ptr left;
  tree_ptr right;
};
typedef tree_ptr SEARCH_TREE;

struct tree CURSOR_SPACE[SPACE_SIZE];

#define NULL_TREE (-1)

void make_null(tree_ptr p)
{
  CURSOR_SPACE[p].isuse=NULL_TREE;
}

SEARCH_TREE create_tree()
{
  make_null(0);
  return 0;
}

tree_ptr find(element_type x,SEARCH_TREE T)
{
  if(T==NULL_TREE||CURSOR_SPACE[T].isuse==NULL_TREE)
    return NULL_TREE;
  if(x<CURSOR_SPACE[T].element)
    return(find(x,CURSOR_SPACE[T].left));
  else if(x>CURSOR_SPACE[T].element)
    return(finde(x,CURSOR_SPACE[T].right));
  else
    return T;
}

tree_ptr find_min(SEARCH_TREE T)
{
  if(T==NULL_TREE||CURSOR_SPACE[T].isuse==NULL_TREE)
    return NULL_TREE;
  if(CURSOR_SPACE[T].left==NULL_TREE)
    return T;
  else 
    return find_min(CURSOR_SPACE[T].left);  
}

tree_ptr find_max(SEARCH_TREE T)
{
  if(T==NULL_TREE||CURSOR_SPACE[T].isuse==NULL_TREE)
    return NULL_TREE;
  if(CURSOR_SPACE[T].right==NULL_TREE)
    return T;
  else 
    return find_min(CURSOR_SPACE[T].right);  
}

tree_ptr avali_ptr()
{
  tree_ptr p;
  for(p=0;p<SPACE_SIZE;p++){
    if(CURSOR_SPACE[p].isuse==NULL_TREE)
      return p;
  }
  return NULL_TREE;
}

tree_ptr insert(element_type x,SEARCH_TREE T)
{
  if(T==NULL_TREE)
    return NULL_TREE;
  if(CURSOR_SPACE[T].isuse==NULL_TREE){
    CURSOR_SPACE[T].isuse==1;
    CURSOR_SPACE[T].element=x;
    CURSOR_SPACE[T].left=NULL_TREE;
    CURSOR_SPACE[T].right=NULL_TREE;
  }else{
    if(CURSOR_SPACE[T].element>x){
      if(CUSOR_SPACE[T].left==NULL_TREE){
	CURSOR_SPACE[T].left=avali_ptr();
      }
      CURSOR_SPACE[T].left=insert(x,CURSOR_SPACE[T].left);
    }else if(CURSOR_SPACE[T].element<x){
      if(CUSOR_SPACE[T].right==NULL_TREE){
	CURSOR_SPACE[T].right=avali_ptr();
      }
      CURSOR_SPACE[T].right=insert(x,CURSOR_SPACE[T].right);
    }
  }
  return T;
}

element_type delete_min(SEARCH_TREE T,tree_ptr father)
{
  element_type i;
  if(T==NULL_TREE||CURSOR_SPACE[T].isuse==NULL_TREE)
    return NULL_TREE;
  if(CURSOR_SPACE[T].left==NULL_TREE||CURSOR_SPACE[CURSOR_SPACE[T].left]==NULL_TREE){
    i=CURSOR_SPACE[T].element;
    CURSOR_SPACE[father].left=CURSOR_SPACE[T].right;
    CURSOR_SPACE[T].isuse=NULL_TREE;
    return i;
  }else
    return(delete_min(T->left,T));
}

tree_ptr delete(element_type x,SEARCH_TREE T)
{
  tree_ptr tmp;
  if(T==NULL_TREE||CURSOR_SPACE[T].isuse==NULL_TREE)
    return NULL_TREE;
  if(x<CURSOR_SPACE[T].element)
    return delete(x,CURSOR_SPACE[T].left);
  else if(x>CURSOR_SPACE[T].element)
    return delete(x,CURSOR_SPACE[T].right);

  element_type rightmin=delete_min(CURSOR_SPACE[T].right,T);
  if(rightmin==NULL_TREE){
    tmp=T;
    T=CURSOR_SPACE[T].left;
    CURSOR_SPACE[tmp].isuse=NULL_TREE;
  }else{
    CURSOR_SPACE[T].element=rightmin;
  }
  return T;
}
