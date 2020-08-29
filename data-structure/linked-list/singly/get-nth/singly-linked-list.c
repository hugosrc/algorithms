#include <stdio.h>
#include <stdlib.h>
#include <assert.h>;

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

int getNth(struct Node *head, int index) {
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
  // 1->10->5->8->12

  printf("The element of index 4 is: %d\n", getNth(head, 4));

  printf("The element of index 8 is: %d\n", getNth(head, 8));

  /*
    Output:
    The element of index 4 is: 12
    getNth: Assertion `0' failed.
  */

  return 0;
}