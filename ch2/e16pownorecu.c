#include<stdio.h>
#include<stdlib.h>

long int npow(int,int);

int main()
{
  printf("%ld\n",npow(4,5));
}

long int npow(int x,int n)
{
  int i;
  long int *a=(long int *)malloc(sizeof(long int)*(n+1));
  a[0]=1;
  a[1]=x;
  for(i=2;i<=n;i++){
    if(i%2==0)
      a[i]=a[i/2]*a[i/2];
    else
      a[i]=a[i/2]*a[i/2]*x;
  }

  long int re=a[n];
  free(a);
  return re;
}

/* 17 2^B */

