#include <stdio.h>

struct Node {
  int data;
  struct Node* next;
};

int main() {
  struct Node* head = NULL;
  struct Node* second = NULL;
  struct Node* third = NULL;

  head = malloc(sizeof(struct Node));
  second = malloc(sizeof(struct Node));
  third = malloc(sizeof(struct Node));

  head -> data = 1;
  second -> data = 2;
  third -> data = 3;

  head -> next = second;
  second -> next = third;
  third -> next = NULL;

  printf("O List item values:\n\n");
  printf("Data value, Head: %d\n", head -> data);
  printf("Data value, Second: %d\n", second -> data);
  printf("Data value, Third: %d\n\n", third -> data);

  printf("O Values of the next list items:\n\n");
  printf("Item value after head - %d\n", head -> next -> data);
  printf("Item value after head - %d\n", second -> next -> data);
  printf("Item value after head - %d\n", third -> next -> data);

  /*
    Output:

    O List item values:

    Data value, Head: 1
    Data value, Second: 2
    Data value, Third: 3

    O Values of the next list items:

    Item value after head - 2
    Item value after head - 3
    Item value after head - null
  */

  return 0;
}