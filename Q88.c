#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Check if we can place k cows with minimum distance dist
bool canPlace(vector<int>& stalls, int k, int dist) {
    int count = 1; // first cow placed
    int last = stalls[0];

    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - last >= dist) {
            count++;
            last = stalls[i];
        }
        if (count >= k) return true;
    }
    return false;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> stalls(n);
    for (int i = 0; i < n; i++) {
        cin >> stalls[i];
    }

    // Step 1: sort positions
    sort(stalls.begin(), stalls.end());

    int left = 1;
    int right = stalls[n - 1] - stalls[0];
    int ans = 0;

    // Step 2: binary search
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canPlace(stalls, k, mid)) {
            ans = mid;        // valid → try bigger
            left = mid + 1;
        } else {
            right = mid - 1;  // too large → reduce
        }
    }

    cout << ans;
    return 0;
}