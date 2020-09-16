#include <stdio.h>

// performs a linear search on a list
int search(int array[], int length, int target) {

  // loops through all the elements in the list
  for (int i = 0; i < length; i++) 
  {
    // if the element has a value equal to the target, returns the index
    if (array[i] == target)
    {
      return i;
    }
  }

  // if the target is not found, returns -1
  return -1;
}

int main(void) {
  int array[] = { 1, 5, 7, 6, 2, 4, 6, 84, 62, 0 };

  printf("Element 62 found in index: %d\n", search(array, 10, 62)); 
  printf("Element 5 found in index: %d\n", search(array, 10, 5)); 
  printf("Element 0 found in index: %d\n", search(array, 10, 0));
  printf("Element 100 found in index: %d\n", search(array, 10, 100));

  /*
    Output:

    Element 62 found in index: 8
    Element 5 found in index: 1
    Element 0 found in index: 9
    Element 100 found in index: -1
  */

  return 0;
}