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

void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
    }
    vector<int> dist(n, 0);
    vector<int> parent(n, -1);
    int isCycle = -1;
    dist[0] = 0;
    for (int i = 0; i < n; i++)
    {
        isCycle = -1;
        for (int u = 0; u < n; u++)
        {
            for (auto it : adj[u])
            {
                int v = it.first;
                int w = it.second;
                if (dist[u] + w < dist[v])
                {
                    parent[v] = u;
                    dist[v] = dist[u] + w;
                    isCycle = v;
                }
            }
        }
    }

    if (isCycle != -1)
    {
        cout << "YES" << Endl;
        int y = isCycle;
        for (int i = 0; i < n; i++)
        {
            y = parent[y];
        }
        vector<int> path;
        for (int cur = y;; cur = parent[cur])
        {
            path.push_back(cur);
            if (cur == y && path.size() > 1)
                break;
        }
        reverse(all(path));
        for (auto it : path)
            cout << it + 1 << " ";
        cout << endl;
    }
    else
        cout << "NO" << Endl;
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
