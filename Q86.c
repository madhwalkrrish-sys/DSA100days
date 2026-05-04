#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    long long left = 0, right = n;
    long long ans = 0;

    while (left <= right) {
        long long mid = left + (right - left) / 2;

        if (mid * mid == n) {
            cout << mid;
            return 0;
        }
        else if (mid * mid < n) {
            ans = mid;        // store answer
            left = mid + 1;   // move right
        }
        else {
            right = mid - 1;  // move left
        }
    }

    cout << ans;
    return 0;
}