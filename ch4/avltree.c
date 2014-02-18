#include<stdlib.h>

typedef struct avl_node *avl_ptr;

struct avl_node{
  element_type element;
  avl_ptr left;
  avl_ptr right;
  int height;
};

typedef avl_ptr SEARCH_TREE;

int height(avl_ptr p)
{
  if(p==NULL)
    return -1;
  else
    return p->height;
}

int node_height(avl_ptr p)
{
  return(max(height(p->left),height(p->right))+1);
}

avl_ptr s_rotate_left(avl_ptr k2)
{
  avl_ptr k1=k2->left;
  k2->left=k1->right;
  k1->right=k2;
  k2->height=node_height(k2);
  k1->height=node_height(k1);
  return k1;
}

avl_ptr s_rotate_right(avl_ptr k1)
{
  avl_ptr k2=k1->right;
  k1->right=k2->left;
  k2->left=k1;
  k1->height=node_height(k1);
  k2->height=node_height(k2);
  return k2;
}

avl_ptr d_rotate_left(avl_ptr k3)
{
  k3->left=s_rotate_right(k3->left);
  return(s_rotate_left(k3));
}

avl_ptr d_rotate_right(avl_ptr k3)
{
  k3->right=s_rotate_left(k3->right);
  return(s_rotate_right(k3));
}

SEARCH_TREE insert1(element_type x,SEARCH_TREE T,avl_ptr parent)
{
  avl_ptr rotated_tree;
  if(T==NULL){
    T=(SEARCH_TREE) malloc(sizeof(struct avl_node));
    if(T==NULL)
      fatal_error("Out of space\n");
    else{
      T->element=x;
      T->height=0;
      T->left=T->right=NULL;
    }
  }else{
    if(x<T->element){
      T->left=insert1(x,T->left,T);
      if((height(T->left)-height(T->right))==2){
	if(x<T->left->element)
	  rotated_tree=s_rotated_left(T);
	else
	  rotated_tree=d_rotated_left(T);
	if(parent->left==T)
	  parent->left=rotated_tree;
	else
	  parent->right=rotated_tree;
      }else{
	T->height=node_height(T);
      }
    }else if(x>T->element){
      T->right=insert1(x,T->right,T);
      if((height(T->left)-height(T->right))==2){
	if(x>T->right->element)
	  rotated_tree=s_rotated_right(T);
	else
	  rotated_tree=d_rotated_right(T);
	if(parent->right==T)
	  parent->right=rotated_tree;
	else
	  parent->left=rotated_tree;
      }else{
	T->height=node_height(T);
      }
    }
  }
  return T;
}

SEARCH_TREE insert(element_type x,SEARCH_TREE T)
{
  return insert1(x,T,NULL);
}


