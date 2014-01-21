#include<stdlib.h>
#include<stdio.h>
#include<time.h>

/*3种算法：*/
void fillrand(int *,int);
void usedrand(int *,int);
void swaprand(int *,int);

void showexec(void (*)(int *,int),int,int);

main()
{
  printf("第一种:\n");
  showexec(fillrand,250,2000);
  printf("%%%%%%%%%%%%%%\n第二种:\n");
  showexec(usedrand,2500,80000);
  printf("%%%%%%%%%%%%%%\n第三种:\n");
  showexec(fillrand,10000,640000);
}

double exectime(void (*)(int *,int),int *,int);

void showexec(void (*f)(int *,int),int begin,int end)
{
  int i;
  for(i=begin;i<=end;i=i*2){
  double total=0,this;
    int k=0;
    for(;k<10;k++){
      int p[i];
      this=exectime(f,p,i);
      printf("%d:%f\n",i,this);
      total+=this;
    }
  double ave=total/10;
  printf("%d:ave:%f\n",i,ave);
  printf("-------------------------\n");
  }
}

/*运行时间*/
double exectime(void (*f)(int *,int),int *p,int n)
{
  time_t before,after;
  before=time(NULL);
  (*f)(p,n);
  after=time(NULL);
  return difftime(after,before);
}

/*第一种算法
  加入没有重复出现的数字*/
void fillrand(int *p,int n)
{
  int i,k;
  for(i=0;i<n;i++){
    int randint=rand();
/* printf("%d\n",randint); */

    for(k=0;k<i;k++){
      if(p[k]==randint){               /*重复*/
	randint=rand();                /*新随机数*/
	k=0;                           /*重头比较*/
      }
    }
    p[i]=randint;
  }
  p[n]='\0';
}

/*第二个算法
  用array记录使用*/
void usedrand(int *p,int n)
{
  int used[n],i;
  for(i=0;i<n;i++)
    used[n]=0;

  for(i=0;i<n;i++){
    while(1){
      int randint=(int)((float)(rand())*n/RAND_MAX);
      if(used[randint]==0){
	p[i]=randint;
	used[randint]=1;
	break;
      }
    }
  }
  p[n]='\0';
}

/*第三个算法
  交换*/
void swaprand(int *p,int n)
{
  int i;
  for(i=0;i<n;i++)
    p[n]=i+1;

  for(i=1;i<n;i++){
    int index=(int)((float)(rand())*n/RAND_MAX);
    int tmp=p[i];
    p[i]=p[index];
    p[index]=tmp;
  }
  p[n]='\0';
}
