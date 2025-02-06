#include <bits/stdc++.h>
using namespace std;
// #define int long long
typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define Endl '\n'
const int MOD = 1e9 + 7;

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
    vector<vector<int>> adj(n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> parent(n + 1, -1);
    vector<int> dis(n + 1, 1e9);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 0});
    dis[0] = 0;
    while (!q.empty())
    {
        auto it = q.top();
        int dist = it.first;
        int node = it.second;
        q.pop();
        for (auto adjnode : adj[node])
        {
            if (1 + dist < dis[adjnode])
            {
                dis[adjnode] = 1 + dist;
                parent[adjnode] = node;
                q.push({dis[adjnode], adjnode});
            }
        }
    }
    if (dis[n - 1] == 1e9)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        vector<int> path;
        for (int at = n - 1; at != -1; at = parent[at])
        {
            path.push_back(at);
        }
        reverse(path.begin(), path.end());
        cout << path.size() << Endl;
        for (auto it : path)
            cout << it + 1 << " ";
        cout << Endl;
    }
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