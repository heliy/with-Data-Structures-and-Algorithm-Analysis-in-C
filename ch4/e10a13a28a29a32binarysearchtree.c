#include<stdlib.h>

typedef int element_type;

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

/* 4.28 
   only a pointer to T?
   O(n)*/

int count_nodes(SEARCH_TREE T)
{
  if(T==NULL)
    return 0;
  if(T->left!=NULL||T->right!=NULL)
    return(1+count_node(T->left)+count_node(T->right));
  else
    return 0;
}

int count_leaves(SEARCH_TREE T)
{
  if(T=NULL)
    return 0;
  if(T->left==NULL&&T->right==NULL)
    return 1;
  else
    return(count_leaves(T->left)+count_leaves(T->right));
}

int count_full(SEARCH_TREE T)
{
  if(T==NULL)
    return 0;
  else
    return(count_full(T->left)+count_full(T->right)+1);
}

/* 4.29
   O(n)*/

tree_ptr create_node(element_type x){
  tree_ptr p;

  p=(SEARCH_TREE) malloc(sizeof(struct tree_node));
  if(p==NULL){
    printf("NO space\n");
    exit(-1);
  }else{
    p->element=n;
    p->left=p->right=NULL;
  }

  return p;  
}

SEARCH_TREE create_n_recu(int n)
{
  tree_ptr T=NULL,R,p;
  int i;
  for(i=1;i<=n;i++){
    p=create_node((element_type) i);

    if(T==NULL){
      R=p;
    }else{
      T->right=p;
    }
    T=p;
  }
  return R;
}

/* 4.32 */

void print_elements(SEARCH_TREE T,element_type k1,element_type k2)
{
  if(T==NULL)
    return;
  if(T->element<k1)
    print_elements(T->right,k1,k2);
  else if(T->element>k2)
    print_elements(T->left,k1,k2);
  else{
    print_elements(T->left,k1,k2);
    print(T->element);
    print_elements(T->right,k1,k2);
  }
}

