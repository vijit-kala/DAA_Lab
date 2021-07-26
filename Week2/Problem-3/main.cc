/**
 * Everything is theoretically impossible until it is done.
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int binarySearch(vector<int>& arr, int low, int high, int key) {
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

void countPairWithDiffK(vector<int>& arr, int n, int k) {
    // Using inbuilt sort method.
    sort(arr.begin(), arr.end());
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (binarySearch(arr, i + 1, n - 1, (arr[i] + k)) != -1)
            count++;
    }

    cout << count;
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
        for (auto& e : arr)
            cin >> e;
        int k;
        cin >> k;

        // Approach 1: Brute Force -> Time: O(N2) Space: O(1).
        // int count = 0;
        // for (int i = 0; i < n - 1; i++) {
        //     for (int j = i + 1; j < n; j++) {
        //         if (abs(arr[i] - arr[j]) == k)
        //             count++;
        //     }
        // }
        // cout << count << endl;

        // Approach 2: Sorting + Binary Search -> Time: O(NlogN) Space: O(1).
        countPairWithDiffK(arr, n, k);
        cout << "\n";
    }
    return 0;
}