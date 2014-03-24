
#include<stdio.h>

#define MAX_LONG 30

void print_real(double);

void main()
{
  double d1=12345.678;
  double d2=-4567.3455;
  print_real(d1);
  print_real(d2);
}

/* output: */
/* 0.12345678e+5 */
/* -0.45673455e+4 */


void print_real(double d)
{
  int i=0,pow=0,cord;
  if(d<0){
    printf("-");
    d*=(-1);
  }
  while(d>1){
    d/=10;
    pow++;
  }
  printf("0.");
  while(((int)(d*100))%10!=0){
    printf("%d",(int)(d*10));
    d=(d*10)-(int)(d*10);
  }
  printf("%d",(int)(d*10));
  printf("e+%d\n",pow);
}
