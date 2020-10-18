# Merge Sort

<p align="center">
  <img src="../images/merge-sort.png" width="50%"/>
</p>

Merge Sort is a Divide and Conquer algorithm. It divides input array in two halves, calls itself for the two halves and then merges the two sorted halves. The merge() function is used for merging two halves.

### Steps
Step 1 − Divide the list recursively into two halves until it can no more be divided.<br/>
Step 2 − Merge the smaller lists into new list in sorted order.

### Implementation of a linear search in C:

```c
  void merge_sort(int* array, int left, int right) {
    if (left < right)
    {
      int middle = (left + right) / 2;

      merge_sort(array, left, middle);
      merge_sort(array, middle + 1, right);

      merge(array, left, middle, right);
    }
  }
```

## References

https://www.youtube.com/watch?v=JSceec-wEyw

https://www.tutorialspoint.com/data_structures_algorithms/merge_sort_algorithm.htm

https://www.geeksforgeeks.org/merge-sort/

https://en.wikipedia.org/wiki/Merge_sort

https://www.tutorialspoint.com/cprogramming/c_recursion.htm

https://www.tutorialspoint.com/cprogramming/c_memory_management.htm