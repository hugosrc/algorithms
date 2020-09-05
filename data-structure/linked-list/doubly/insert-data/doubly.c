#include <stdio.h>
#include <stdlib.h>

/*
  In C, structure of a node in doubly linked list can be given as:
    prev -> Previous Node
    data -> Node Value
    next -> Next Node
*/
struct Node {
  struct Node* prev;
  int data;
  struct Node* next;
};

// Inserts a new node in the first position of the list
void push(struct Node** headRef, int data) {
  // Allocates memory for the new node
  struct Node* newNode = malloc(sizeof(struct Node));

  // Defines the previous node
  newNode->prev = NULL;
  // Defines the node value
  newNode->data = data;
  // Defines the value of the next node
  newNode->next = (*headRef);

  // If the reference is not null, define the new node as the previous node of the next node
  if ((*headRef) != NULL)
  {
    (*headRef)->prev = newNode;
  }
  
  // Defines the new node as the first node
  (*headRef) = newNode;
}

// Function to print the list
void printList(struct Node* node) {
  struct Node* last;
  printf("Traversal in forward direction: ");
  while (node != NULL)
  {
    printf(" %d ->", node->data);
    last = node;
    node = node->next;
  }
  printf("\n");
  
  printf("Traversal in reverse direction: ");
  while (last != NULL)
  {
    printf(" <- %d ", last->data);
    last = last->prev;
  }
  printf("\n");
}

int main() {
  struct Node* head = NULL;
  
  push(&head, 21);
  push(&head, 8);
  push(&head, 10);
  push(&head, 5);
  push(&head, 1);

  printList(head);

  /*
    Output:

    Traversal in forward direction:  1 -> 5 -> 10 -> 8 -> 21 -> NULL
    Traversal in reverse direction:  NULL <- 21  <- 8  <- 10  <- 5  <- 1 
  */

  return 0;
}