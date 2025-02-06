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
    bool notNeg = true;
    for (int i = 0; i < m; i++)
    {
        int u, v, x;
        cin >> u >> v >> x;
        u--;
        v--;
        if (x < 0)
            notNeg = false;
        adj[u].push_back({v, x});
    }
    vector<int> dist(n, LLONG_MIN);
    dist[0] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int u = 0; u < n; u++)
        {
            for (auto it : adj[u])
            {
                int v = it.first;
                int w = it.second;
                if (dist[u] != LLONG_MIN and dist[u] + w > dist[v])
                {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }

    vector<bool> reach_from_1(n, false);
    queue<int> q;
    q.push(0);
    reach_from_1[0] = true;
    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            if (!reach_from_1[it.first])
            {
                reach_from_1[it.first] = true;
                q.push(it.first);
            }
        }
    }
    vector<bool> reach_from_n(n, false);
    // queue<int> ;
    q.push(n - 1);
    reach_from_n[n - 1] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v = 0; v < n; v++)
        {
            for (auto &edge : adj[v])
            {
                if (edge.first == u && !reach_from_n[v])
                {
                    reach_from_n[v] = true;
                    q.push(v);
                }
            }
        }
    }
    bool improved = false;
    for (int u = 0; u < n; u++)
    {
        for (auto &edge : adj[u])
        {
            int v = edge.first;
            int w = edge.second;
            if (reach_from_1[u] && reach_from_n[v] && dist[u] + w > dist[v])
            {
                dist[v] = dist[u] + w;
                improved = true;
                break;
            }
        }
    }
    if (improved)
    {
        cout << -1 << Endl;
    }
    else
        cout << dist[n - 1] << Endl;
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
