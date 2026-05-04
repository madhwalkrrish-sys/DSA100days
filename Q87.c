#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Iterative Binary Search
int binarySearch(vector<int>& arr, int key) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; // not found
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Step 1: Sort the array
    sort(arr.begin(), arr.end());

    // Print sorted array
    for (int x : arr) cout << x << " ";
    cout << endl;

    // Step 2: Input element to search
    int key;
    cin >> key;

    // Step 3: Binary Search
    int result = binarySearch(arr, key);

    if (result != -1)
        cout << "Element found at index " << result;
    else
        cout << "Element not found";

    return 0;
}