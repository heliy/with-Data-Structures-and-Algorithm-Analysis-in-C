/* 最大子序列问题
   算法1:递归实现（O(nlogn)
   算法2:重置0（O(n)
 */

int max_sub_sum(int*,int,int);

/* 分为三个子问题：前半部分最大，后半部分最大，跨中间最大 */
int algo1_recu(int *a,int n)
{
  return max_sub_sum(a,0,n-1);
}

int max(int,int,int);

int max_sub_sum(int *a,int left,int right)
{
  if(left==right){   		/* 基本 */
    if(a[left]>0)
      return a[left];
    else
      return 0;
  }

  int i,center=(left+right)/2;
  int max_left_sum=max_sub_sum(a,left,center); /* 前半部分最大 */
  int max_right_sum=max_sub_sum(a,center+1,right); /* 后半部分最大 */

  /* 包含前半部分最后一个数值的最大和 */
  int max_left_border_sum=0,left_border_sum=0;
  for(i=center;i>=left;i--){
    left_border_sum+=a[i];
    if(left_border_sum>max_left_border_sum)
      max_left_border_sum=left_border_sum;
  }

  /* 包含后半部分第一个数值的最大和 */
  int max_right_border_sum=0,right_border_sum=0;
  for(i=center+1;i<=right;i++){
    right_border_sum+=a[i];
    if(right_border_sum>max_right_border_sum)
      max_right_border_sum=right_border_sum;
  }

  return max(max_left_sum,max_right_sum,max_left_border_sum+max_right_border_sum);
}

int max(int a,int b,int c)
{
  if(a>=b&&a>=c)
    return a;
  else if(b>=c)
    return b;
  else
    return c;
}


/* 当和小于0时以前记录无效
   即加入原有记录与下一个正数和一定小于该正数
 */
int algo2_turn20(int *a,int n)
{
  int i,max_sum,this_sum;
  for(i=max_sum=this_sum=0;i<n;i++){
    this_sum+=a[i];
    if(this_sum>max_sum){
      max_sum=this_sum;
    }
    if(this_sum<0){
      this_sum=0;
    }
  }
  return max_sum;
}
