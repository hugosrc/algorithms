#include <limits.h> 
#include <stdio.h> 
#include <stdlib.h> 

struct Stack {
  int top;
  unsigned capacity;
  int* array;
};

// creates a new stack
struct Stack* createStack(unsigned capacity) {
  struct Stack* stack = malloc(sizeof(struct Stack));

  stack->capacity = capacity;
  stack->top = -1;
  stack->array = malloc(stack->capacity * sizeof(int));

  return stack;
};

// checks if the stack is full
int isFull(struct Stack* stack) {
  return stack->top == stack->capacity - 1;
}

// checks if the stack is empty
int isEmpty(struct Stack* stack) {
  return stack->top == -1;
}

// add an item to the stack
void push(struct Stack* stack, int item) {
  if (isFull(stack)) return;
  
  stack->array[++stack->top] = item;

  printf("%d pushed to stack\n");
}

// removes an item from the stack
int pop(struct Stack* stack) {
  if (isEmpty(stack)) return INT_MIN;
  
  return stack->array[stack->top--];
}

// returns top element of stack
int peek(struct Stack* stack) {
  if (isEmpty(stack)) return INT_MIN;
  
  return stack->array[stack->top];
}

int main(void)
{
  struct Stack* stack = createStack(100);

  push(stack, 80);
  push(stack, 25);
  push(stack, 42);

  printf("%d popped from stack\n", pop(stack));
  printf("Top element is %d\n", peek(stack));

  /*
    Output:

    80 pushed to stack
    25 pushed to stack
    42 pushed to stack
    42 popped from stack
    Top element is 25
  */

  return 0;
}
