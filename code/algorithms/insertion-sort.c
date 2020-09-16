#include <stdio.h>

void insetionSort(int array[], int length) {
  int i = 0; 

  while (i < length)
  {
    int j = i;

    while (j > 0 && array[j - 1] > array[j])
    {
      int temp = array[j - 1];
      array[j - 1] = array[j];
      array[j] = temp;

      j--;
    }

    i++;
  }
  
}

void printArray(int array[], int length) {
  for (int i = 0; i < length; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n");
}

int main(void) {
  int numbers[] = {7, 5, 3, 10, 8, 6, 9, 4, 2, 1};
  int length = sizeof(numbers)/sizeof(numbers[0]);

  printf("Before sorting: ");
  printArray(numbers, length);

  insetionSort(numbers, length);

  printf("After sorting: ");
  printArray(numbers, length);

  return 0; 
}