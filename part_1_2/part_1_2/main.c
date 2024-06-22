//
//  main.c
//  part_1_2
//
//  Created by Tuyen Vo on 6/21/24.
//

#include <stdio.h>

/* Function to swap two elements */
void swap(int *first, int *second) {
  int temp = *first;
  *first = *second;
  *second = temp;
}

/* Partition function for quicksort */
int partition(int arr[], int low, int high) {
  int pivot = arr[high]; /* pivot element */
  int i = (low - 1); /* index of smaller element */

  for (int j = low; j <= high - 1; j++) {
    /* If current element is smaller than the pivot */
    if (arr[j] <= pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

/* Iterative quicksort function */
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[p] is now at right place
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
      }
}

/* Function to remove duplicates in-place */
int removeDuplicates(int arr[], int size) {
  if (size == 0 || size == 1) {
    return size;
  }

  int j = 0; /* index to store unique elements */

  for (int i = 1; i < size; i++) {
    if (arr[i] != arr[j]) {
      j++;
      arr[j] = arr[i]; /* in-place copy */
    }
  }

  return j + 1; /* return the new length of the array */
}

int main(void) {
  int arr[] = {-1, 2, 2, 4, 1, 0, 3, 2, 5};
  int size = sizeof(arr) / sizeof(arr[0]);

  /* Sort the array using quicksort */
  quickSort(arr, 0, size - 1);

  /* Remove duplicates and get the new length */
  size = removeDuplicates(arr, size);

  /* Print the sorted and deduplicated array */
  printf("Sorted and deduplicated array: ");
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}
