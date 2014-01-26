typedef struct node * node_ptr;
struct node;
typedef node_ptr DLIST;
typedef node_ptr postion;

DLIST create(void);
int is_empty(DLIST L);
int is_last(position p);
position find(element_type x,DLIST L);
void delete(element_type x,DLIST L);
void insert(element_type x,LIST L,position p);


