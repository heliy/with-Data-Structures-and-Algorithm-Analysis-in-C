#include<stdio.h>

typedef struct
{
  int int_array[MAX_DIG];
  unsigned int high_dig;
  int sign_flag;
}* INTERGER;

void plus(INTERGER,INTERGER,INTERGER);
void subt(INTERGER,INTERGER,INTERGER);
void multi(INTERGER,INTERGER,INTERGER);
void divid(INTERGER,INTERGER,INTERGER);

/* void init(INTERGER INT) */
/* { */
  
/* } */

void to_zero(INTERGER INT)
{
  INT->sign_flag=0;
  INT->high_dig=0;
  int i;
  for(i=0;i<MAX_DIG;i++)
    int_array[i]=0;
}

int get_sign(INTERGER INT)
{
  if(INT->sign_flag>0)return 1;
  else if(INT->sign_flag==0)return 0;
  else return -1;
}

unsigned int max(unsigned int a,unsigned int b)
{
  return (a>b)?a:b;
}

void plus(INTERGER int1,INTERGER int2,INTERGER int_plus)
{
  to_zero(int_plus);
  unsigned int i,high;
  int re,tmp=0,sign1=get_sign(int1),sign2=get_sign(int2);
  high=max(int1->high_dig,int2->high_dig);
  for(i=0;i<high;i++){
    re=sign1*(int1->int_array[i])+sign2*(int2->int_array[i])+tmp;
    if(re>0&&re<10)
      tmp=0;
    else{
      if(re<0){
        tmp=-1;
        re=10+re;
      }
      if(re<0){
        tmp=-2;
        re=10+re;
      }
      if(re>=10){
        tmp=1;
        re=re-10;
      }
    }
    int_plus->int_array[i]=re;
  }
  if(tmp<0){
    int_plus->high_dig=high+1;
    int_plus->int_array[int_plus->high_dig]=(-tmp);
    for(i=0;i<high;i++)
      int_plus->int_array[i]=10-int_plus->int_array[i];
    int_plus->sign_flag=-1;
  }else{
    int_plus->high_dig=high+tmp;
    if(tmp>0)
      int_plus->int_array[int_plus->high_dig]=(tmp);
    int_plus->sign_flag=1;    
  }
}

void subt(INTERGER int1,INTERGER int2,INTERGER int_sub)
{
  INTERGER int2p=(INTERGER) malloc(sizeof(struct node));
  int2p->int_array=int2->int_array;
  int2p->high_dig=int2->high_dig;
  int2p->sign_flag=-1*(int2->sign_flag);
  plus(int1,int2p,int_sub);
  free(subt);
}

void single_multi(INTERGER int1,int a,INTERGER int_multi)
{
  if(a<0||a>9)
    exit(-1);
  to_zero(int_multi);
  int_multi->sign_flag=get_sign(int1);
  int i,re,tmp=0;
  for(i=0;i<int1->high_dig;i++){
    re=int1->int_array[i]*a+tmp;
    tmp=(int)re/10;
    re=re%10;
    int_multi->int_array[i]=re;
  }
  if(tmp>0){
    int_multi->high_dig=int1->high_dig+1;
    int_multi->int_array[int_multi->high_dig]=tmp;
  }else{
    int_multi->high_dig=int1->high_dig;    
  }
}

void right_move(INTERGER int1,int m)
{
  int1->high_dig=int1->high_dig+m;
  int i;
  for(i=int1->high_dig;i>=m;i--){
    int1->int_array[i]=int1->int_array[i-m];
  }
  for(;i>=0;i--){
    int1->int_array[i]=0;
  }
  int1->int_array[int1->high_dig]='\0';
}

void multi(INTERGER int1,INTERGER int2,INTERGER int_multi)
{
  to_zero(int_multi);
  int_multi->sign_flag=get_sign(int1)*get_sign(int2);
  INTERGER add,tmp;
  int k,i;
  for(i=0;i<int2->high_dig;i++){
    k=int2->int_array[i];
    single_multi(int1,k,tmp);
    right_move(tmp,i);
    plus(tmp,add,int_multi);
    add=int_multi;
  }
}

void one_plus(INTERGER int1){
  int i,flag;
  for(i=0;i<int1->high_dig&&flag!=10;i++){
    int1->int_array[i]++;
    flag=10-int1->int_array[i];
  }
  if(flag==10){
    int1->high_dig++;
    int1->int_array[int1->high_dig]=1;
  }
}

void divid(INTERGER int1,INTERGER int2,INTERGER int_divid)
{
  to_zero(int_divid);
  
}
