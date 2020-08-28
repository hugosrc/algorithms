#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Queue {
  int front, rear, size;
  unsigned capicity;
  int* array;
};

struct Queue* createQueue(unsigned capacity) {
  struct Queue* queue = malloc(sizeof(struct Queue*));
  
  queue->capicity = capacity;
  queue->front = 0;
  queue->size = 0;

  queue->rear = capacity - 1;
  queue->array = malloc(queue->capicity * sizeof(int));

  return queue;
}

int isFull(struct Queue* queue) {
  return queue->size == queue->capicity;
}

int isEmpty(struct Queue* queue) {
  return queue->size == 0;
}

void enqueue(struct Queue* queue, int item) {
  if (isFull(queue)) return;

  queue->rear = (queue->rear + 1) % queue->capicity;  
  queue->array[queue->rear] = item;
  queue->size = queue->size + 1;

  // printf("%d enqueued to queue\n");
}

int dequeue(struct Queue* queue) {
  if (isEmpty(queue)) return INT_MIN;

  int item = queue->array[queue->front];
  queue->front = (queue->front + 1) % queue->capicity;
  queue->size = queue->size - 1;

  return item;
}

int front(struct Queue* queue) {
  if (isEmpty(queue)) return INT_MIN;

  return queue->array[queue->front];
}

int rear(struct Queue* queue) {
  if (isEmpty(queue)) return INT_MIN;
  
  return queue->array[queue->rear];
}

int main(void)
{
  struct Queue* queue = createQueue(1000);

  enqueue(queue, 10);
  enqueue(queue, 20);
  enqueue(queue, 30);
  enqueue(queue, 40);
  enqueue(queue, 50);

  printf("%d dequeue from queue\n", dequeue(queue));
  printf("%d dequeue from queue\n", dequeue(queue));
  printf("%d dequeue from queue\n", dequeue(queue));

  printf("Front item is %d\n", front(queue));
  printf("Rear item is %d\n", rear(queue));

  /*  
    Output:
    10 dequeue from queue
    20 dequeue from queue
    30 dequeue from queue
    Front item is 40
    Rear item is 50
  */

  return 0;
}
