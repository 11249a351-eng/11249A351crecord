
✅ Aim

To write a program that searches for a given element in a sorted array using the Binary Search technique.
Binary search repeatedly divides the search interval into halves to quickly locate the target element.


---

✅ Algorithm: Binary Search

1. Start


2. Read the size of the array (n)


3. Read n sorted elements into the array


4. Read the element to be searched (key)


5. Initialize:

low = 0

high = n - 1



6. Repeat while low <= high

mid = (low + high) / 2

If arr[mid] == key
→ Print “Element found at position mid”
→ Stop

Else if key < arr[mid]
→ high = mid - 1

Else
→ low = mid + 1



7. If loop ends without finding the element

Print “Element not found”



8. Stop


✅ C Program for Binary Search

#include <stdio.h>

int main() {
    int arr[50], n, i, key;
    int low, high, mid;

    // Input size of array
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input sorted array elements
    printf("Enter %d sorted elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input key to search
    printf("Enter the element to search: ");
    scanf("%d", &key);

    low = 0;
    high = n - 1;

    // Binary Search
    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == key) {
            printf("Element %d found at position %d\n", key, mid + 1);
            return 0;
        }
        else if (key < arr[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    printf("Element %d not found in the array.\n", key);

    return 0;
}
