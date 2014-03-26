#include<stdio.h>
#include<math.h>

int is_prime(int);

int main(){
  int d;
  while((scanf("%d",&d))!=EOF){
    if(is_prime(d)){
      printf("%d is a prime number.\n",d);
    }else{
      printf("%d is NOT a prime number.\n",d);
    }
  }
  return 0;
}

int is_prime(int d)
{
  int lim=sqrt(d),i;

  if(d==1)
    return 1;
  for(i=2;i<lim;i++){
    if(d%i==0){
      return 0;
    }
  }
  return 1;
}

/* O(N^(1/2))
   B=logN
   2^(B/2)
 */
