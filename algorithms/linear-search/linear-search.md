# Linear Search

<p align="center">
  <img src="./linear-search.png" width="50%"/>
</p>

Linear search is a method for finding an element within a list. A linear search sequentially checks each element of the list until it finds an element that matches the target value. If the algorithm reaches the end of the list, the search terminates unsuccessfully.

### Implementation of a linear search in C:

```bash
  int search(int array[], int length, int target) {

    for (int i = 0; i < length; i++) 
    {
      if (array[i] == target)
      {
        return i;
      }
    }

    return -1;
  }
```

## Big-O

### Worst-case

#### O(n) - Iterate through the entire array of n elements because the target is at the end or doesn't exist.

### Best-case

#### O(1) - Occurs when the searched element is the first element in the list.

## References

https://javacodekorner.blogspot.com/2019/03/linear-search-program-java.html

https://arthcp.wordpress.com/2015/05/31/what-is-the-best-search-algorithm/

https://www.geeksforgeeks.org/linear-search/

https://www.freecodecamp.org/news/big-o-notation-simply-explained-with-illustrations-and-video-87d5a71c0174/#:~:text=Big%20O%20notation%20tells%20you,it%20will%20take%20n%20operations.&text=Big%20O%20notation%20lets%20you%20compare%20the%20number%20of%20operations.

https://www.hackerearth.com/pt-br/practice/algorithms/searching/linear-search/tutorial/

https://en.wikipedia.org/wiki/Linear_search