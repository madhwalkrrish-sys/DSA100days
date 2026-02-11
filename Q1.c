#include <stdio.h>
#define MAX 100

int main() {
    int arr[MAX];
    int n, pos, x;

    // Input size
    scanf("%d", &n);

    // Input array elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input position (1-based)
    scanf("%d", &pos);

    // Input element to insert
    scanf("%d", &x);

    // Check for valid position
    if(pos < 1 || pos > n + 1) {
        printf("Invalid position");
        return 0;
    }

    // Check for overflow
    if(n >= MAX) {
        printf("Array overflow");
        return 0;
    }

    // Shift elements right (DSA insertion logic)
    for(int i = n - 1; i >= pos - 1; i--) {
        arr[i + 1] = arr[i];
    }

    // Insert element
    arr[pos - 1] = x;

    n++;  // Increase size

    // Print updated array
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
