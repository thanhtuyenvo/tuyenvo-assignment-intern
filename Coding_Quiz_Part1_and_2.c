#include <stdio.h>

/* Function to swap two elements */
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
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
  while (low < high) {
    /* pi is partitioning index */
    int pi = partition(arr, low, high);

    /* Recursively sort elements before and after partition */
    if (pi - low < high - pi) {
      quickSort(arr, low, pi - 1);
      low = pi + 1;
    } else {
      quickSort(arr, pi + 1, high);
      high = pi - 1;
    }
  }
}

/* Function to remove duplicates in-place */
int removeDuplicates(int arr[], int n) {
  if (n == 0 || n == 1) {
    return n;
  }

  int j = 0; /* index to store unique elements */

  for (int i = 1; i < n; i++) {
    if (arr[i] != arr[j]) {
      j++;
      arr[j] = arr[i]; /* in-place copy */
    }
  }

  return j + 1; /* return the new length of the array */
}

int main() {
  int arr[] = {-1, 2, 2, 4, 1, 0, 3, 2, 5};
  int n = sizeof(arr) / sizeof(arr[0]);

  /* Sort the array using quicksort */
  quickSort(arr, 0, n - 1);

  /* Remove duplicates and get the new length */
  n = removeDuplicates(arr, n);

  /* Print the sorted and deduplicated array */
  printf("Sorted and deduplicated array: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}
