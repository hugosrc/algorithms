#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

struct Node {
  int data;
  struct Node* next;
};

// Function to print list values
void printList(struct Node *node) {
  while (node != NULL) {
    printf("%d ", node -> data);
    node = node->next;
  }
  printf("\n");
}

// Method is used to push an element at the beginning of the list
void push(struct Node** headRef, int data) {
  struct Node* newNode = malloc(sizeof(struct Node));
  
  newNode->data = data;
  newNode->next = (*headRef);

  (*headRef) = newNode;
}

// Adds a new element after a given element
void addAfter(struct Node* previous, int data) {
  if (previous == NULL)
  {
    printf("The previous node cannot be null");
    return;
  }

  struct Node* newNode = malloc(sizeof(struct Node));

  newNode->data = data;
  newNode->next = previous->next;
  previous->next = newNode;
}

// Adds a new element to the end of the list
void append(struct Node** headRef, int data) {
  struct Node* newNode = malloc(sizeof(struct Node));
  struct Node* lastElement = *headRef;

  newNode->data = data;
  newNode->next = NULL;

  if (*headRef == NULL)
  {
    *headRef = newNode;
    return;
  }

  while (lastElement->next != NULL)
  {
    lastElement = lastElement->next;
  }
  
  lastElement->next = newNode;
}

// Function that returns the number of elements in a list
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

// Checks if the list with has an element with a certain value
bool contains(struct Node* head, int data) {
  struct Node* current = head;

  while (current != NULL)
  {
    if (current->data == data)
    {
      return true;
    }
    
    current = current->next;
  }
  
  return false;
}

// Deletes the element at a given position in the list
void deleteByPosition(struct Node** headRef, int index) {
  if (*headRef == NULL) return;
  
  struct Node* temp = *headRef;

  if (index == 0)
  {
    *headRef = temp->next;
    free(temp);
    return;
  }

  for (int i = 0; temp != NULL && i < index - 1; i++) {
    temp = temp->next;
  } 

  if (temp == NULL || temp->next == NULL) return;
  
  struct Node* next = temp->next->next;
  free(temp->next);

  temp->next = next;  
}

// Deletes an element with a certain value in the list
void deleteByValue(struct Node** headRef, int value) {
  struct Node* temp = *headRef;
  struct Node* prev = NULL;

  if (temp != NULL && temp->data == value)
  {
    *headRef = temp->next;
    free(temp);
    return;
  }
  
  while (temp != NULL && temp->data != value)
  {
    prev = temp;
    temp = temp->next;
  }
  
  if (temp == NULL) return;
  
  prev->next = temp->next;
  free(temp);
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

// Returns the element of a given position in the list
int get(struct Node* head, int index) {
  struct Node* current = head;

  int count = 0;
  while (current != NULL)
  {
    if (count == index)
    {
      return current->data;
    }
    

    count++;  
    current = current->next;
  }
  
  assert(0);
}

int main(void) {
  struct Node* head = NULL;

  push(&head, 5);
  push(&head, 7);
  push(&head, 1);
  append(&head, 10);
  push(&head, 2);
  addAfter(head->next, 9);
  // Linkedlist: 2 -> 1 -> 9 -> 7-> 5 -> 10

  deleteByPosition(&head, 2);
  deleteByValue(&head, 7);

  printf("The number of nodes on that list is: %d\n", length(head));
  printList(head);
  printf("does the list contain a node with a value of 5? ");
  printf(contains(head, 5) ? "true\n" : "false\n");
  printf("The node value at position 2 is: %d\n", get(head, 2));

  deleteList(&head);
  printf("Linked list deleted.\n");

  /*
    Output:
    The number of nodes on that list is: 4
    2 1 5 10 
    does the list contain a node with a value of 5? true
    The node value at position 2 is: 5
    Linked list deleted.
  */  

  return 0;
}