/*a*/

int rand_not_in(int m,TREE T)
{
  int i;
  do{
    i=rand_int(1,m);
  }while(find(i,T)!=NULL);
  return i;
}

/* b */

int weight(TREE t)
{
  if(t==NULL)
    return 0;
  else
    return(weight(t->left)+weight(t->right)+1);
}

int rand_alre_in(TREE T)
{
  if(T==NULL)
    return NULL;
  int i=rand_int(1,weight(T));
  if(i<weight(T->left))
    return(rand_alre_in(T->left));
  else if(i<weight(T)-1)
    return(rand_alre_in(T->left));
  else
    return T->element;
}

/* c */
/* alpha>=3 */
