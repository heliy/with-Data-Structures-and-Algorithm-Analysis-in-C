struct stack_record
{
  int size;
  int top;
  int min;
  int min_loc;
  int *array;
};

typedef struct stack_record *STACK;
#define EMPTY (-1)
#define MIN_STACK_SIZE 4
#define BUFSIZE 10
#define MAX 99999

STACK create_stack(int max_elements)
{
  STACK S;
  if(max_elements<MIN_STACK_SIZE)
    printf("Stack size is too small");
  S=(STACK) malloc(sizeof(struct stack_record));
  if(S==NULL){
    printf("Out of space!");
    exit(-1);
  }
  S->array=(int *) malloc(sizeof(int)*max_elements);
  if(S->array==NULL){
    printf("Out of space!");
    exit(-1);
  }
  S->top=EMPTY;
  S->size=max_elements;
  S->min=MAX;
  S->min_loc=EMPTY;
  return(S);
}

void dispose_stack(STACK S)
{
  if(S!=NULL)
    {
      free(S->array);
      free(S);
    }
}

int is_empty(STACK S)
{
  return (S->top==EMPTY);
}

void make_null(STACK S)
{
  S->top=EMPTY;
  S->min=MAX;
  S->min_loc=EMPTY;
}

void push(int x,STACK S)
{
  if(S->top==(S->size-1))
    error("Stack is FULL");
  else{
    S->array[++(S->top)]=x;
    if(x<S->min){
      S->min=x;
      S->min_loc=S->top;
    }
  }
}

int top(STACK S)
{
  if(is_empty(S))
    printf("Stack is EMPTY\n");
  else
    return S->array[S->top];  
}

void pop(STACK S)
{
  if(is_empty(S))
    printf("Stack is EMPTY\n");
  else{
    int i=S->top;
    S->top--;  
    if(i==S->min_loc){
      S->min=MAX;
      for(i=0;i<=S->top;i++)
	if(S->min>S->array[i]){
	  S->min=S->array[i];
	  S->min_loc=i;
	}
    }
  }
}

int find_min(STACK S)
{
  return(S->min);
}
