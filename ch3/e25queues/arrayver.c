struct queue_record
{
  unsigned int q_max_size;
  unsigned int q_front;
  unsigned int q_rear;
  unsigned int q_size;
  element_type *q_array;
};

typedef struct queue_record *QUEUE;

int is_empty(QUEUE Q)
{
  return(Q->q_size==0);
}

void make_null(QUEUE Q)
{
  Q->q_size=0;
  Q->q_front=1;
  Q->q_rear=0;
}

unsigned int succ(unsigned int value,QUEUE Q)
{
  if(++value==Q->q_max_size)
    value=0;
  return value;
}

void enqueue(element_type x,QUEUE Q)
{
  if(Q->q_max_size==Q->q_size)
    error("Queue is FULL");
  else{
    Q->q_size++;
    Q->q_rear=succ(Q->q_rear,Q);
    Q->q_array[Q->q_rear]=x;
  }
}


