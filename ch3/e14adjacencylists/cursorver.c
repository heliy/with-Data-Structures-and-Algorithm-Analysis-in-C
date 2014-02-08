#define MAXNODE 100

struct node{
  int adjacency[MAXNODE];
};

typedef int LIST;
typedef int position;
struct node CURSOR_SPACE[MAXNODE];

void insert(position a,position b)
{
  CURSOR_SPACE[a-1].adjacency[b-1]=1;
}


