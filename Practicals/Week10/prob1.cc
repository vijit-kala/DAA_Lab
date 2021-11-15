#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);

    int N;
    cin >> N;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> ft(N), st(N);
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
            index = -1;
        return index;
    };

    vector<int> ans;
    auto it = pq.top();
    int start = it.second, end = it.first;
    pq.pop();
    ans.push_back(getIndex(ft, end) + 1);

    while (!pq.empty())
    {
        auto itr = pq.top();
        pq.pop();

        if (itr.second >= end)
        {
            start = itr.second;
            end = itr.first;
            ans.push_back(getIndex(ft, end) + 1);
        }
    }

    cout << "No. of Non-conflicting activities: " << ans.size() << endl;
    cout << "List of selected activities: ";
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << "\n";

    return 0;
}