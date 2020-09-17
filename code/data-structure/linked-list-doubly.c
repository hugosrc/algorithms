#include <stdio.h>
#include <stdlib.h>

// In C, structure of a node in doubly linked list can be given as:
struct Node {
  struct Node* prev;
  int data;
  struct Node* next;
};

/*
  prev -> Previous Node
  data -> Node Value
  next -> Next Node
*/

// Function to print list values
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

// Inserts a new node in the first position of the list
void push(struct Node** headRef, int data) {
  struct Node* newNode = malloc(sizeof(struct Node));

  newNode->prev = NULL;
  newNode->data = data;
  newNode->next = (*headRef);

  if ((*headRef) != NULL)
  {
    (*headRef)->prev = newNode;
  }
  
  (*headRef) = newNode;
}

// Add a new node before a given node
void addBefore(struct Node** headRef, struct Node* nextNode, int data) {
  if (nextNode == NULL)
  {
    printf("The next node cannot be null\n");
    return;
  }
  
  struct Node* newNode = malloc(sizeof(struct Node));

  newNode->data = data;
  newNode->prev = nextNode->prev;
  nextNode->prev = newNode;

  newNode->next = nextNode;

  if (newNode->prev != NULL) 
  {
    newNode->prev->next = newNode;
  } else {
    *headRef = newNode;
  }
}

// Function that returns the number of elements in a list
int length(struct Node* head) {
  int count = 0;
  while (head != NULL)
  {
    count++;
    head = head->next;
  }
  
  return count;
}

int main() {
  struct Node* head = NULL;
  
  push(&head, 21);
  push(&head, 5);
  push(&head, 8);
  addBefore(&head, head->next, 100);
  addBefore(&head, head->next->next, 0);

  printList(head);
  printf("List length: %d\n", length(head));

  /*
    Output:
    Traversal in forward direction:  8 -> 100 -> 0 -> 5 -> 21
    Traversal in reverse direction:  21  -> 5  -> 0  -> 100  -> 8 
    List length: 5
  */

  return 0;
}