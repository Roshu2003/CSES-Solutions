#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define Endl '\n'

#define Roshan()                          \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(0);                       \
        cout.tie(0);                      \
    }

vector<int> ans;
void Solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    vector<int> count(n);
    vector<int> ans;
    while (!pq.empty())
    {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        count[u]++;
        if (u == n - 1)
        {
            ans.push_back(d);
            if (ans.size() == k)
            {
                break;
            }
        }
        if (count[u] <= k)
        {
            for (auto it : adj[u])
            {
                int v = it.first;
                int w = it.second;
                pq.push({d + w, v});
            }
        }
    }
    for (auto it : ans)
        cout << it << " ";
    cout << Endl;
}

int32_t main()
{
    Roshan();
    int t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        Solve();
    }
    return 0;
}