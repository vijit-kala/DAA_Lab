/**
 * Everything is theoretically impossible until it is done.
 * Overall complexity: Time => O(N2logN) Space => O(1).
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int binarySearch(vector<int> &arr, int low, int high, int key) {
    if (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            return binarySearch(arr, low, mid - 1, key);
        else
            return binarySearch(arr, mid + 1, high, key);
    }
    return -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int testCases;
    cin >> testCases;

    while (testCases--) {
        // Solving every tescase here.
        int n;
        cin >> n;
        vector<int> arr(n);
        for (auto &e : arr)
            cin >> e;
        bool isFound = false;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                int val = arr[i] + arr[j];
                int index = binarySearch(arr, j + 1, n - 1, val);
                if (index != -1) {
                    cout << i << " , " << j << " , " << index << endl;
                    isFound = true;
                    break;
                }
            }
            if (isFound)
                break;
        }
        if (!isFound)
            cout << "No sequence found\n";
    }
    return 0;
}