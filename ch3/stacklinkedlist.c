typedef struct node *node_ptr;
struct node
{
  element_type element;
  node_ptr next;
};

typedef node_ptr STACK;

int is_empty(STACK S)
{
  return(S->next==NULL);
}

STACK create_stack(void)
{
  STACK S;
  S=(STACK) malloc(sizeof(struct node));
  if(S==NULL)
    fatal_error("OUT OF SPACE!");
  return S;
}

void make_null(STACK S)
{
  if(S!=NULL)
    S->next=NULL;
  else
    error("Must use create_stack first");
}

void push(element_type x,STACK S)
{
  node_ptr cre;
  cre=(node_ptr) malloc(sizeof(struct node));
  if(tmp==NULL)
    fatal_error("Out of space!");
  else{
    cre->element=x;
    cre->next=S->next;
    S->next=cre;
  }
}

element_type top(STACK S)
{
  if(is_empty(S))
    error("Stack is EMPTY!");
  else
    return S->next->element;
}

void pop(STACK S)
{
  if(is_empty(S))
    error("Stack is EMPTY!");
  else{
    node_ptr t;
    t=S->next;
    S->next=t->next;
    free(t);
  }
}

