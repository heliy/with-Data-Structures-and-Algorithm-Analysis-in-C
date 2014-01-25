struct stack_record
{
  unsigned int stack_size;
  int top_of_stack;
  element_type *stack_array;
};

typedef struct stack_record *STACK;
#define EMPTY_TOS (-1)

STACK create_stack(unsigned int max_elements)
{
  STACK S;
  if(max_elements<MIN_STACK_SIZE)
    error("Stack size is too small");
  S=(STACK) malloc(sizeof(struct stack_record));
  if(S==NULL)
    fatal_error("Out of space!");
  S->stack_array=(element_type *) malloc(sizeof(element_type)*max_elements);
  if(S->stack_array==NULL)
    fatal_error("Out of space!");
  S->top_of_stack=EMPTY_TOS;
  S->stack_size=max_elements;
  return(S);
}

void dispose_stack(STACK S)
{
  if(S!=NULL)
    {
      free(S->stack_array);
      free(S);
    }
}

int is_empty(STACK S)
{
  return (S->top_of_stack==ENPTY_TOS);
}

void make_null(STACK S)
{
  S->top_of_stack=EMPTY_TOS;
}

void push(element_type x,STACK S)
{
  if(S->top_of_stack==(S->stack_size-1))
    error("Stack is FULL");
  else
    S->stack_array[++(S->top_of_stack)]=x;
}

element_type top(STACK S)
{
  if(is_empty(S))
    error("Stack is EMPTY");
  else
    return S->stack_array[S->top_of_stack];  
}

void pop(STACK S)
{
  if(is_empty(S))
    error("Stack is EMPTY");
  else
    S->top_of-stack--;  
}
