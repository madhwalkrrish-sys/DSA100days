#include <stdio.h>

int main() {
    int n, k;
    int arr[100];
    int found = 0;
    int comparisons = 0;

    // Input array size
    scanf("%d", &n);

    // Input array elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input key to search
    scanf("%d", &k);

    // Linear Search
    for(int i = 0; i < n; i++) {
        comparisons++;   // Count each comparison
        
        if(arr[i] == k) {
            printf("Found at index %d\n", i);
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("Not Found\n");
    }

    printf("Comparisons = %d", comparisons);

    return 0;
}
