# Queue

<p align="center">
  <img src="./queue.png" width="50%"/>
</p>

A Queue is a linear structure which follows a particular order in which the operations are performed. The order is First In First Out (FIFO), so it is an important structure for storing and retrieving data and hence is used extensively among all the data structures.

### Utility

Queue is used when things don’t have to be processed immediately, but have to be processed in First In First Out order

### The following operations can be performed on Queue:

- Createqueue -> To create an empty queue</br>
- Enqueue     -> To add (insert) and element in the queue</br>
- Dequeue     -> To access and remove an element of the queue</br>
- Peek        -> To access the first element of the queue without removing it.</br>
- Isfull      -> To check whether the queue is full</br>
- Isempty     -> To check whether the queue is empty</br>

## Simple Queue

### Representation

```bash
struct Queue {
  int front, rear, size;
  unsigned capicity;
  int* array;
};
```

## References

https://www.hackerearth.com/pt-br/practice/data-structures/queues/basics-of-queues/tutorial/

https://www.geeksforgeeks.org/queue-data-structure/

https://sites.google.com/site/merasemester/data-structures/queue

https://www.freecodecamp.org/news/data-structures-101-queues-a6960a3c98/

https://www.geeksforgeeks.org/applications-of-queue-data-structure/

https://www.geeksforgeeks.org/priority-queue-set-1-introduction/

https://www.thecrazyprogrammer.com/2019/01/types-of-queues-in-data-structure.html

https://www.programiz.com/dsa/priority-queue