#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

/*K&R p69
  ~/pro/prac/cprolang/ch4/e3to10.c*/

struct stack_record
{
  int size;
  int top;
  int *array;
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
  S->array=(int *) malloc(sizeof(int)*max_elements);
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

void push(int x,STACK S)
{
  if(S->top==(S->size-1))
    error("Stack is FULL");
  else
    S->array[++(S->top)]=x;
}

int top(STACK S)
{
  if(is_empty(S))
    printf("Stack is EMPTY");
  else
    return S->array[S->top--];  
}

void get_eva(char *,int,STACK);
void putin(int,char *,int);

main()
{
  int c;
  char buf[BUFSIZE];
  int buftop=EMPTY;
  STACK S=create_stack(20);
  while(c=getchar()!=EOF){
    printf("%c\n",(char)c);
    if(c==' '){
      get_eva(buf,buftop,S);
    }
    else{
      if(isdigit(c)||c=='+'||c=='-'||c=='*'||c=='/')
	putin(c,buf,buftop);
    }
  }
  int re=top(S);
  if(is_empty(S)){
    printf("result:%d",re);
  }else{
    printf("this postfix expressions is error!");
  }
}

void get_eva(char *buf,int buftop,STACK S)
{
  if(buftop==EMPTY)
    return;
  if(isdigit(buf[0])){
    buf[buftop+1]='\0';
    int value=atoi(buf);
    push(value,S);
  }else{
    if(buf[0]=='+'){
      int p1=top(S);
      int p2=top(S);
      push(p1+p2,S);
    }else if(buf[0]=='-'){
      int p1=top(S);
      int p2=top(S);
      push(p2-p1,S);      
    }else if(buf[0]=='*'){
      int p1=top(S);
      int p2=top(S);
      push(p1*p2,S);
    }else if(buf[0]=='/'){
      int p1=top(S);
      if(p1==0){
	printf("CAN NOT divid ZERO!");
	exit(-1);
      }
      int p2=top(S);
      push(p2/p1,S);
    }else{
      buf[buftop+1]='\0';
      printf("CAN NOT define what this MEAN:%s",buf);
    }
  }
}

void putin(int c,char *buf,int bufsize)
{
  buf[++bufsize]=c;
}
