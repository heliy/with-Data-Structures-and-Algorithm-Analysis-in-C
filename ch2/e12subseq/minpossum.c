#include<stdio.h>
#define MAX_NUMBER 999999

/* O(n)

 */

int minpossum(int *,int);

int main()
{
  int a[8]={10,-7,-1,-4,5,8,0,3};
  int sum=minpossum(a,8);
  if(sum>0){
    printf("min positive subsequence sum:%d\n",sum);
  }else{
    printf("No positive number in this sequence\n");
  }
  return 0;
}

int minpossum(int *a,int n)
{
  int minsum,thissum,i,negsum,k;
  if(a[0]>0){
    thissum=a[0];
    minsum=a[0];
  }else{
    thissum=0;
    minsum=MAX_NUMBER;
  }
  for(i=1;i<n;i++){
    if(a[i]>0){
      if(a[i-1]<0){
	for(negsum=a[i],k=i-1;a[k]<0&&k>-1;k--){
	  negsum+=a[k];
	  if(negsum>0){
	    if(negsum<minsum)
	      minsum=negsum;
	  }else{
	    break;
	  }
	}
      }else{
        if(thissum>a[i]){
	  thissum=a[i];
        }else{
	  thissum+=a[i];
        }
      }
    }else{
      if(thissum+a[i]>0){
	thissum+=a[i];
      }else{
	thissum=0;
      }
    }
    if(thissum==0)
      continue;
    if(thissum<minsum){
      minsum=thissum;
    }
  }

  if(minsum==MAX_NUMBER){
    return -1;
  }else{
    return minsum;
  }
}
