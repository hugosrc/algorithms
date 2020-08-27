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

// Given a reference to the head of a list and  a position, deletes the node at the given position 
void deleteNode(struct Node** headRef, int position) {
  // checks that the linked list is empty
  if (*headRef == NULL) return;

  // stores the head of the node
  struct Node* temp = *headRef;

  // check if the position is 0, if yes delete and change the head
  if (position == 0)
  {
    *headRef = temp->next;
    free(temp);
    return;
  }

  // finds the previous node of the node to be deleted
  for (int i = 0; temp != NULL && i < position - 1; i++)
  {
    temp = temp->next;
  }

  // checks if the node is not found
  if (temp == NULL || temp->next == NULL) return;
  
  // stores the pointer to the next node to be deleted
  struct Node* next = temp->next->next;
  
  // unlink the node from linked list 
  free(temp->next);

  // unlink the deleted node from list
  temp->next = next;
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

  deleteNode(&head, 1);

  printf("Created Linked list is >>> ");
  printList(head); // Linked list 1->5->8->12->NULL

  /*
    Output:
    Created Linked list is >>>  1  10  5  8  12 
    Created Linked list is >>>  1  5  8  12  
  */

  return 0;
}