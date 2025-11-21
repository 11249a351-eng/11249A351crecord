✅ Aim:
To write a program that searches for a given element in an array using the Linear Search technique.
Linear Search checks each element of the array one by one until the desired element is found or the list ends.

✅ Algorithm: Linear Search
1. Start
2. Read the size of the array (n)
3. Read n elements into the array
4. Read the element to be searched (key)
5. Repeat for i = 0 to n-1
If array[i] == key
Print “Element found at position i”
Stop
6. If the loop ends without finding the key
Print “Element not found”
7. Stop

Program for Linear Search:
#include <stdio.h>
int main() {
    int arr[100], n, i, key;

    // Input size of array
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input key to search
    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Linear Search
    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Element %d found at position %d\n", key, i + 1);
            return 0;  // Exit after finding
        }
    }

    // If not found
    printf("Element %d not found in the array.\n", key);

    return 0; 
}

OUTPUT:
Enter number of elements: 5
Enter 5 elements:
10 25 30 45 50
Enter element to search: 45
Element 45 found at position 4
          RESULT:
          For the input array:10 25 30 45 50
          Searching for:45
          Linear search found the element at position 4.
