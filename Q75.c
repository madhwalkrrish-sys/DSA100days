#include <stdio.h>

#define MAX 1000

int main() {
    int n;
    scanf("%d", &n);

    int arr[MAX];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = 0;
    int maxLen = 0;

    // store prefix sums and first index
    int prefixSum[MAX];
    int index[MAX];
    int size = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        // case 1: sum = 0
        if (sum == 0) {
            maxLen = i + 1;
        }

        int found = 0;

        // check if sum seen before
        for (int j = 0; j < size; j++) {
            if (prefixSum[j] == sum) {
                int len = i - index[j];
                if (len > maxLen) {
                    maxLen = len;
                }
                found = 1;
                break;
            }
        }

        // store if not found
        if (!found) {
            prefixSum[size] = sum;
            index[size] = i;
            size++;
        }
    }

    printf("%d\n", maxLen);
    return 0;
}