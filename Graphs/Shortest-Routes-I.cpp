#include <bits/stdc++.h>
using namespace std;
#define int long long
// typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define Endl '\n'

#define Roshan()                          \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(0);                       \
        cout.tie(0);                      \
    }

void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        u--;
        v--;
        adj[u].push_back({v, wt});
    }
    // vector<int> vis(n, 0);
    vector<int> dis(n, LLONG_MAX);
    // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    set<pair<int, int>> q;
    q.insert({0, 0});
    dis[0] = 0;
    while (!q.empty())
    {
        auto it = *q.begin();
        q.erase(q.begin());
        int len = it.first;
        int node = it.second;
        for (auto adjNode : adj[node])
        {
            int it = adjNode.first;
            int toLen = adjNode.second;
            if (len + toLen < dis[it])
            {
                if (dis[it] != LLONG_MAX)
                {
                    q.erase({dis[it], it});
                }
                dis[it] = len + toLen;
                q.insert({dis[it], it});
            }
        }
    }
    for (auto it : dis)
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