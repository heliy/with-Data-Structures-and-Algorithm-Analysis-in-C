struct stack_record
{
  int single_size;
  int top_a;
  int top_b;
  int top_c;
  char *array;
};

typedef struct stack_record *THREESTACKS;
#define MIN_STACK_SIZE 5

THREESTACKS create2stacks(int single_max)
{
  THREESTACKS S;
  if(max_chars<MIN_STACK_SIZE)
    printf("Stack size is too small");
  S=(THREESTACKS) malloc(sizeof(struct stack_record));
  if(S==NULL){
    printf("Out of space!");
    exit(-1);
  }
  S->array=(char *) malloc(sizeof(char)*single_max*3);
  if(S->array==NULL){
    printf("Out of space!");
    exit(-1);
  }
  S->single_size=single_max;
  S->top_a=-1;
  S->top_b=S->single_size-1;
  S->top_c=S->single_size*2-1;
  return(S);  
}

void dispose_stack(THREESTACKS S)
{
  if(S!=NULL)
    {
      free(S->array);
      free(S);
    }
}

int is_a_empty(THREESTACKS S)
{
  return(S->top_a==(-1));
}

int is_b_empty(THREESTACKS S)
{
  return(S->top_b==S->single_size-1);
}

int is_c_empty(THREESTACKS S)
{
  return(S->top_c==S->single_size*2-1);
}

void make_null(THRESTACKS S)
{
  S->top_a=-1;
  S->top_b=S->single_size-1;
  S->top_c=S->single_size*2-1;
}

int is_a_full(THRESTACKS S)
{
  return((S->top_a+1)>=S->single_size);
}

int is_b_full(THRESTACKS S)
{
  return((S->top_b+1)>=S->single_size*2);
}

int is_c_full(THRESTACKS S)
{
  return((S->top_c+1)>=S->single_size*3);
}

void push_a(char c,THRESTACKS S)
{
  if(is_a_full(S))
    printf("STACK A is FULL\n");
  else
    S->array[++(S->top_a)]=c;
}

void push_b(char c,THRESTACKS S)
{
  if(is_b_full(S))
    printf("STACK B is FULL\n");
  else
    S->array[++(S->top_b)]=c;
}

void push_c(char c,THRESTACKS S)
{
  if(is_c_full(S))
    printf("STACK C is FULL\n");
  else
    S->array[++(S->top_b)]=c;
}

char top_a(THRESTACKS S)
{
  if(is_a_empty(S))
    printf("stack A is EMPTY\n");
  else
    return(S->array[S->top_a]);
}

char top_b(THRESTACKS S)
{
  if(is_b_empty(S))
    printf("stack B is EMPTY\n");
  else
    return(S->array[S->top_b]);
}

char top_c(THRESTACKS S)
{
  if(is_c_empty(S))
    printf("stack C is EMPTY\n");
  else
    return(S->array[S->top_c]);
}

void pop_a(THRESTACKS S)
{
  if(is_a_empty(S))
    printf("stack A is EMPTY\n");
  else
    S->top_a--;
}

void pop_b(THRESTACKS S)
{
  if(is_b_empty(S))
    printf("stack B is EMPTY\n");
  else
    S->top_b--;
}

void pop_c(THRESTACKS S)
{
  if(is_c_empty(S))
    printf("stack C is EMPTY\n");
  else
    S->top_c--;
}

