#include<stdio.h>
#include<stdlib.h>

#define SIZE 4

/*不知道怎么查看组合是否为单词，先找出所有可能情况*/
int main()
{
  int i,j;
  for(i=0;i<SIZE;i++)
    for(j=0;j<SIZE;j++){
      int flags[4]={1-j,SIZE-j,1-i,SIZE-i};
      if(flags[0]>1){     /*上*/
	printf("(%d,%d,up)\n",i,j);
      } 
      if(flags[1]>1){     /*下*/
	printf("(%d,%d,down)\n",i,j);	
      }
      if(flags[2]>1){     /*左*/
	printf("(%d,%d,left)\n",i,j);	
      }
      if(flags[3]>1){     /*右*/
	printf("(%d,%d,right)\n",i,j);	
      }
      if(flags[0]>1&&flags[2]>1){     /*上左*/
	printf("(%d,%d,up-left)\n",i,j);
      }	
      if(flags[0]>1&&flags[3]>1){     /*上右*/
	printf("(%d,%d,up-right)\n",i,j);	
      }
      if(flags[1]>1&&flags[2]>1){     /*下左*/
	printf("(%d,%d,down-left)\n",i,j);	
      }
      if(flags[1]>1&&flags[3]>1){     /*下右*/
	printf("(%d,%d,down-right)\n",i,j);	
      }
    }
}

