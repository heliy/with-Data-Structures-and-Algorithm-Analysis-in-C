/* 
  a.
   对[a(1)a(2)……a(k)],hash_pre=((a(1)*32+a(2))*32+a(3))*32……+a(k)=32^k*a(1)+……+32^(k-i+1)*a(i)+……+a(k)
   对[a(2)a(3)……a(k)a(k+1)],hash_next=32^k*a(2)+……+32^(k-i+1)*a(i+1)+……+a(k+1)=(hash_pre-32^k(a1))*32+a(k+1)
   所以，hash_next=(hash_pre-32^ka(1))*32+a(k+1)

  b.
   假设没有多余的错误匹配，即每次用hash值即可找到正确的结果
   对长度为k的字符串求hash值为O(k)
   由a题，对总长为n的字符串上的小k段hash值计算在遍历时只需常数极时间，hash表的建立为O(n)

  c.
   即两个不同的字符串hash值相同的概率非常小

  d.
 */

#include<string.h>
#include<math.h>

typedef unsigned int HASH_VALUE;

HASH_VALUE hash(char *key,int len)
{
  HASH_VALUE val=0;
  int i;
  for(i=0;i<len;i++)
    val=(val<<5)+*key++;
  return(hash_val);
}

HASH_VALUE next_hash(HASH_VALUE,char*,int,long int);

char * sub_string(char *sub,char *lon,int k,int n)
{
  HASH_VALUE criterion=hash(sub,k);
  HASH_VALUE prev=0;
  long int pow5=(long int) pow(32,k);
  int i=0;
  do{
    HASH_VALUE compare;
    if(prev==0)
      compare=hash(lon,k);
    else
      compare=next_hash(prev,lon-1,k,pow5);

    if(compare==criterion&&strncmp(sub,lon,k))
      return lon;
    else{
      lon++;
      i++;
    }
  }while(i<n-k)
}

HASH_VALUE next_hash(HASH_VALUE prev,char* ap,int len,long int power)
{
  return((prev-power*(*ap))<<5)+(*(ap+len));
}

/* 
  e.
  f.
   ?
 */
