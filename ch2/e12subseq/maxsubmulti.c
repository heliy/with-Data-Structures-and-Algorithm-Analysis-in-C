#include<stdio.h>

#define MIN_VALUE (-99999)

/* O(nlogn)
   递归 分而治之
 */

long int max_sub_multi(int *,int,int);

int main()
{
  int a[8]={10,-7,-1,-4,5,-8,0,5};
  long int multi=max_sub_multi(a,0,7);
  printf("%ld\n",multi);
}

long int max(long int,long int,long int);
int have_zero(int*,int,int);
int first_last_non_zero(int*,int);
int last_first_non_zero(int*,int);
int first_negtive(int*,int);
int last_negtive(int*,int);
long int multi(int*,int,int);

long int max_sub_multi(int *a,int left,int right)
{
  if(left==right){
    return ((long int) a[left]);
  }

  int i,center=(left+right)/2;
  long int max_left_multi=max_sub_multi(a,left,center);
  long int max_right_multi=max_sub_multi(a,center+1,right);

  long int total_multi=1;
  int left_non_zero,right_non_zero;
  if(have_zero(a,left,center))
    left_non_zero=last_first_non_zero(a,center);
  else
    left_non_zero=left;
  if(have_zero(a,center,right))
    right_non_zero=first_last_non_zero(a,center+1);
  else
    right_non_zero=right;

  for(i=left_non_zero;i<=right_non_zero;i++){
    total_multi*=a[i];
  }
  if(total_multi<0){
    int left_negtive=first_negtive(a,left_non_zero);
    int right_negtive=last_negtive(a,right_non_zero);

    if(left_negtive>center){
      total_multi/=multi(a,right_negtive,right_non_zero);
    }else if(right_negtive<center+1){
      total_multi=multi(a,left_non_zero,left_negtive);
    }else{
      long int left_multi=multi(a,left_non_zero,left_negtive);
      long int right_multi=multi(a,right_negtive,right_non_zero);
      if(left_multi<right_multi)
	total_multi/=right_multi;
      else
	total_multi/=left_multi;
    }
  }

  long int max_multi=max(max_left_multi,max_right_multi,total_multi);
  /* printf("%d %d/%d %d:%ld\n",left,right,left_non_zero,right_non_zero,max_multi); */
  return max_multi;
}

long int max(long int a,long int b,long int c)
{
  if(a>=b&&a>=c)
    return a;
  else if(b>=c)
    return b;
  else
    return c;
}

int first_negtive(int *a,int left)
{
  for(;a[left]>0;left++)
    ;
  return left;
}

int last_negtive(int *a,int right)
{
  for(;a[right]>0;right--)
    ;
  return right;
}

long int multi(int*a,int left,int right)
{
  long int m;
  for(m=1;left<=right;left++){
    m*=a[left];
  }
  return m;
}

int first_last_non_zero(int *a,int left)
{
  int i;
  for(i=left;a[i]!=0;i++)
    ;
  if(i==left)
    return left;
  else
    return --i;
}

int last_first_non_zero(int *a,int right)
{
  int i;
  for(i=right;a[i]!=0;i--)
    ;
  if(i==right)
    return right;
  else
    return ++i;
}

int have_zero(int *a,int left,int right)
{
  for(;left<=right;left++)
    if(a[left]==0)
      return 1;
  return 0;
}
