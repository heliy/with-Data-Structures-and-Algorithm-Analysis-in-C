typedef struct node *node_ptr;

struct node
{
  element_type element;
  node_ptr next;
};

typedef node_ptr LIST;
typedef node_ptr postion;

int is_empty(LIST L)
{
  return(L->next==NULL);
}

int is_last(postion p,LIST L)
{
  /* postion last; */
  /* for(last=L->next;last->next!=NULL;last=last->next) */
  /*   ; */
  /* return(last==p); */
  return(p->next==NULL);
}

postion find(element_type x,LIST L)
{
  postion loc;
  for(loc=L->next;loc!=NULL&&loc->element!=x;loc=loc->next)
    ;
  return loc;
}

void delete(element_type x,LIST L)
{
  postion pre,tmp;
  for(pre=L->next;pre->next!=NULL&&pre->next->element!=x;pre=pre->next)
    ;
  if(pre->next!=NULL){
    tmp=pre->next;
    pre->next=tmp->next;
    free(tmp);
  }
}

void insert(element_type x,LIST L,postion p)
{
  postion tmp=(postion) malloc(sizeof(struct node));
  if(tmp==NULL){
    printf("No space!\n")
      exit(-1);
  }else{
    tmp->element=x;
    tmp->next=p->next;
    p->next=tmp;
  }
}

void delete_list(LIST L)
{
  position p,tmp;
  for(p=L->next;p!=NULL;tmp=p->next){
    free(p);
    p=tmp; 
  }
  L->next=NULL;
}



