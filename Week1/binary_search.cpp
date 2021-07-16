/**
 * Everything is theoretically impossible until it is done.
 * Author: Vijit Kala
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCases;
    cin >> testCases;

    while (testCases--) {
        // Solving every tescase here.
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int key;
        cin >> key;

        // Assuming the array is already a sorted, yet sorting the array again,
        // just to be sure. This takes overall time complexity to O(NlogN).
        sort(arr.begin(), arr.end());
        int low = 0, high = n - 1;
        int flag = 0, cntComp = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == key) {
                flag = 1;
                cntComp++;
                break;
            } else if (arr[mid] > key) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
            cntComp++;
        }

        cout << (flag ? "Present " : "Not Present ") << cntComp << endl;
    }
    return 0;
}
