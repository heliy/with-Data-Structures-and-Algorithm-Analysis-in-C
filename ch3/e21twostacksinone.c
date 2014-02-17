struct stack_record
{
  int size;
  int top_a;
  int top_b;
  char *array;
};

typedef struct stack_record *TWOSTACKS;
#define MIN_STACK_SIZE 10

TWOSTACKS create2stacks(int max_chars)
{
  TWOSTACKS S;
  if(max_chars<MIN_STACK_SIZE)
    printf("Stack size is too small");
  S=(TWOSTACKS) malloc(sizeof(struct stack_record));
  if(S==NULL){
    printf("Out of space!");
    exit(-1);
  }
  S->array=(char *) malloc(sizeof(char)*max_elements);
  if(S->array==NULL){
    printf("Out of space!");
    exit(-1);
  }
  S->size=max_elements;
  S->top_a=-1;
  S->top_b=S->size;
  return(S);  
}

void dispose_stack(TWOSTACKS S)
{
  if(S!=NULL)
    {
      free(S->array);
      free(S);
    }
}

int is_a_empty(TWOSTACKS S)
{
  return(S->top_a==(-1));
}

int is_b_empty(TWOSTACKS S)
{
  return(S->top_b==S->size);
}

int is_empty(TWOSTACKS S)
{
  return(is_a_empty(S)&&is_b_empty(S));
}

void make_null(TWOSTACKS S)
{
  S->top_a=-1;
  S->top_b=S->size;
}

int is_full(TWOSTACKS S)
{
  return((S->top_a+1)>=S->top_b);
}

void push_a(char c,TWOSTACKS S)
{
  if(is_full(S))
    printf("STACK is FULL\n");
  else
    S->array[++(S->top_a)]=c;
}

void push_b(char c,TWOSTACKS S)
{
  if(is_full(S))
    printf("STACK is FULL\n");
  else
    S->array[--(S->top_b)]=c;
}

char top_a(TWOSTACKS S)
{
  if(is_a_empty(S))
    printf("stack A is EMPTY\n");
  else
    return(S->array[S->top_a]);
}

char top_b(TWOSTACKS S)
{
  if(is_b_empty(S))
    printf("stack B is EMPTY\n");
  else
    return(S->array[S->top_b]);
}

void pop_a(TWOSTACKS S)
{
  if(is_a_empty(S))
    printf("stack A is EMPTY\n");
  else
    S->top_a--;
}

void pop_b(TWOSTACKS S)
{
  if(is_b_empty(S))
    printf("stack B is EMPTY\n");
  else
    S->top_b++;
}
