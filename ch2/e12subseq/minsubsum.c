#include<stdio.h>

/* O(n) */

int minsubsum(int *,int);

void main()
{
  int a[7]={1,-3,4,-7,0,-3,10};
  printf("min subsequence sum:%d\n",minsubsum(a,7));
}

int minsubsum(int *a,int n)
{
  int minsum=a[0],thissum=a[0],i;
  for(i=1;i<n;i++){
    if(a[i]<0){
      if(thissum<0){
	thissum+=a[i];
      }else{
	thissum=a[i];
      }
    }else{
      if(thissum>0){
	if(thissum>a[i])
	  thissum==a[i];
      }else{
	thissum+=a[i];
      }
    }
    if(thissum<minsum){
      minsum=thissum;
    }
  }

  return minsum;
}

