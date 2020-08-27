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

void deleteNode(struct Node** headRef, int key) {
  struct Node* temp = *headRef, *prev;

  if (temp != NULL && temp->data == key)
  {
    *headRef = temp->next;
    free(temp);
    return;
  }

  while (temp != NULL && temp->data != key)
  {
    prev = temp;
    temp = temp->next;
  }

  if (temp == NULL) return;
  
  prev->next = temp->next;

  free(temp);
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

  deleteNode(&head, 8);

  printf("\nCreated Linked list is >>> ");
  printList(head); // Linked list 1->10->5->12->NULL

  /*
    Output:
    Created Linked list is >>>  1  10  5  8  12
    Created Linked list is >>>  1  10  5  12
  */

  return 0;
}