/**
 * Everything is theoretically impossible until it is done.
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

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
        int sum;
        cin >> sum;
        mergeSort(arr, 0, n - 1);

        bool flag = false;
        int left_ptr = 0, right_ptr = n - 1;
        while (left_ptr <= right_ptr) {
            int sum_ptrs = arr[left_ptr] + arr[right_ptr];
            if (sum_ptrs > sum)
                right_ptr--;
            else if (sum_ptrs < sum)
                left_ptr++;
            else {
                flag = true;
                cout << "{ " << arr[left_ptr] << " , " << arr[right_ptr] << " } ";
                left_ptr++;
                right_ptr--;
            }
        }
        if (!flag)
            cout << "No such pair exist\n";
        else
            cout << "\n";
    }
    return 0;
}