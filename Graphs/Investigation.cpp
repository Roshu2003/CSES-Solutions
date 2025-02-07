#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
#define roundUp(a, b) ((a + b - 1) / b)
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define Endl '\n'
#define Roshan()                          \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(0);                       \
        cout.tie(0);                      \
    }
const int MOD = 1e9 + 7;

void Solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<int> dist(n + 1, LLONG_MAX), ways(n + 1, 0), minEdges(n + 1, LLONG_MAX), maxEdges(n + 1, 0);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[1] = 0;
    ways[1] = 1;
    minEdges[1] = 0;
    maxEdges[1] = 0;

    pq.push({0, 1});

    while (!pq.empty())
    {
        auto it = pq.top();
        int u = it.second;
        int d = it.first;
        pq.pop();

        if (d > dist[u])
            continue;

        for (auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;
            if (dist[v] > d + w)
            {
                dist[v] = d + w;
                ways[v] = ways[u];
                minEdges[v] = minEdges[u] + 1;
                maxEdges[v] = maxEdges[u] + 1;
                pq.push({dist[v], v});
            }
            else if (dist[v] == d + w)
            {
                ways[v] = (ways[v] + ways[u]) % MOD;
                minEdges[v] = min(minEdges[v], minEdges[u] + 1);
                maxEdges[v] = max(maxEdges[v], maxEdges[u] + 1);
            }
        }
    }

    cout << dist[n] << " " << ways[n] << " " << minEdges[n] << " " << maxEdges[n] << endl;
}

int32_t main()
{
    Roshan();
    int t;
    t = 1;
    while (t--)
    {
        Solve();
    }
    return 0;
}