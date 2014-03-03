typedef struct tree_node *tree_ptr;
struct tree_node{
  element_type element;
  tree_ptr first_child;
  tree_ptr next_sibling;
};
typedef tree_ptr TREE;

void traverse(TREE T)
{
  if(T==NULL)
    return;
  print_element(T->element);
  traverse(T->first_child);
  traverse(T->next_sibling);
}

