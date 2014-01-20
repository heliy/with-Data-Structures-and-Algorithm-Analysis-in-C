#include<stdio.h>
#include<stdlib.h>

#define N 100
#define K N/2

int array[N];
int result[K];

void seq(int *,int);
void sselect(int *,int *,int,int);
void print(int *,int);

int main(){
  seq(array,N);
  sselect(array,result,K,N);
  print(result,K);
}

void print(int *result,int k)
{
  int i;
  for(i=0;i<k;i++)
    printf("%d\n",result[i]);  
}

void insert(int *,int,int);
void sort(int *,int);

/*将se中的数选出k个放入re中*/
void sselect(int *se,int *re,int k,int n)
{
  int i;                            /*i对于se标数*/
  for(i=0;i<k;i++){                 /*读入前k个*/
    re[i]=se[i];
  }
  re[i]='\r';

  sort(re,k);                         /*前k个排序*/
  int min=re[k-1];                  /*降序排序后最后一数最小*/

  while(i<n){              /*剩下的*/
    if(se[i]>min) {                    /*可加入*/
      insert(re,se[i],k);
      min=re[k-1];
    }
    i++;
  }
}

/*将n插入p，保持降序*/
void insert(int *p,int n,int k)
{
  int end;
  int i;

  for(i=0;p[i]>n;i++)
    ;

  for(end=k-1;end>i;end--){
    p[end]=p[end-1];
  }

  p[i]=n;

}

void swap(int *,int,int);

void sort(int *n,int k)
{
  int i,j;
  for(i=0;i<k;i++){
    for(j=i;j<k;j++){
      if(n[i]<n[j]){
        swap(n,i,j);
      }
    }
  }
}

void swap(int *n,int i,int j)
{
  int tmp=n[i];
  n[i]=n[j];
  n[j]=tmp;
}

/*n个随机整数生成入p*/
void seq(int *p,int n)
{
  int i;
  for(i=0;i<n;i++){
    *(p+i)=rand();
  }
  *(p+i)='\r';
}
