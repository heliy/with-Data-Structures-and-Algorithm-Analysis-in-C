#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

/* 多位数的还是有问题 */

struct stack_record
{
  int size;
  int top;
  char *array;
};

typedef struct stack_record *STACK;
#define EMPTY (-1)
#define MIN_STACK_SIZE 4
#define BUFSIZE 10

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
  S->array=(char *) malloc(sizeof(char)*max_elements);
  if(S->array==NULL){
    printf("Out of space!");
    exit(-1);
  }
  S->top=EMPTY;
  S->size=max_elements;
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
}

void push(char x,STACK S)
{
  if(S->top==(S->size-1))
    error("Stack is FULL");
  else
    S->array[++(S->top)]=x;
}

char top(STACK S)
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
  else
    S->top--;  
}

void print_stack(STACK S)
{
  printf("%s\n",S->array);
}

void in2posfix(char *,char *);

main()
{
  char a[30]="1 + 2 * 3 + ( 4 * 5 + 6 ) * 7";
  char b[30];
  in2posfix(a,b);
  printf("%s\n",b);
}

char *  itoa(int,char*);
char * popstack(int,STACK,char*);

void in2posfix(char *in,char *pos)
{
  char *b=pos;
  STACK S=create_stack(20);
  int i=0,mae=0;
  while(in[i]!='\0'){
    printf("in:%c\n",in[i]);
    if(isdigit(in[i])){
      mae=mae*10+(in[i]-'0');
    }
    if(in[i]==' '){
      if(mae!=0){
	pos=itoa(mae,pos);
      }
      mae=0;
    }
    if(in[i]=='('){
      push('(',S);
    }
    if(in[i]==')'){
      pos=popstack(')',S,pos);
    }
    if(in[i]=='*'){
      pos=popstack('*',S,pos);
      push('*',S);
    }
    if(in[i]=='+'){
      pos=popstack('+',S,pos);
      push('+',S);
    }
    print_stack(S);
    i++;
  }
  if(mae!=0){
    pos=itoa(mae,pos);    
  }
  pos=popstack('o',S,pos);
  *pos='\0';
  pos=b;
}

char * itoa(int x,char *cp)
{
  if(x>9){
    cp=itoa(x/10,cp);
  }
  x=x%10;
  *cp='0'+x;
  cp++;
  *cp=' ';
  cp++;
  return cp;
}

char *popin(STACK S,char* pos)
{
  char c=top(S);
  *pos=c;
  pos++;
  pop(S);
  *pos=' ';
  pos++;
  return pos;
}

char * popstack(int flag,STACK S,char *pos)
{
  char c;
  if(flag==')'){
    while((c=top(S))!='('){
      pos=popin(S,pos);
    }
    pop(S);
  }
  if(flag=='*'){
    while((c=top(S))=='*'){
      pos=popin(S,pos);
    }
  }
  if(flag=='+'){
    while((c=top(S))=='*'||c=='+'){
      pos=popin(S,pos);
   }
  }
  if(flag=='o'){
    while(!is_empty(S)){
      pos=popin(S,pos);
    }
  }
  return pos;
}
