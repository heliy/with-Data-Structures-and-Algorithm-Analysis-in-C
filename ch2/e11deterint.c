#include<stdio.h>

/* O(logn) */

int ieqai(int *,int,int);

void main()
{
  int a[5]={0,2,4,5,7};
  int loc=ieqai(a,0,5);
  if(loc>=0){
    printf("Have,like %dth is %d\n",loc+1,a[loc]);
  }else{
    printf("No int i exists a[i]==i\n");
  }
}

int ieqai(int *a,int bef,int aft)
{
  if(bef==aft){
    if((bef+1)==a[bef])
      return bef;
    else
      return -1;
  }

  int mid=(bef+aft)/2;
  if((mid+1)==a[mid])
    return mid;
  else if((mid+1)<a[mid])
    return ieqai(a,bef,mid);
  else
    return ieqai(a,mid+1,aft);
}
