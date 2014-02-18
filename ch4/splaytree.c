typedef struct splay_node * splay_ptr;

struct splay_node{
  element_type element;
  splay_ptr left;
  splay_ptr right;
  splay_ptr parent;
};

typedef splay_ptr SEARCH_TREE;

void zig_left(splay_ptr x)
{
  splay_ptr p,B;
  p=x->parent;
  B=x->right;
  x->right=p;
  x->parent==NULL;
  p->parent=x; //这个不应该放在外面吗？
  p->left=B;   //同上
  if(B!=NULL){
    B->parent=p;
    /* p->parent=x;  */
    /* p->left=B;    */
  }
}

void zig_right(splay_ptr x)
{
  splay_ptr p,A;
  p=x->parent;
  A=x->left;
  x->left=p;
  x->parent=NULL;
  p->parent=x; 
  p->right=A;
  if(A!=NULL){
    A->parent=p;
  }
}

void single_rotate(splay_ptr x)
{
  if(x->parent->left==x)
    zig_left(x);
  else
    zig_right(x);
}

void zig_zig_left(splay_ptr x)
{
  splay_ptr p,g,B,C,ggp;
  p=x->parent;
  g=p->parent;
  B=x->right;
  C=p->right;
  ggp=g->parent;

  x->right=p;
  p->parent=x;
  p->right=g;
  g->parent=p;

  p->left=B;
  if(B!=NULL)
    B->parent=p;

  g->left=C;
  if(C!=NULL)
    C->parent=g;

  x->parent=ggp;
  if(ggp!=NULL)
    if(ggp->left==g)
      ggp->left=x;
    else
      ggp->right=x;
}

void zig_zig_right(splay_ptr x)
{
  splay_ptr p,g,ggp,B,C;
  p=x->parent;
  g=p->parent;
  ggp=g->parent;
  B=p->left;
  C=g->left;

  x->parent=p;
  p->left=x;
  p->parent=g;
  g->left=p;

  x->right=B;
  if(B!=NULL)
    B->parent=x;

  p->right=C;
  if(C!=NULL)
    C->parent=p;

  g->parent=ggp;
  if(ggp!=NULL)
    if(ggp->left=x)
      ggp->left=g;
    else
      ggp->right=g;
}

void zig_zag_left(splay_ptr x)
{
  splay_ptr p,g,ggp,B,C;
  p=x->parent;
  g=p->parent;
  ggp=g->parent;
  B=x->left;
  C=x->right;

  x->left=p;
  p->parent=x;
  x->right=g;
  g->parent=x;

  p->right=B;
  if(B!=NULL)
    B->parent=p;

  g->left=C;
  if(C!=NULL)
    C->parent=g;

  x->parent=ggp;
  if(ggp->left==g)
    ggp->left=x;
  else
    ggp->right=x;
}

void zig_zag_right(splay_ptr x)
{
  splay_ptr p,g,ggp,B,C;
  p=x->parent;
  g=p->parent;
  ggp=g->parent;
  B=x->left;
  C=x->right;

  x->left=g;
  g->parent=x;
  x->right=p;
  p->parent=x;

  g->left=B;
  if(B!=NULL)
    B->parent=g;

  p->right=C;
  if(C!=NULL)
    C->parent=p;

  x->parent=ggp;
  if(ggp->left==g)
    ggp->left=x;
  else
    ggp->right=x;

}

void double_rotate(splay_ptr x)
{
  if(x->parent->right==x){
    if(x->parent->parent->left==x->parent)
      zig_zag_left(x);
    else
      zig_zig_right(x);
  }else{
    if(x->parent->parent->right==x->parent)
      zig_zag_right(x);
    else
      zig_zig_left(x);
  }
}

void splay(splay_ptr current)
{
  splay_ptr father;
  father=current->parent;
  while(father!=NULL){
    if(father->parent==NULL)
      single_rotate(current);
    else
      double_rotate(current);
  }
}
