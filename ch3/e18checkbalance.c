#include<stdio.h>
#include<stdlib.h>

#define EMPTY (-1)
#define MAXSIZE 20

struct stack_record{
  int top;
  int array[MAXSIZE];
  char arround[MAXSIZE*MAXSIZE];
};

typedef struct stack_record * STACK;

STACK create_stack()
{
  STACK S;
  S=(STACK) malloc(sizeof(struct stack_record));
  if(S==NULL){
    printf("OUT OF SPACE!!");
    exit(-1);
  }
  S->top=EMPTY;
  return(S);
}

void dispose_stack(STACK S)
{
  if(S!=NULL)
    free(S);
}

int is_empty(STACK S)
{
  return(S->top==EMPTY);
}

void make_null(STACK S)
{
  S->top=EMPTY;
}

void push(int x,char *a,STACK S)
{
  if(S->top==MAXSIZE-1){
    printf("ERROR:STACK is FULL!");
  }else{
    S->array[++(S->top)]=x;
    int i;
    for(i=MAXSIZE*(S->top);i<MAXSIZE;i++){
      S->arround[MAXSIZE*(S->top)+i]=a[i];
    }
  }
}

int top(STACK S)
{
  if(is_empty(S))
    printf("Stack is EMPTY");
  else
    return S->array[S->top];  
}

char * print_top_arround(STACK S)
{
  if(is_empty(S))
    printf("STACK is EMPTY");
  else{
    int i=S->top*MAXSIZE;
    for(;i<(S->top+1)*MAXSIZE;i++)
      printf("%c",S->arround[i]);
    printf("%c",'\n');
  }
}

void pop(STACK S)
{
  if(is_empty(S))
    error("Stack is EMPTY");
  else
    S->top--;  
}

char arround[MAXSIZE]="--------------------";

int get_ele();
void print_err(STACK);
int is_pare(int,int);

int main()
{
  int p;
  STACK S=create_stack();
  while(p=get_ele()!=EOF){
    if(is_pare(p,top(S))==1){
      pop(S);
    }else{
      push(p,arround,S);
    }
  }
  if(is_empty(S))
    print_err(S);
}

int contains[6]={'[',']','(',')','/','*'};

void print_err(STACK S)
{
  int p=top(S);
  printf("error in '%c':",contains[p]);
  print_top_arround(S);
}

int is_pare(int a,int b){
  if(a+1!=b||a%2==1)
    return 1;
  else
    return 0;
}

void insert(char c)
{
  int i;
  for(i=0;i<MAXSIZE;i++){
    arround[i]=arround[i+1];
  }
  arround[i]=c;
}
int saki_flag=0;

int get_ele(){
  char c;

  while(c=getchar()){
    if(c==EOF)
      return EOF;

    insert(c);

    if(saki_flag==1){
      saki_flag=0;
      if(c=='*'){
	return 4;
      }
    }else if(saki_flag==2){
	saki_flag=0;
      if(c=='/'){
	saki_flag=0;
	return 5;
      }else{
	saki_flag=0;
      }
    }

    if(c=='['){
      return 0;
    }else if(c==']'){
      return 1;
    }else if(c=='('){
      return 2;
    }else if(c==')'){
      return 4;
    }else if(c=='/'){
      saki_flag=1;
      continue;
    }else if(c=='*'){
      saki_flag=2;
      continue;
    }else{
      continue;
    }
  }
}
