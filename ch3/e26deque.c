struct deque_record
{
  unsigned int max_size;
  unsigned int front;
  unsigned int rear;
  unsigned int size;
  int *array;
};

typedef struct deque_record *DEQUE;

DEQUE create_deque(int maxsize)
{
  D=(DEQUE) malloc(sizeof(struct deque_record));
  if(Q==NULL){
    printf("CAN NOT create deque:NO space\n");
    exit(-1);
  }
  D->array=(int *) malloc(sizeof(int)*maxsize);
  if(D->array==NULL){
    printf("CAN NOT create deque:NO space\n");
    exit(-1);
  }
  D->max_size=maxsize;
  D->size=0;
  D->front=1;
  D->rear=0;
  return D;
}

int is_empty(DEQUE D)
{
  return(D->size==0);
}

int is_full(DEQUE D)
{
  return(D->size==D->max_size)
}

void make_null(DEQUE D)
{
  D->q_size=0;
  D->q_front=1;
  D->q_rear=0;
}

void push(int x,DEQUE D)
{
  if(is_full(D))
    printf("DEQUE is FULL\n");
  else{
    if(D->front+1==D->max_size){
      D->front=0;
    }else
      D->front++;
    D->array[D->front]=x;
    D->size++;
  }
}

int pop(DEQUE D)
{
  if(is_empty(D))
    printf("DEUE is EMPTY\n");
  else{
    int top=D->array[D->front];
    if(D->front==0){
      D->front=D->max_size-1;
    }else
      D->front--;
    D->size--;
    return(top);
  }
}

void inject(int x,DEQUE D)
{
  if(is_full(D))
    printf("DEQUE is FULL\n");
  else{
    if(D->rear==0){
      D->rear=D->max_size-1;
    }else
      D->rear--;
    D->array[D->rear]=x;
    D->size++;
  }
}

int eject(DEQUE D)
{
  if(is_empty(D))
    printf("DEUE is EMPTY\n");
  else{
    int top=D->array[D->rear];
    if(D->rear==D->max_size-1){
      D->rear=0;
    }else
      D->rear++;
    D->size--;
    return(top);
  }
}
