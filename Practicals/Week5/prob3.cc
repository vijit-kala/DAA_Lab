/**
 * Everything is theoretically impossible until it is done.
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n1, n2;
    cin >> n1;
    int arr1[n1];
    for (int i = 0; i < n1; i++)
        cin >> arr1[i];
    cin >> n2;
    int arr2[n2];
    for (int i = 0; i < n2; i++)
        cin >> arr2[i];

    int ptr1 = 0, ptr2 = 0;
    int ans_ptr = 0;
    int final_size = (n1 > n2) ? n1 : n2;
    int ans_arr[final_size];
    while (ptr1 < n1 and ptr2 < n2) {
        if (arr1[ptr1] == arr2[ptr2]) {
            ans_arr[ans_ptr++] = arr1[ptr1++];
            ptr2++;
        } else if (arr1[ptr1] < arr2[ptr2]) {
            ptr1++;
        } else {
            ptr2++;
        }
    }

    for (int i = 0; i < ans_ptr; i++) {
        cout << ans_arr[i] << " ";
    }
    cout << endl;
    return 0;
}