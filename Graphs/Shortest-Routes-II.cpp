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
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<pair<int, int>>> adj(n);
    vector<vector<int>> dis(n, vector<int>(n, LLONG_MAX));
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        u--;
        v--;
        dis[u][v] = min(dis[u][v], wt);
        dis[v][u] = min(dis[v][u], wt);
        // dis[i][i] = 0;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    for (int i = 0; i < n; i++)
        dis[i][i] = 0;

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dis[i][k] != LLONG_MAX && dis[j][k] != LLONG_MAX)
                {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[j][k]);
                }
            }
        }
    }
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        if (dis[u][v] == LLONG_MAX)
        {
            cout << -1 << Endl;
        }
        else
        {
            cout << dis[u][v] << Endl;
        }
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
