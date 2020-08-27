#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

void push(struct Node** headRef, int newData) {
  // allocate node 
  struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

  // defines the value of the new node
  newNode -> data = newData;

  // defines next as the old head
  newNode -> next = (*headRef);

  // defines the head as the new node
  (*headRef) = newNode;
}

void insertAfter(struct Node* prevNode, int newData) {
  // checks if the previous node exists   
  if (prevNode == NULL) {
    printf("The previous node cannot be null");
    return;
  }
  
  // allocate node
  struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

  // defines the value of the new node
  newNode->data = newData;

  // defines the link of the new node as being the link of the previous one
  newNode->next = prevNode->next;

  // defines the link of the previous node as the new one
  prevNode->next = newNode;
}

void append(struct Node** headRef, int newData) {
  // allocate node
  struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
  
  // defines the variable "last" as being the head
  struct Node *last = *headRef;

  // defines the value of the new node
  newNode->data = newData;

  // sets the link to NULL
  newNode->next = NULL;

  // checks if the head is null, if yes the new node will be the first
  if (*headRef == NULL) 
  {
    *headRef = newNode;
    return;
  }

  // loops through all the elements in the list
  while (last->next != NULL)
  {
    // define "last" as the last node
    last = last->next;
  }
  
  // defines the link of the last node as the new node
  last->next = newNode;
  return;
}

void printList(struct Node *node) {
  while (node != NULL) {
    printf(" %d ", node -> data);
    node = node -> next;
  }
}

int main() {
  struct Node* head = NULL;

  // Inserts 5 at the end of the list
  append(&head, 5); // 5->NULL

  // insert 10 at the beginning of the list
  push(&head, 10); // 10->5->NULL

  // Inserts 12 at the end of the list
  append(&head, 12); // 10->5->12->NULL

  // Insert 1, after 5
  insertAfter(head->next, 8); // 10->5->8->12->NULL

  // insert 1 at the beginning of the list
  push(&head, 1); // 1->10->5->8->12->NULL

  printf("Created Linked list is >>> ");
  printList(head);

  /*
    Output:
    Created Linked list is >>>  1  10  5  8  12
  */

  return 0;
}