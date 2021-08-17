#include <iostream>
using namespace std;

// Searching for an element in array in linear time.
void findInArr(int *arr, int size, int key) {
    int cntComp = 0;  // Storing comparisions.
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            cntComp += 1;
            cout << "Found " << key << " at index " << i << endl;
            cout << "Total comparisions:: " << cntComp << endl;
            return;
        }
        cntComp += 1;
    }
    cout << "Could not find " << key << endl;
    cout << "Total comparisions:: " << cntComp << endl;
}

int main() {
    int testCases;
    cout << "Enter testcases:: ";
    cin >> testCases;

    while (testCases--) {
        int n;
        cout << "Enter size of array:: ";
        cin >> n;
        cout << "Enter array elements:: ";
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << "Enter key to look for:: ";
        int key;
        cin >> key;
        findInArr(arr, n, key);
    }
}