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

// deletes the first occurrence of key in linked list
void deleteNode(struct Node** headRef, int key) {
  // Store head node 
  struct Node* temp = *headRef, *prev;

  // checks if the main node itself contains the key to be deleted
  if (temp != NULL && temp->data == key)
  {
    // change the head value
    *headRef = temp->next;
    // deallocates the allocated memory portion
    free(temp);
    return;
  }

  // Search for the key to be deleted, keep track of the 
  // previous node as we need to change 'prev->next' 
  while (temp != NULL && temp->data != key)
  {
    prev = temp;
    temp = temp->next;
  }

  // if no node is found with the expected key returns
  if (temp == NULL) return;
  // change link from previous node
  prev->next = temp->next;

  // deallocates the allocated memory portion
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