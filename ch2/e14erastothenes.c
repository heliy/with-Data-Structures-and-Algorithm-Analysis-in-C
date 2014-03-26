#include<stdio.h>
#include<math.h>
#include<stdlib.h>

/* O(n) */

void erastothenes(int);

int main()
{
  erastothenes(300);
}

void erastothenes(int d)
{
  int *a=(int *) malloc(sizeof(int)*(d+1));
  int i,k;
  for(i=2;i<d;i++){
    a[i]=1;
  }
  for(i=2;i<d;i++){
    if(a[i]==0)
      continue;
    else{
      printf("%d\n",i);
      for(k=i;k<(d+1);k+=i){
	a[k]=0;
      }
    }
  }

  free(a);
}
