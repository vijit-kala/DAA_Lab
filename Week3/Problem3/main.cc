/**
 * Everything is theoretically impossible until it is done.
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// Using merge sort , complexities:
// Time : O(NlogN), space: O(N).

void merge(int arr[], int l, int mid, int r) {
    int i, j, k;
    int size1 = mid - l + 1;
    int size2 = r - mid;

    int left[size1], right[size2];

    for (i = 0; i < size1; i++)
        left[i] = arr[l + i];
    for (j = 0; j < size2; j++)
        right[j] = arr[mid + 1 + j];

    i = j = 0;
    k = l;

    while (i < size1 and j < size2) {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    while (i < size1)
        arr[k++] = left[i++];
    while (j < size2)
        arr[k++] = right[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l >= r)
        return;
    int mid = l + (r - l) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int testCases;
    cin >> testCases;

    while (testCases--) {
        // Solving every tescase here.
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        mergeSort(arr, 0, n - 1);
        //printArray(arr, n);
        bool found_duplicates = false;
        for (int i = 1; i < n; i++) {
            if (arr[i] == arr[i - 1]) {
                found_duplicates = true;
                break;
            }
        }
        cout << ((found_duplicates) ? "YES\n" : "NO\n");
    }
    return 0;
}