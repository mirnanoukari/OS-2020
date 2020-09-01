#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int value;
  struct Node *next;
} Node;

typedef struct linked_list
{
  Node *head;
} linked_list;

linked_list *
create_linked_list ()
{
  linked_list *list = (linked_list *) malloc (sizeof (linked_list));
  list->head = NULL;
  return list;
}

void
print_list (linked_list * list)
{
  if (!list || !list->head)
    return;
  Node *item = list->head;
  while (item)
    {
      printf ("%d ", item->value);
      item = item->next;
    }
  printf ("\n");
}

void
insert_node (linked_list * list, int value)
{
  if (!list)
    return;

  Node *node = (Node *) malloc (sizeof (Node));
  node->value = value;
  node->next = NULL;

  if (!list->head)
    list->head = node;
  else
    {
      Node *item = list->head;
      while (item->next)
	item = item->next;
      item->next = node;
    }
}

void
delete_node (linked_list * list, int value)
{
  if (!list || !list->head)
    return;
  Node *node = list->head;
  if (node->value == value)
    {
      list->head = node->next;
      free (node);
    }
  else
    {
      while (!node->next || node->next->value != value)
	node = node->next;
      if (!node->next)
	return;
      Node *deleted = node->next;
      node->next = deleted->next;
      free (deleted);
    }
}

int
main ()
{
  linked_list *list = create_linked_list ();
  insert_node (list, 3);
  insert_node (list, 7);
  insert_node (list, 9);
  insert_node (list, 8);
  insert_node (list, 1);

  print_list (list);

  delete_node (list, 3);

  print_list (list);

  delete_node (list, 8);

  print_list (list);

  return 0;
}

