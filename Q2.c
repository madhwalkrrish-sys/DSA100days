#include <stdio.h>

int main() {
    int n, pos;
    int arr[100];   // Maximum size assumed 100

    // Input number of elements
    scanf("%d", &n);

    // Input array elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input position (1-based)
    scanf("%d", &pos);

    // Check if position is valid
    if(pos < 1 || pos > n) {
        printf("Invalid position");
        return 0;
    }

    // Shift elements to the left
    for(int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Reduce array size
    n--;

    // Print updated array
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
