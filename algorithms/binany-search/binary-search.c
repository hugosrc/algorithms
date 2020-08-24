#include "stdio.h"

int main(void) {
  int result = binarySearch(15);

  result == -1 
    ? printf("Element is not present in array\n") 
    : printf("Element is present at index: %d\n", result);

  return 0;
}

int binarySearch(int target) {
  int array[] = { 1, 2, 3, 4, 8, 9, 10, 15, 75, 100 };

  int arrayLength = sizeof(array) / sizeof(array[0]);

  int rightPoint = arrayLength - 1;
  int leftPoint = 0;
  int middlePosition = (leftPoint + rightPoint) / 2;
  
  while (arrayLength > middlePosition) {
    int middleElement = array[middlePosition];

    if (middleElement == target) {
      return middlePosition;
    }

    if (middleElement > target) {
      rightPoint = middlePosition - 1;
    }

    if (middleElement < target) {
      leftPoint = middlePosition + 1;
    }

    if (leftPoint > rightPoint) {
      return -1;
    }

    middlePosition = (leftPoint + rightPoint) / 2;
  }

  return -1;
}