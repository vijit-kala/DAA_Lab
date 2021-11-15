#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    freopen("input3.txt", "r", stdin);
    freopen("output3.txt", "w", stdout);

    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    int mx = 0, ans = -1;
    for (int i = 0; i < N - 1; i++)
    {
        int j = i, count = 1;
        while (arr[j + 1] == arr[i])
        {
            j++;
            count++;
        }
        mx = max(mx, count);
        i = j;
    }

    (mx >= (N + 1) / 2) ? cout << "YES\n" : cout << "NO\n";
    int median = (N & 1) ? arr[N / 2] : (arr[(N - 1) / 2] + arr[(N + 1) / 2]) / 2;
    cout << "Median: " << median;
    return 0;
}