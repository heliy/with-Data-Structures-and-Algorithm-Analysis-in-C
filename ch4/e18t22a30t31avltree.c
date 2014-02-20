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

tree_ptr node_init(element_type x)
{
  tree_ptr T=(SEARCH_TREE) malloc(sizeof(struct avl_node));
  if(T==NULL)
    fatal_error("Out of space\n");
  else{
    T->element=x;
    T->height=0;
    T->left=T->right=NULL;
  }
  return T;  
}

int is_father_fit(element_type x,SEARCH_TREE T)
{
  if(x<T->element){
    if(T->left==NULL)
      return 1;
    else
      return -1;
  }else if(x>T->element){
    if(T->right==NULL)
      return 2;
    else
      return -2;
  }else{
    return 0;
  }
}

tree_ptr find_father(SEARCH_TREE T,SEARCH_TREE root)
{
  if(T==NULL||root==NULL)
    return NULL;
  if(root->left==T||root->right==T)
    return root;
  if(T->element<root->element)
    return(find_father(T,root->left));
  else
    return(find_father(T,root->right));
}

void total_rotate(element_type x,SEARCH_TREE T,SEARCH_TREE root)
{
  tree_ptr father=find_father(T,root),rotated_tree;
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
    if((height(T->right)-height(T->left))==2){
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


void insert_nonrecu(element_type x,SEARCH_TREE T)
{
  if(T==NULL){
    T=node_init(x);
    return;
  }

  avl_ptr f,tmp;
  f=T;
  int i;
  while((i=is_father_fit(x,f))<0){
    if(i==-1)
      f=f->left;
    else
      f=f->right;
  }
  if(i==0)  /* 已有 */
    return;
  tmp=node_init(x);
  if(i==1){
    f->left=tmp;
  }else{
    f->right=tmp;
  }

  for(;tmp!=T;tmp=f){
    f=find_father(tmp,T);
    total_rotated(x,f);
  }
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
      if((height(T->right)-height(T->left))==2){
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


/* 4.18&20 */
/* 20:非递归版？ <-应该不符合要求
      将对向的节点重新insert一遍*/

void re_new(val_ptr p,val_ptr father,SEARCH_TREE root)
{
  if(p->left!=NULL)
    re_new(p->left,p,root);
  if(p->right!=NULL)
    re_new(p->right,p,root);

  element_type i=p->element;

  if(father->left==p)
    father->left=NULL;
  else
    father->right=NULL;
  free(p);

  root=insert(i,root);
}

avl_ptr delete_node(val_ptr father,val_ptr p){
  if(father->right==p){
    father->right=p->right;
    if(p->left!=NULL){
      re_new(p->left);
    }
  }else{
    father->left=p->left;
    if(p->right!=NULL){
      re_new(p->right);
    }
  }
  free(p);
}


void delete(element_type x,SEARCH_TREE T)
{
  if(T==NULL){
    T=node_init(x);
    return;
  }

  avl_ptr f,tmp;
  f=T;
  int i;
  while((i=is_father_fit(x,f))<0){
    if(i==-1)
      f=f->left;
    else
      f=f->right;
  }
  if(i==0)  /* 没有 */
    return;
  if(i==1){
    tmp=delete_node(f,f->left);
  }else{
    tmp=delete_node(f,f->right);
  }

  for(;tmp!=T;tmp=f){
    f=find_father(tmp,T);
    total_rotated(x,f);
  }

}

/* 4.22 */
void d_rotate_left_nons(avl_ptr k3)
{
  avl_ptr k1,k2,B,C;
  k1=k3->left;
  k2=k1->right;
  B=k2->left;
  C=k2->right;

  k2->left=k1;
  k1->right=B;
  k2->right=k3;
  k3->left=C;
}

void d_rotate_left_nons(avl_ptr k3)
{
  avl_ptr k1,k2,B,C;
  k1=k3->right;
  k2=k1->left;
  B=k2->left;
  C=k2->right;

  k2->left=k3;
  k3->right=B;
  k2->right=k1;
  k1->left=C;
}

/* 4.30 & 4.31*/

SEARCT_TREE create_max(int h,tree_ptr father,int flag)
{
  if(h==-1)
    return NULL;
  tree_ptr p;
  if(father==NULL){
    father=node_init(2^(h)+1);
    p=father;
  }else{
    if(flag<0){
      p=node_init(father->element-(2^(h)-1));
      father->left=p;
    }else{
      p=node_init(father->element+(2^(h)-1)+2);
      father->right=p;
    }
  }
  p->left=create_max(h-1,p,-1);
  p->right=create_max(h-1,p,1);
  p->height=h;
  return p;
}

SEARCH_TREE delete_left_min(SEARCH_TREE T)
{
  tree_ptr p,tmp;
  for(p=T;p->left->left!=NULL;p=p->left)
    ;
  tmp=p->left;
  p->left=NULL;
  free(tmp);
return T
}

SEARCH_TREE max2avl(SEARCH_TREE T)
{
  if(T->left!=NULL)
    T->left=max2val(T->left);
  if(T->right!=NULL)
    T->right=max2val(T->right);
  if(T->left==NULL&&T->right==NULL)
    return T;
  else
    return delete_left_min(T);
}

SEARCH_TREE create_avl_min(int h)
{
  tree_ptr t=create_max(h,NULL,0);
  t=max2avl(t);
}
