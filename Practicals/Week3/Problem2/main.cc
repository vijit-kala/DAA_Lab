/**
 * Everything is theoretically impossible until it is done.
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int shifts, comp;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n) {
    shifts = comp = 0;
    int min_index, i, j;
    for (i = 0; i < n - 1; i++) {
        min_index = i;
        for (j = i + 1; j < n; j++) {
            if (arr[min_index] > arr[j]) {
                min_index = j;
                comp++;
            }
        }
        swap(&arr[min_index], &arr[i]);
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
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        selectionSort(arr, n);
        // Printing the array.
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << "\nComparisions : " << comp << endl;
        cout << "Shifts : " << shifts << endl;
    }
    return 0;
}