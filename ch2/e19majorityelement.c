#include<stdio.h>
#include<stdlib.h>

#define NA (-99999)

int majo_element(int *,int);

int main()
{
  int a[12]={3,4,2,4,2,2,2,2,2,2,4};
  int a_majo=majo_element(a,12);
  if(a_majo==NA)
    printf("There is no majority element.\n");
  else
    printf("Majority element is %d.\n",a_majo);
}

int candidate(int *,int);
void array_copy(int *,int *,int);

int majo_element(int *a,int n)
{
  int *b=(int *)malloc(sizeof(int)*(n+1));
  array_copy(a,b,n);
  int value=candidate(b,n);
  free(b);
  if(value==NA)
    return NA;
  int i,count=0,loc;
  for(i=0;i<n;i++){
    if(a[i]==value){
      loc=i;
      count++;
    }
  }
  if(count*2>n)
    return a[loc];
  else
    return NA;
}

void ahead(int *,int,int);

int candidate(int *a,int n)
{
  if(n==1){
    return a[0];
  }

  if(n==2){
    if(a[0]==a[1]){
      return a[0]; 
    }else
      return NA;
  }

  int i,s;
  for(i=0,s=n;i<s-1;){
    if(a[i]=a[i+1]){
      ahead(a+i,1,s);
      s--;
      i++;
    }else{
      ahead(a+i,2,s);
      s-=2;
    }
  }

  return candidate(a,s);
}

void ahead(int *a,int s,int n)
{
  int i;
  for(i=0;i<n-s;i++){
    a[i]=a[i+s];
  }
  a[i]='\0';
}

void array_copy(int *a,int *b,int n)
{
  int i;
  for(i=0;i<n;i++)
    b[i]=a[i];
  b[i]='\n';
}
