#include <stdio.h>
#include <stdlib.h>

void merge(int* array, int left, int middle, int right) {
  int leftTemp = left;
  int j = middle + 1;
  int auxIndex = 0;
  int length = right - left + 1;
  int* arrayAux = malloc(length * sizeof(int));

  while (leftTemp <= middle && j <= right) {
    if (array[leftTemp] <= array[j]) {
      arrayAux[auxIndex] = array[leftTemp];
      leftTemp++;
    } else {
      arrayAux[auxIndex] = array[j];
      j++;
    }
    
    auxIndex++;
  }
  
  while (leftTemp <= middle) {
    arrayAux[auxIndex] = array[leftTemp];
    auxIndex++;
    leftTemp++;
  }

  while (j <= right) {
    arrayAux[auxIndex] = array[j];
    auxIndex++;
    j++;
  }

  for (auxIndex = left; auxIndex <= right; auxIndex++) {
    array[auxIndex] = arrayAux[auxIndex - left];
  }

  free(arrayAux);
}

void merge_sort(int* array, int left, int right) {
  if (left < right)
  {
    int middle = (left + right) / 2;

    merge_sort(array, left, middle);
    merge_sort(array, middle + 1, right);

    merge(array, left, middle, right);
  }
}

void print_array(int* array, int length) {
  printf("[");
  for (int i = 0; i < length; i++) {
    printf(" %d ", array[i]);
  }
  printf("]\n");
}

int main(void) {
  int array[9] = { 8, 2, 11, 9, 0, 55, 5, 4, 8 };
  int array_length = sizeof(array)/sizeof(array[0]);

  printf("Before: ");
  print_array(array, array_length);

  merge_sort(array, 0, array_length - 1);

  printf("After: ");
  print_array(array, array_length);

  /*
    Output:
    Before: [ 8  2  11  9  0  55  5  4  8 ]
    After:  [ 0  2  4  5  8  8  9  11  55 ]
  */

  return 0;
}