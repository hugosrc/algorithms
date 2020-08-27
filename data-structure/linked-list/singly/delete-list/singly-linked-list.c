#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

void push(struct Node** headRef, int newData) {
  struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
  newNode -> data = newData;
  newNode -> next = (*headRef);
  (*headRef) = newNode;
}

void deleteList(struct Node** headRef) {
  struct Node* current = *headRef;
  struct Node* next;

  while (current != NULL)
  {
    next = current->next;
    free(current);
    current = next;
  }

  *headRef = NULL;
}

void printList(struct Node *node) {
  while (node != NULL) {
    printf(" %d ", node -> data);
    node = node -> next;
  }
}

int main() {
  struct Node* head = NULL;

  push(&head, 12);
  push(&head, 8);
  push(&head, 5);
  push(&head, 10);
  push(&head, 1);

  printf("Created Linked list is >>> ");
  printList(head); // Linked list 1->10->5->8->12->NULL

  deleteList(&head);
  
  printf("\nLinked list deleted.\n");

  /*
    Output:
    
    Created Linked list is >>>  1  10  5  8  12 
    Linked list deleted.
  */
  
  return 0;
}