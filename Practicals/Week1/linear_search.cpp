#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int testCase;
    cin >> testCase;

    while (testCase--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int key;
        cin >> key;
        int cntCmp = 0, flag = 0;
        for (int x : arr) {
            cntCmp++;
            if (x == key) {
                flag = 1;
                break;
            }
        }
        cout << (flag ? "Present " : "Not Present ") << cntCmp << endl;
    }
    return 0;
}