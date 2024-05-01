#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>

typedef struct node {
  int val;
  struct node *next;
} node_t;

node_t *create_node(int val);
int list_size(node_t *head);
void list_print(node_t *head);
void push_front(node_t **head, int val);
int value_at(node_t *head, int index);
int firstval(node_t *head);
int lastval(node_t *head);
int pop_front(node_t **head);
void push_last(node_t **head, int val);
int pop_last(node_t *head);
void delete_index(node_t **head, int index);
void reverse(node_t **head);
int value_n_from_end(node_t *head, int n);

#endif
