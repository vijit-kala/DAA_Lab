/**
 * Everything is theoretically impossible until it is done.
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    freopen("sorted_inputs.txt", "r", stdin);
    freopen("output_2.txt", "w", stdout);

    int testCases;
    cin >> testCases;

    while (testCases--) {
        // Solving every tescase here.
        int n;
        cin >> n;
        vector<int> arr(n);
        for (auto &e : arr)
            cin >> e;
        int key;
        cin >> key;

        // Main logic.
        int cntComp = 0, flag = 0;
        if (arr[0] == key) {
            cout << "Present " << 1 << endl;
        } else {
            int i = 1;
            // To find interval where key lies.
            while (i < n and arr[i] <= key) {
                cntComp++;
                i *= 2;
            }

            // Binary searching between i/2 and i to find the key.
            int l = i / 2, r = i;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (arr[mid] == key) {
                    cntComp++;
                    flag = 1;
                    break;
                } else if (arr[mid] > key) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
                cntComp++;
            }

            cout << (flag ? "Present " : "Not Present ") << cntComp << endl;
        }
    }
    return 0;
}