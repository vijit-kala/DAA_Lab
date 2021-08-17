/**
 * Everything is theoretically impossible until it is done.
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int binarySearch(vector<int>& arr, int key, int flag) {
    int l = 0, h = arr.size() - 1;
    int index = -1;
    while (l <= h) {
        int mid = l + (h - l) / 2;
        if (arr[mid] == key) {
            index = mid;

            if (flag)
                h = mid - 1;
            else
                l = mid + 1;
        } else if (arr[mid] > key)
            h = mid - 1;
        else
            l = mid + 1;
    }
    return index;
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
        int key;
        cin >> key;

        // 1/0 will act as indicator for directions.
        int firstIndex = binarySearch(arr, key, 1);
        int lastIndex = binarySearch(arr, key, 0);

        if (firstIndex != -1 or lastIndex != -1) {
            cout << arr[firstIndex] << " - " << (lastIndex - firstIndex + 1) << endl;
        } else {
            cout << "Key not present\n";
        }
    }
    return 0;
}