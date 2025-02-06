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
int n, m;
int ans = 0;
vector<int> vis;
vector<int> in_degree, topo_order;
void topologicalSort(int n, vector<int> adj[])
{
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (in_degree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        topo_order.push_back(u);
        for (auto v : adj[u])
        {
            if (--in_degree[v] == 0)
            {
                q.push(v);
            }
        }
    }
}
void Solve()
{
    cin >> n >> m;
    vector<int> adj[n];
    vector<int> indegree(n, 0), dp(n, 0);
    in_degree.assign(n, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        in_degree[v]++;
    }
    topologicalSort(n, adj);
    dp[0] = 1;
    for (auto u : topo_order)
    {
        for (auto v : adj[u])
        {
            dp[v] = (dp[u] + dp[v]) % MOD;
        }
    }

    cout << dp[n - 1] << Endl;
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