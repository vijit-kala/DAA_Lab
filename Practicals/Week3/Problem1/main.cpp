/**
 * Everything is theoretically impossible until it is done.
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int shifts, comp;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertionSort(int arr[], int n) {
    shifts = comp = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 and arr[j] > key) {
            shifts++, comp++;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        shifts++;
    }
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
        insertionSort(arr, n);
        printArray(arr, n);
        cout << "Comparisions : " << comp << endl;
        cout << "Shifts : " << shifts << endl;
    }
    return 0;
}