AIM:
To write a C program to sort an array using:
Quick Sort
Merge Sort
and display the sorted output.

ALGORITHM:
1. Choose a pivot
Usually the last element.
2. Partition the array
Elements smaller than pivot → left
Elements greater than pivot → right
3. Recursively apply Quick Sort
QuickSort(left side)
QuickSort(right side)
4. Divide
Split the array into two halves.
5. Conquer
Recursively sort both halves.
6. Combine
Merge the two sorted halves.

PROGRAM — Quick Sort & Merge Sort (Menu Driven):
#include <stdio.h>

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* ======================
       QUICK SORT
   ====================== */
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* ======================
       MERGE SORT
   ====================== */

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int left[n1], right[n2];

    for (int i = 0; i < n1; i++)
        left[i] = arr[l + i];

    for (int j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    while (i < n1)
        arr[k++] = left[i++];

    while (j < n2)
        arr[k++] = right[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

/* ======================
     MAIN FUNCTION  
   ====================== */
int main() {
    int arr[50], n, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\n1. Quick Sort\n2. Merge Sort\nChoose: ");
    scanf("%d", &choice);

    if (choice == 1)
        quickSort(arr, 0, n - 1);
    else if (choice == 2)
        mergeSort(arr, 0, n - 1);
    else {
        printf("Invalid Choice!\n");
        return 0;
    }

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return 0;
}

OUTPUT:
Enter number of elements: 5
Enter elements: 40 10 30 50 20
1. Quick Sort
2. Merge Sort
Choose: 1
Sorted array: 10 20 30 40 50
Using Merge Sort:
Choose: 2
Sorted array: 10 20 30 40 50

     RESULT:
     Given input:40 10 30 50 20
     Both Quick Sort and Merge Sort produce:10 20 30 40 50.
