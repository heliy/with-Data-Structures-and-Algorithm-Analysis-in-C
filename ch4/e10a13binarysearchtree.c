#include<stdlib.h>

typedef struct tree_node *tree_ptr;

struct tree_node{
  element_type element;
  tree_ptr left;
  tree_ptr right;
};

typedef tree_ptr SEARCH_TREE;

SEARCH_TREE make_null()
{
  return NULL;
}

tree_ptr find(element_type x,SEARCH_TREE T)
{
  if(T==NULL)
    return NULL;
  if(x<T->element)
    return(find(x,T->left));
  else if(x>T->element)
    return(find(x,T->right));
  else
    return T;
}

tree_ptr find_min(SEARCH_TREE T)
{
  if(T==NULL)
    return NULL;
  else if(T->left==NULL)
    return T;
  else
    return(find_min(T->left));
}

tree_ptr find_max(SEARCH_TREE T)
{
  if(T!=NULL)
    while(T->right!=NULL)
      T=T->right;
  return T;
}

tree_ptr insert(element_type x,SEARCH_TREE T)
{
  if(T==NULL){
    T=(SEARCH_TREE) malloc(sizeof(struct tree_node));
    if(T==NULL){
      printf("NO space\n");
      exit(-1);
    }else{
      T->element=x;
      T->left=T->right=NULL;
    }
  }else{
    if(x<T->element)
      T->left=insert(x,T->left);
    else if(x>T->element)
      T->right=insert(x,T->right);
  }
  return T;
}

element_type delete_min(SEARCH_TREE T,tree_ptr father)
{
  element_type i;
  if(T==NULL)
    return NULL;
  if(T->left==NULL){
    i=T->element;
    father->left=T->right;
    free(T);
    return i;
  }else
    return(delete_min(T->left,T));
}

tree_ptr delete(element_type x,SEARCH_TREE T)
{
  tree_ptr tmp;
  if(T==NULL){
    printf("elemnet 404\n");
    return NULL;
  }
  if(x<T->element)
    return delete(x,T->left);
  else if(x>T->element)
    return delete(x,T->right);

  element_type rightmin=delete_min(T->right,T);
  if(rightmin==NULL){
    tmp=T;
    T=T->left;
    free(tmp);
  }else{
    T->element=rightmin;
  }
  return T;
}

/* 4.13 
   基本上。。。。*/

element_type delete_max(SEARCH_TREE T,tree_ptr father)
{
  element_type i;
  if(T==NULL)
    return NULL;
  if(T->right==NULL){
    i=T->element;
    father->right=T->left;
    free(T);
    return i;
  }else
    return(delete_max(T->left,T));

}

tree_ptr delete_left(SEARCH_TREE T)
{
  if(T==NULL)
    return NULL;
  if(x<T->element)
    return delete_left(x,T->left);
  if(x>T->element)
    return delete_left(x,T->right);

  element_type leftmax=delete_max(T->left,T);
  if(leftmax==NULL){
    tree_ptr tmp=T;
    T=T->right;
    free(tmp);
  }else{
    T->element=leftmax;
  }
  reutrn T;
}

