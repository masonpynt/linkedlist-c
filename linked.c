#include <stdio.h>
#include <stdlib.h>
#include "linked.h"

node_t *create_node(int val) {

  node_t *new_node = malloc(sizeof(node_t));
  
  new_node->val = val;
  new_node->next = NULL;
  return new_node;

}

int list_size(node_t *head) {
  int size = 0;
  node_t *cur = head;

  while(cur != NULL) {
    size++;
    cur = cur->next;
  }
  
  return size;
}

void list_print(node_t *head) {
  node_t * cur = head;

  while (cur != NULL) {
    printf("%d\n", cur->val);
    cur = cur->next;
  }
}


void push_front(node_t **head, int val) {
  // pointer to the new node
  node_t *new_node = create_node(val);

  new_node->next = *head;
  *head = new_node;
}

int value_at(node_t *head, int index) {
  node_t * cur = head;

  int pos = 0;

  while(cur->next != NULL && pos < index) {
    cur = cur->next;
    pos++;
  }

  if (cur != NULL && pos == index) {
    return cur->val;
  } else {
    return 1;
  }
}

int firstval(node_t *head) {

  if (head == NULL) {
    return 1;
  }

  return head->val;
}

int lastval(node_t *head) {

  if (head == NULL) {
    return -1;
  }

  node_t * cur = head;
  while(cur->next != NULL) {
    cur = cur->next;
  }
  

  return cur->val;
}

int pop_front(node_t **head) {
  int remval = -1;

  node_t * next_node = NULL;

  if (head == NULL) {
    return 1;
  }

  next_node = (*head)->next;
  remval = (*head)->val;
  free(*head);
  *head = next_node;

  return remval;
}


void push_last(node_t **head, int val) {
  if (*head == NULL) {
    *head = create_node(val);
    return;
  }

  node_t *cur = *head;
  while (cur->next != NULL) {
    cur = cur->next;
  }

  cur->next = create_node(val);

}

int pop_last(node_t *head) {

  int remval = 0;

  if (head->next == NULL) {
    remval = head->val;
    free(head);
    return remval;
  }

  node_t * cur = head;

  while(cur->next != NULL) {
    cur = cur->next;
  }

  remval = cur->next->val;
  free(cur->next);
  cur->next = NULL;

  return remval;
}

void delete_index(node_t **head, int index) {

  if (*head == NULL) {
    return;
  }

  // If index is 0, store head in temp and delete head
  if (index == 0) {
    node_t *temp = *head;

    *head = (*head)->next;
    free(temp);
    return;
  }
  
  // Initialise ptrs = current at head, and *prev starts at NULL
  node_t *cur = *head;
  node_t *prev = NULL;

  int i = 0;
  
  // While current is not null and i is less than the index passed
  while (cur != NULL && i < index) {
    prev = cur;
    cur = cur->next;
    i++;
  }
  
  // if index out of bounds return
  if (cur == NULL) {
    return;
  }
  
  // Set previous node to next, skipping over current node
  // Free the cur
  prev->next = cur->next;
  free(cur);
}

int value_n_from_end(node_t *head, int n) {
  node_t *main_ptr = head;
  node_t *ref_ptr = head;
  
  int i = 0;

  while(i < n) {
    if (ref_ptr == NULL) {
      return -1;
    }
    ref_ptr = ref_ptr->next;
    i++;
  }

  while(ref_ptr->next != NULL) {
    main_ptr = main_ptr->next;
    ref_ptr = ref_ptr->next;
  }
  if (main_ptr != NULL) {
    return main_ptr->val;
  }
  return -1;
}

// Reversal
// iterate through linked list;
// prev and next start as null, curr is head
// loop through, store next as cur->next
// reverse current's node pointer
// move prev and curr one ahead

void reverse(node_t **head) {
  node_t *cur = *head;
  node_t *prev = NULL;
  node_t *next = NULL;

  while(cur != NULL) {

    // Store next before manipulation
    next = cur->next;
    
    // store 'next' at current position as prev
    cur->next = prev;

    // Store previous at current
    prev = cur;
    
    // Move cur 1 across
    cur = next;
    
  }
  // Set new head to prev
  *head = prev;
}

int main() {
  
  node_t *head = NULL;

  push_front(&head, 3);
  push_front(&head, 2);
  push_front(&head, 1);
  push_last(&head, 45);

  list_print(head);
  printf("Value n from end: %d\n", value_n_from_end(head, 1));

  reverse(&head);
  
  printf("\nPost surgery\n");
  list_print(head);

  printf("Value n from end: %d\n", value_n_from_end(head, 1));

  node_t *cur = head;
  node_t *next = NULL;

  while(cur != NULL) {
    next = cur->next;
    free(cur);
    cur = next;
  }

  head = NULL;

  return 0;
}
