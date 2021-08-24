#include <bits/stdc++.h>
using namespace std;

/**
 * Given an unsorted array containing duplicate elements,
 * find element with maximum occurrences and print it
 * Complexities: Time - O(N), Space - O(N).
*/

void solve() {
    int n;
    cin >> n;
    char arr[n];
    int count[26] = {0};
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        count[arr[i] - 'a']++;
    }
    char ch;
    int count_ch = 1;
    for (int i = 0; i < 26; i++) {
        if (count[i] > count_ch) {
            ch = (char)(i + 'a');
            count_ch = count[i];
        }
    }
    if (count_ch == 1) {
        cout << "No duplicates present\n";
    } else {
        cout << ch << " " << count_ch;
    }
}

int main() {
    int testCase;
    cin >> testCase;
    while (testCase--) {
        solve();
    }
    return 0;
}