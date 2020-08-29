#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool search(struct Node *head, int target) {
  struct Node* current = head;

  while (current != NULL)
  {
    if (current->data == target)
    {
      return true;
    }
    
    current = current->next;
  }
  

  return false;
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

  search(head, 0) ? printf("Exists\n") : printf("No exists\n"); // Output: No exists

  search(head, 10) ? printf("Exists\n") : printf("No exists\n"); // Output: Exists

  return 0;
}