#include "stdio.h"

int main() 
{
  int numbers[] = { 1, 2, 3, 4, 8, 9, 10, 15, 75, 100, 101, 157, 254 };

  int result = binarySearch(numbers, 13, 101);

  result == -1 
    ? printf("Element is not present in array\n") 
    : printf("Element is present at index: %d\n", result);

  return 0;
}

int binarySearch(int array[], int length, int target) 
{
  int rightPoint = length - 1;
  int leftPoint = 0;
  int middlePosition = (leftPoint + rightPoint) / 2;
  
  while (length > middlePosition) 
  {
    int middleElement = array[middlePosition];

    if (middleElement == target) 
    {
      return middlePosition;
    }

    if (middleElement > target) 
    {
      rightPoint = middlePosition - 1;
    }

    if (middleElement < target) 
    {
      leftPoint = middlePosition + 1;
    }

    if (leftPoint > rightPoint) 
    {
      return -1;
    }

    middlePosition = (leftPoint + rightPoint) / 2;
  }

  return -1;
}