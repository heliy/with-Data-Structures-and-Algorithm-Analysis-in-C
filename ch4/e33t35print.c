#include<stdlib.h>

typedef int element_type;

typedef struct tree_node *tree_ptr;

struct tree_node{
  element_type element;
  tree_ptr left;
  tree_ptr right;
  float x;
  float y;
  int no; 
};

typedef tree_ptr SEARCH_TREE;

/* 4.33 */

/* a */
int count_full(SEARCH_TREE T)
{
  if(T==NULL)
    return 0;
  else
    return(count_full(T->left)+count_full(T->right)+1);
}

SEARCH_TREE parent_child_between(SEARCH_TREE T,tree_ptr parent)
{
  if(T==NULL)
    return NULL;
  if(parent==NULL)
    T->x=0;
  if(parent->left==T){
    T->x=(float)count_full(T->left);
  }else{
    T->x=(float)count_full(T->right);
  }
  T->left=parent_child_between(T->left,T);
  T->right=parent_child_between(T->right,T);
  return T;
}

SEARCH_TREE make_inorder(SEARCH_TREE T)
{
  if(T==NULL)
    return NULL;
  if(T->left!=NULL){
    T->left->x=T->x-T->left->x;
    T->left=make_inorder(T-left);
  }
  if(T->right!=NULL){
    T->right->x=T->x+T->right->x;
    T->right=make_inorder(T->right);
  }
  return T;
}

SEARCH_TREE x_coordinate(SEARCH_TREE T)
{
  T=parent_child_between(T,NULL);
  T=make_inorder(T);
  return T;
}

/* b */

SEARCH_TREE make_nega_depth(SEARCH_TREE T,tree_ptr father)
{
  if(T==NULL)
    return NULL;
  if(father==NULL)
    T->y=0.0;
  else{
    T->y=father->y-1;
  }
  T->left=make_nega_depth(T->left,T);
  T->right=make_nega_depth(T->right,T);
  return T;
}

SEARCH_TREE y_coordinate(SEARCH_TREE T)
{
  return(make_nega_depth(T,NULL));
}

/* c 
   调高
   题目是指高是宽的2/3?<-E文没学好*/

int height(SEARCH_TREE T)
{
  if(T==NULL)
    return 0;
  return(max(height(T->left),height(T->right))+1);
}

int width(SEARCH_TREE T)
{
  tree_ptr p;
  if(T==NULL)
    return 0;
  int w=1;
  for(p=T;p->left!=NULL;p=p->left);
  if(p!=T)
    w=w-(int)p->x;
  for(p=T;p-right!=NULL;p=p->right);
  if(p!=T)
    w=w+(int)p->x;
  return w;
}

SEARCH_TREE adjust_coordinate(SEARCH_TREE T,float factor)
{
  if(T==NULL)
    return NULL;
  T->y=T->y*factor;
  T->left=adjust_coordinate(T->left);
  T->right=adjust_coordinate(T->right);
  return T;
}

SEARCH_TREE adjust_2_3(SEARCH_TREE T)
{
  int w=width(T),h=height(T);
  float factor=w*2.0/3*h;
  return(adjust_coordinate(T,factor));
}

/* 4.34 
   后续*/

void draw(SEARCH_TREE T)
{
  if(T==NULL)
    return;
  circle(T->x,T->y);
  if(T->left!=NULL){
    drawline(T->no,T->left->no);
  }
  if(T->right!=NULL){
    drawline(T->no,T->right->no);
  }

}

/* 4.35 
   用linkedlist*/

typedef struct node * node_ptr;
struct list_node{
  tree_ptr tree;
  node_ptr next;
};
typedef node_ptr LIST;

void free_list(LIST L)
{
  if(L==NULL) return;
  position pos,rank=L;
  for(pos=L->next;pos!=NULL;pos=L){
    L=pos->next;
    free(pos);
  }
  free(rank);
}

void insert_fornt(tree_ptr tree,LIST L)
{
  position p;
  p=(node_ptr) malloc(sizeof(struct list_node)); 
  if(p==NULL)
    exit(-1);
  p->tree=tree;
  p->next=L;
  L=p;
}

void format(SEARCH_TREE T,LIST *array,int h)
{
  if(T==NULL)
    return;
  insert_fornt(array[h-1],T);
  format(T->left;array,h-2);
  format(T->right;array,h-2);
}

void print_list(LIST L)
{
  position p;
  for(p=L;p!=NULL;p=p->next){
    print_element(p->tree->element);
  }
}

void print_lists(LIST *array,int h)
{
  int i;
  for(i=h-1;i>0;i--){
    print_list(array[i]);
  }
}

void print_level_order(SEARCH_TREE T)
{
  int h=height(T);              /* O(n) */
  LIST array[h];
  int i;
  for(i=0;i<h;i++)		/* O(logn) */
    array[i]=NULL;

  format(T,array,h);   		/* O(n) */

  print_element(T);
  print_lists(array,h);		/* O(n) */
}
