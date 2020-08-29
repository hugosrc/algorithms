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

int length(struct Node* head) {
  int count = 0;
  struct Node* current = head;

  while (current != NULL)
  {
    count++;
    current = current->next;
  }
  
  return count;
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

  printf("The number of nodes on that list is: %d\n", length(head));
  
  /*
    Output:
    The number of nodes on that list is: 5
  */  

  return 0;
}