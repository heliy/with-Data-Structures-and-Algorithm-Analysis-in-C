typedef struct node *node_ptr;
struct node;
typedef node_ptr LIST;
typedef node_ptr postion;

int is_empty(LIST L);
int is_last(postion p,LIST L);
postion find(element_type x,LIST L);
void delete(element_type x,LIST L);
void insert(element_type x,LIST L,postion p);
void delete_list(LIST L);
void find_prev(element_type x,LIST L);




