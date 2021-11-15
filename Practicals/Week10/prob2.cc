#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    freopen("input2.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);

    int N;
    cin >> N;

    vector<int> st(N), ft(N);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < N; i++)
        cin >> st[i];

    for (int i = 0; i < N; i++)
    {
        cin >> ft[i];
        pq.push(make_pair(ft[i], st[i]));
    }

    function<int(vector<int>, int)> getIndex = [&](vector<int> ft, int end)
    {
        int index;
        auto it = find(ft.begin(), ft.end(), end);
        if (it != ft.end())
            index = it - ft.begin();
        else
            index = -2;
        return index + 1;
    };

    int prev = 0;
    vector<int> ans;

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int end = it.first, start = it.second;
        if (end - start >= prev)
        {
            prev += start;
            ans.push_back(getIndex(ft, end));
        }
    }

    sort(ans.begin(), ans.end());

    cout << "Max number of tasks: " << ans.size() << '\n';
    cout << "Selected task numbers: ";
    for (auto &x : ans)
    {
        cout << x << ' ';
    }
    cout << '\n';
    return 0;
}